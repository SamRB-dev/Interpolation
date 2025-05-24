# Python Extension in C++

## Compilation

```shell
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) Test.cpp -o Test$(python3-config --extension-suffix)
```