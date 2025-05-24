#include <iostream>
#include <string>
#include <pybind11/pybind11.h>


void FuncWithoutArgs() {
    // Function without arguments
    std::cout << "Function without arguments called." << std::endl;
}

void FuncWithArgs(double a, double b) {
    // Function with arguments
    std::cout << "Function with arguments called: a = " << a << ", b = " << b << std::endl;
}

class Greeter {
public:
    Greeter(const std::string& name) : name(name) {}

    std::string greet() const {
        return "Hello, " + name + "!";
    }

private:
    std::string name;
};

PYBIND11_MODULE(Test, function) {
    function.def("FuncWithoutArgs", &FuncWithoutArgs, "A function that takes no arguments and prints a message.");

    function.def("FuncWithArgs", &FuncWithArgs, "A function that takes two arguments and prints their values.");

    pybind11::class_<Greeter>(function, "Greeter")
        .def(pybind11::init<const std::string&>())
        .def("greet", &Greeter::greet);
}