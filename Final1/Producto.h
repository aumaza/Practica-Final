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
int prod_get_id(eProducto* this);
char* prod_get_descripcion(eProducto* this);
int prod_get_cantidad(eProducto* this);
int prod_buscarId(ArrayList* this, int cod);
int prod_mover(ArrayList* this,ArrayList* that,int id);//,char* NOM_ARCH,char* NOM_ARCH2);






















#endif // PRODUCTO_H_INCLUDED
