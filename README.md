# C++ project template with Google Tests and CI/CD

This is a project template. Feel free to use & fork it. It contains all pre-configured 
CMakeLists.txt, so to use it, just replace project name with your in 
[main CmakeLists.txt](CMakeLists.txt), and all target and executable names in 
[CI/CD script](./.github/workflows/ci_tests.yml). Sample program prints a greeting for the first argument.

## How to build and run

Run following commands from project directory.

1. Create CMake cache

```shell
cmake -S . -B cmake-build
```

2. Build main target

```shell
cmake --build cmake-build --target cpp_tests
```

3. Build tests target

```shell
cmake --build cmake-build --target cpp_tests_tests
```

4. Run main target

* On Windows:

```shell
.\cmake-build\cpp_tests.exe World
```

* On *nix:

```shell
./cmake-build/bin/cpp_tests World
```

5. Run tests

* On Windows:

```shell
.\cmake-build\cpp_tests_tests.exe
```

* On *nix:

```shell
./cmake-build/tests/cpp_tests_tests
```
