# CMake MacOS Rosetta

Check MacOS CPU capabilities using CMake, C++, Python, Matlab.

By default, the test will show not using Rosetta even on an Apple Silicon Mac.
This is because by default the compiler uses native mode.
To force Rosetta use, build with:

```sh
cmake -DCMAKE_OSX_ARCHITECTURES=x86_64 -B build

cmake --build build

ctest --test-dir build -V
```

To get physical CPU count, especially for the number of fast "performance" cores, see [physical-cpu-count](https://github.com/scivision/physical-cpu-count) single-file C++ project.
