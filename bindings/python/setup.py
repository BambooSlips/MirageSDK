import platform
import shutil
from setuptools import setup, find_packages
from setuptools.command.sdist import sdist
from setuptools.dist import Distribution
from pathlib import Path

class PlatformWheel(Distribution):
    def is_pure(self):
        return False
    def has_ext_modules(self):
        return True

class CustomCommand(sdist):
    def run(self):
        system  = platform.system().lower()
        machine = platform.machine().lower()

        platform_map = {
                'linux': {
                    'x86_64': 'linux_x86_64',
                    'amd64': 'linux_x86_64'
                },
                'windows': {
                    'x86_64': 'win_x86_64',
                    'amd64': 'win_amd64'
                },
                # TODO: Add support for MacOS
        }

        lib_dir = platform_map.get(system, {}).get(machine)
        if lib_dir:
            print("current path is ", Path(__file__))
            pack_path = Path(__file__).parent
            mirage_py  = f"_mirage_py.{'pyd' if system == 'windows' else 'so'}"
            libmirage  = f"libmirage.{'dll' if system == 'windows' else 'so'}"
            libmirage_path  = f"{pack_path}/src/Mirage/lib/{lib_dir}/{libmirage}"
            mirage_py_path  = f"{pack_path}/src/Mirage/lib/{lib_dir}/{mirage_py}"

            print("copying from ", mirage_py_path)
            shutil.copy(mirage_py_path, f"{pack_path}/src/Mirage/_mirage_py.{'pyd' if system == 'windows' else 'so'}")
            print("copying from ", libmirage_path)
            shutil.copy(libmirage_path, f"{pack_path}/src/Mirage/libmirage.{'pyd' if system == 'windows' else 'so'}")
        
        super().run()


setup(
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    package_data={"": ["*.so", "*.dll", "*.pyd"]},
    include_package_data=True,
    distclass=PlatformWheel,
    classifiers=[
        "Operating System :: Microsoft :: Windows",
        "Operating System :: POSIX :: Linux",
        "Operating System :: MacOS :: MacOS X",
    ],
    cmdclass={
        'sdist': CustomCommand,
    },
)