import sys
from pathlib import Path

mirage_path = Path(__file__).parent.parent.parent / "bindings" / "python" / "src" / "Mirage"
sys.path.insert(0, str(mirage_path))
print("module example is in: ", mirage_path)

import Mirage
import DemoLayer
import DemoOverlay


class DemoApp(Mirage.Application):
    def __init__(self, rProps):
        Mirage.Application.__init__(self, rProps)
        demoLayer     = DemoLayer.DemoLayer()
        demoOverlayer = DemoOverlay.DemoOverlay()
        self.PushLayer(demoLayer)
        self.PushOverlay(demoOverlayer)
        Mirage.Launch(self)

    def PushLayer(self, upLayer):
        print(type(upLayer))
        super().PushLayer(upLayer)
    
    def PushOverlay(self, upLayer):
        print("PushOverlay")
        super().PushOverlay(upLayer)
    
rProps = Mirage.ApplicationProps()
rProps.strWorkspaceDir = "data/"
rProps.strName = "DemoApp"
demoApp = DemoApp(rProps)