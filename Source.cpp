#include <Python.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


int main()
{
	int userSelection;

	do {
		cout << "\n1: Print the list of items and how many times they were purchased" << endl;
		cout << "2: Find how many times a specific item was purchased" << endl;
		cout << "3: Display the items purchase frequency in a visual model" << endl;
		cout << "4: Exit the Program" << endl << endl;

		cout << "Please input a command:" << endl;
		cin >> userSelection;

		if (userSelection < 1 || userSelection > 4) {
			cout << "Please pick a valid command: 1, 2, 3, or 4" << endl << endl;
			continue;
		}

		// Displays all items sold from items.txt
		if (userSelection == 1) {
			cout << "Total Amount Sold for Each Item: " << endl;
			CallProcedure("determineInventory");
		}

		// Takes user item and displays how many times it was sold
		if (userSelection == 2) {
			string userItem;

			cout << "Please enter the item you would like to search: " << endl;
			cin >> userItem;
			cout << endl << userItem << " sold " << callIntFunc("determineFrequency", userItem) << " time/s" << endl;
		}
		
		// Reads data from the file made in Python to create a visual model of items sold
		if (userSelection == 3) {
			ifstream inFS;
			string item;
			int itemSales;

			CallProcedure("output");

			// Opens the file created from the output function in python
			inFS.open("frequency.dat");
			if (!inFS.is_open()) {
				cout << "Could not open file" << endl;
			}

			cout << "Item Sales visual model" << endl;

			inFS >> item;
			inFS >> itemSales;

			// Iterates until there is nothing left in the file
			while (!inFS.fail()) {
				item.append(": ");
				cout << left << setw(14) << item;

				for (int i = 0; i < itemSales; i++) {
					cout << "*";
				}

				cout << endl;

				inFS >> item;
				inFS >> itemSales;
			}

			if (!inFS.eof()) {
				cout << "Could not reach the end of file" << endl;
			}

			inFS.close();

		}

	} while (userSelection != 4);

	cout << "Program Terminated" << endl;

	return 0;
}