import sys
from pathlib import Path

mirage_path = Path(__file__).parent.parent.parent / "bindings" / "python" / "src" / "Mirage"
sys.path.insert(0, str(mirage_path))
print("module example is in: ", mirage_path)

import Mirage

class DemoLayer(Mirage.BaseLayer):
    def __init__(self):
        super().__init__()
        self.__observer      = Mirage.Observer()
        self.__model         = Mirage.Model()
        self.__animatedModel = Mirage.Model()
        self.__title         = Mirage.Text()
        self.__flower        = Mirage.Image()
        self.__cursorPoint   = Mirage.CreateInputPoint(0, 0)
        self.__InitObserver()
        # self.__CreateModel()
        self.__CreateAnimatedModel()
        self.__CreateText()
        self.__CreateImg()
    
    def OnAttach(self):
        print("OnAttach IN")
        animationClip = "animation/ShibaInu.pb"
        animation : Mirage.Animation = self.__animatedModel.AddAnimation()
        animation.LoadClipFromFile(animationClip, "ShibaInu")
        animation.SetDuration("ShibaInu", 5000)
        animation.Play("ShibaInu")

        print("OnAttach OUT")

    def OnDetach(self):
        print("OnDetach")

    def OnEvent(self, refEvent):
        print("OnEvent")

    def OnUpdate(self):
        cursorPoint  = Mirage.CreateInputPoint(0, 0)
        scrollOffset = Mirage.CreateScrollOffset(0, 0)
        if (Mirage.IsMouseButtonPressed(Mirage.ButtonLeft) and 
            Mirage.IsKeyPressed(Mirage.LeftAlt)) :
            Mirage.GetCursorPoint(cursorPoint)
            degree = self.__cursorPoint.x - cursorPoint.x
            if 0 != degree :
                rotAxis = Mirage.vec3_float(0, 1, 0)
                self.__observer.Rotate(rotAxis, degree)

        Mirage.GetCursorPoint(self.__cursorPoint)
        Mirage.GetSrollOffset(scrollOffset)

        scale    = (10 - scrollOffset.y) / 10.0
        x        = self.__observer.GetPosition().x * scale
        y        = self.__observer.GetPosition().y * scale
        z        = self.__observer.GetPosition().z * scale
        position = Mirage.vec3_float(x, y, z)

        self.__observer.SetPosition(position)
        self.__observer.ClearView()
        # self.__model.Refresh() 
        self.__animatedModel.Refresh()
        self.__title.Refresh()
        self.__flower.Refresh()

    def __InitObserver(self):
        position = Mirage.vec3_float(0, 0, -5)
        focus    = Mirage.vec3_float(0, 0, 0)
        top      = Mirage.vec3_float(0, 1, 0)
        audioVel = Mirage.vec3_float(0, 0, 0)
        warAudio = "audio/war_bgm.wav"

        self.__observer.SetDepth(0)
        self.__observer.SetCullingMask(0x01)
        self.__observer.SetProjection(60.0, 800.0 / 600, 1.0, 1000.0)
        self.__observer.SetView(focus, top)
        self.__observer.SetPosition(position)

        Mirage.AudioListener.GetInstance().SetPosition(position)
        Mirage.AudioListener.GetInstance().SetFocusVector(focus)
        Mirage.AudioListener.GetInstance().SetTopVector(focus)

        audioBuffer = Mirage.AudioUtils.LoadAudioBuffer(warAudio)
        audioSource : Mirage.AudioSource = self.__model.AddAudioSource()
        audioSource.SetBuffer(audioBuffer)
        audioSource.SetAudioPitch(1.0)
        audioSource.SetAudioGain(1.0)
        audioSource.SetPosition(position)
        audioSource.SetVelocity(audioVel);
        audioSource.SetLoopingStatus(True)
        # audioSource.PlayAudio()
    
    def __CreateModel(self):
        layer    = 0x01
        position = Mirage.vec3_float(0, 0, 0)
        material = "material/moon.mat"
        mesh     = "model/Sphere.mesh"

        self.__model.Configure(layer, material, mesh)
        self.__model.SetPosition(position)
        self.__model.SetCullFaceStatus(True)

        def MoveLeft():
            pos = self.__model.GetPosition() 
            pos.x += 0.5
            self.__model.SetPosition(pos)

        def MoveRight():
            pos = self.__model.GetPosition() 
            pos.x -= 0.5
            self.__model.SetPosition(pos)
        
        def MoveUp():
            pos = self.__model.GetPosition()
            pos.y += 0.5
            self.__model.SetPosition(pos)
        
        def MoveDown():
            pos = self.__model.GetPosition()
            pos.y -= 0.5
            self.__model.SetPosition(pos)
        
        def Rotate():
            rotation = self.__model.GetRotation()
            rotation.y += 1
            self.__model.SetRotation(rotation)

        def PlayMusic():
            audioSource : Mirage.AudioSource = self.__model.GetAudioSource()
            if audioSource.IsPlaying():
                audioSource.PausePlaying()
            else:
                audioSource.PlayAudio()
        
        def StopMusic():
            audioSource : Mirage.AudioSource = self.__model.GetAudioSource()
            audioSource.StopPlaying()

        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.Left), MoveLeft)
        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.Right), MoveRight)
        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.Up), MoveUp)
        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.Down), MoveDown)
        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.R), Rotate)
        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.P), PlayMusic)
        self.__model.AddEvent(lambda : Mirage.IsKeyPressed(Mirage.S), StopMusic)
    
    def __CreateAnimatedModel(self):
        layer = 0x01
        position = Mirage.vec3_float(0, -1, 0)
        material = "material/ShibaInu.mat"
        mesh = "model/ShibaInu.mesh"
        rotation = Mirage.vec3_float(0, 180, 0)
        scale = Mirage.vec3_float(0.02, 0.02, 0.02)

        self.__animatedModel.Configure(layer, material, mesh, False)
        self.__animatedModel.SetPosition(position)
        self.__animatedModel.SetScale(scale)
        self.__animatedModel.SetRotation(rotation)
    
    def __CreateText(self):
        layer    = 0x01
        fontPath = "font/OldEnglish/OLDENGL.TTF"
        text     = "May ot be an evening star shines down upon you"
        scale    = Mirage.vec3_float(0.005, 0.005, 0.0)
        position = Mirage.vec3_float(-3.5, 2.0, 0.0)
        color    = Mirage.vec4_float(255.0, 255.0, 255.0, 1.0)

        self.__title.SetFontSize(72)
        self.__title.Configure(layer, fontPath, text, 0)
        self.__title.SetScale(scale)
        self.__title.SetPosition(position, False)
        self.__title.SetColor(color)
    
    def __CreateImg(self):
        height        = 100
        width         = 100
        material      = "material/flower.mat"
        mask_material = "material/circle_mask.mat"
        layer         = 0x01
        scale         = Mirage.vec3_float(0.01, 0.01, 0.01)
        position      = Mirage.vec3_float(-0.5, -2.5, 0.0)

        self.__flower.Configure(width, height, layer, material)
        self.__flower.AddMask(mask_material)
        self.__flower.SetScale(scale)
        self.__flower.SetPosition(position)
        self.__flower.AddEvent(
            lambda : Mirage.IsKeyPressed(Mirage.M), 
            lambda : self.__flower.SetMaskStatus(not self.__flower.IsMaskEnabled())
        )