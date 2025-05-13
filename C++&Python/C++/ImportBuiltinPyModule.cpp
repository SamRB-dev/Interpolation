#include <python3.13/Python.h>
#include <iostream>
int main(void) {
    Py_Initialize();
    PyObject *pName, *pModule, *pFunc, *pResult;
    pModule = PyImport_ImportModule("os");
    if (pModule) {
        std::cout << "Module Imported" << std::endl;
        pFunc = PyObject_GetAttrString(pModule, "getcwd");
        std::cout << "getcwd detected" << std::endl;
        pResult = PyObject_CallObject(pFunc, nullptr);
        const char* result = PyUnicode_AsUTF8(pResult);
        std::cout << result << std::endl;
        Py_DECREF(pModule);
        Py_DECREF(pFunc);
    }
    Py_Finalize();
    return 0;
}