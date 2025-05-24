#include <python3.13/Python.h>
#include <iostream>  

int main() {
    FILE* fp;  // File pointer to handle the Python script file

    // Initialize the Python interpreter
    Py_Initialize();

    // Open the Python script file in read mode
    fp = fopen("SomePython.py", "r");  
    if (fp) {
        // If the file is successfully opened, execute the Python script
        PyRun_SimpleFile(fp, "SomePython.py");  

        // Close the file after execution
        fclose(fp);
    } else {
        // If the file fails to open, print an error message to the standard error stream
        std::cerr << "Failed to open script.py" << std::endl;
    }

    // Finalize the Python interpreter to clean up resources
    Py_Finalize();

    // Return 0 to indicate successful program execution
    return 0;
}