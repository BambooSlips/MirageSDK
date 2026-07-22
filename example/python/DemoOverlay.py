import sys
from pathlib import Path

mirage_path = Path(__file__).parent.parent.parent / "bindings" / "python" / "src" / "Mirage"
sys.path.insert(0, str(mirage_path))
print("module example is in: ", mirage_path)

import Mirage

class DemoOverlay(Mirage.BaseLayer):
    def __init__(self):
        super().__init__()
        self.__observer = Mirage.Observer()
        self.__image    = Mirage.Image()
        self.__text     = Mirage.Text()
        self.__button   = Mirage.Button()
        self.__InitObserver()
        self.__CreateUIImg()
        self.__CreateUIText()
        self.__CreateUIButton()
    
    def OnAttach(self):
        print("OnAttach")
    
    def OnDetach(self):
        print("OnDetach")
    
    def OnUpdate(self):
        self.__observer.ClearView()
        self.__image.Refresh()
        self.__text.Refresh()
        self.__button.Refresh()
    
    def OnEvent(self, refEvent):
        print("OnEvent")
    
    def __InitObserver(self):
        position = Mirage.vec3_float(0, 0, -1)
        focusVec = Mirage.vec3_float(0, 0, 0)
        topVec   = Mirage.vec3_float(0, 1, 0)
        self.__observer.SetDepth(1)
        self.__observer.SetCullingMask(0x02)
        self.__observer.SetClearFlag(Mirage.MRG_DEPTH_BUFFER_BIT)
        self.__observer.EnableOrthoView(-400, 400, 300, -300, 0.01, 100)
        self.__observer.SetPosition(position)
        self.__observer.SetView(focusVec, topVec)
    
    def __CreateUIText(self):
        layer      = 0x02
        fontPath   = "font/OldEnglish/OLDENGL.TTF"
        text       = "UI Text"
        viewWidth  = 800
        viewHeight = 600

        self.__text.SetFontSize(60)
        self.__text.Configure(layer, fontPath, text, Mirage.left)

        x = self.__text.GetPitch() / 2
        y = viewHeight / 2.0

        position = Mirage.vec3_float(x, y , 0)
        color    = Mirage.vec4_float(255, 215, 0, 1)
        self.__text.SetPosition(position, True)
        self.__text.SetColor(color)
    
    def __CreateUIImg(self):
        height        = 100
        width         = 100
        material      = "material/flower.mat"
        mask_material = "material/circle_mask.mat"
        layer         = 0x02
        viewWidth     = 800
        viewHeight    = 600
        scale         = Mirage.vec3_float(1.0, 1.0, 1.0)
        x             = viewWidth - width / 2
        y             = viewHeight / 2
        position      = Mirage.vec3_float(x, y, 0.0)

        self.__image.Configure(width, height, layer, material)
        self.__image.AddMask(mask_material)
        self.__image.SetScale(scale)
        self.__image.SetPosition(position, True)
    
    def __CreateUIButton(self):
        width      = 40
        height     = 30
        layer      = 0x02
        viewWidth  = 800
        viewHeight = 600
        x          = viewWidth - width / 2
        y          = viewHeight / 2 - 100
        scale      = Mirage.vec3_float(1.0, 1.0, 1.0)
        position   = Mirage.vec3_float(x, y, 0.0)

        self.__button.Configure(width, height, layer)
        self.__button.SetScale(scale)
        self.__button.SetPosition(position, True)
        self.__button.SetClickCallback(
            lambda : self.__image.SetMaskStatus(not self.__image.IsMaskEnabled())
        )