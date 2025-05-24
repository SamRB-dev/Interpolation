#include <iostream>
#include <python3.13/Python.h>
#include <pybind11/pybind11.h>


void FuncWithoutArgs() {
    // Function without arguments
    std::cout << "Function without arguments called." << std::endl;
}

PYBIND11_MODULE(test, function) {
    function.def("FuncWithoutArgs", &FuncWithoutArgs, "A function that takes no arguments and prints a message.");
}