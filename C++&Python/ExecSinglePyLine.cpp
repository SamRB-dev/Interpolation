#include <python3.13/Python.h>

int main(void) {
    Py_Initialize();
    PyRun_SimpleString("print('Hello C++! From Python!')");
    Py_Finalize();
}