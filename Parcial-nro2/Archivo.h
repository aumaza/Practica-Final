#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Empleados.h"

int GuardarArchivoT(ArrayList* this, char nombrearchivo[]);
int ComparaEntero(void* eEmpleadoA,void* eEmpleadoB);
eEmpleado *BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor);





#endif // ARCHIVO_H_INCLUDED
