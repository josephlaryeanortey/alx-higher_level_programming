#include <stdlib.h>
#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - function that prints some basic
 * info about Python lists
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
    Py_ssize_t size, alloc, elem;
    PyObject *item;

    size = PyList_Size(p);
    alloc = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", alloc);

    for (elem = 0; elem < size; elem++)
    {
        item = PyList_GetItem(p, elem);
        printf("Element %ld: %s\n", elem, Py_TYPE(item)->tp_name);
    }
}
