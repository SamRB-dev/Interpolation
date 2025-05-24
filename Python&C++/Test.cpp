#include <iostream>
#include <pybind11/pybind11.h>


void FuncWithoutArgs() {
    // Function without arguments
    std::cout << "Function without arguments called." << std::endl;
}

PYBIND11_MODULE(Test, function) {
    function.def("FuncWithoutArgs", &FuncWithoutArgs, "A function that takes no arguments and prints a message.");
}