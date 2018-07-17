#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#define TAM_DESCR 50
#include "ArrayList.h"


typedef struct
{
    int cod_prod;
    char descrip[TAM_DESCR];
    int cantidad;
}eProducto;


int parserProducto(FILE* pFile, ArrayList* this);






















#endif // PRODUCTO_H_INCLUDED
