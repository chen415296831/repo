#include <thread>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <python2.7/Python.h>


void embed_py(const char* pathname);
int main()
{
	embed_py("example");
}


void embed_py(const char* pathname)
{
	PyObject* pmode, *pdict, *pfunc, *py_print;
	Py_Initialize();
	assert(Py_IsInitialized());
	PyRun_SimpleString("import sys");
	//PyRun_SimpleString("print sys.path");
	PyRun_SimpleString("sys.path.append(\"/root/cpython\")");
	//PyRun_SimpleString("print sys.path");

	pmode = PyImport_ImportModule(pathname);
	if(PyErr_Occurred())
	{
		PyErr_Print();
	}
	assert(pmode);
	pdict = PyModule_GetDict(pmode);
	assert(pdict);
	pfunc = PyDict_GetItemString(pdict, "show_instance");
	assert(PyCallable_Check(pfunc));
	PyObject_CallFunctionObjArgs(pfunc, NULL);


	Py_Finalize();
}

