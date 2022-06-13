# CMake MacOS Rosetta

Check MacOS CPU capabilities using CMake, C++, Python, ...

By default, the test will show not using Rosetta even on an Apple Silicon Mac.
This is because by default the compiler uses native mode.
To force Rosetta use, build with:

```sh
cmake -DCMAKE_OSX_ARCHITECTURES=x86_64 -B build

cmake --build build

ctest --test-dir build -V
```
