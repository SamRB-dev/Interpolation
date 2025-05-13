#include <python3.13/Python.h> // Include the Python C API header file for embedding Python in C++.

int main(void) {
    Py_Initialize(); // Initialize the Python interpreter.
    
    // Execute a single line of Python code to print a message.
    PyRun_SimpleString("print('Hello C++! From Python!')");
    
    Py_Finalize(); // Finalize the Python interpreter and clean up resources.
}