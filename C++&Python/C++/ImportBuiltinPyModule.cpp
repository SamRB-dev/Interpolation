#include <python3.13/Python.h>
#include <iostream>

int main(void) {
    Py_Initialize();
    PyObject *pModule, *pFunc, *pResult;
    pModule = PyImport_ImportModule("os");
    // Check if the module was successfully imported
    if (pModule) {
        std::cout << "Module Imported" << std::endl;

        // Get the "getcwd" function from the "os" module
        pFunc = PyObject_GetAttrString(pModule, "getcwd");
        std::cout << "getcwd detected" << std::endl;

        // Call the "getcwd" function with no arguments
        pResult = PyObject_CallObject(pFunc, nullptr);

        // Convert the result (Python string) to a C-style string
        const char* result = PyUnicode_AsUTF8(pResult);

        // Print the current working directory
        std::cout << result << std::endl;

        // Decrease reference counts for the module and function objects
        Py_DECREF(pModule);
        Py_DECREF(pFunc);
    } else if (!pModule) {
        // Print the Python error if the module failed to load
        PyErr_Print();
        std::cerr << "Failed to load module" << std::endl;
    }
    Py_Finalize();
    return 0;
}