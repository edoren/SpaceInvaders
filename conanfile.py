from conans import ConanFile, CMake


class TelegramCPPConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = ["sfml/2.5.1@bincrafters/stable"]
    generators = "cmake"
    build_policy = "missing"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")  # From bin to bin
        self.copy("*.dylib*", dst="bin", src="lib")  # From lib to bin

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
