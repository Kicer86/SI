from conans import ConanFile, CMake


class SiConan(ConanFile):
    name = "SI"
    version = "1.2.0"
    license = "MIT"
    author = "Dominik Berner <dominik.berner+SI-conan@gmail.com"
    url = "https://github.com/bernedom/SI"
    description = "A header only c++ library that provides type safety and user defined literals for handling pyhsical values defined in the International System of Units."
    topics = ("physical units", "SI-unit-conversion",
              "cplusplus-library", "cplusplus-17")
    exports_sources = "include/*", "CMakeLists.txt", "test/*", "cmake/SIConfig.cmake.in", "LICENSE"
    no_copy_source = True

    def _configure_cmake(self):
        cmake = CMake(self)
        # Add additional settings with cmake.definitions["SOME_DEFINITION"] = True
        cmake.configure()
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_id(self):
        self.info.header_only()
