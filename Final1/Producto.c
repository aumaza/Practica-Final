#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Producto.h"
#include "DataManager.h"
#define ENCABEZADO 0
#define CANTIDAD 3


int parserProducto(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    char cabecera[50];
    int guardoDato;

    eProducto* record;
    char Id[3];
    char descrip[25];
    char canti[3];

    if(pFile != NULL)
    {
        retorno = -2;

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo();
            if(record != NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^\n]\n",Id,descrip,canti);

                    if(prod_set_Id(record,charToint(Id)))
                    {
                        break;
                    }
                    guardoDato = prod_set_descrip(record,descrip);
                    if(guardoDato !=0)
                    {
                        break;
                    }
                    guardoDato = prod_set_cantidad(record,charToint(canti));
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    al_add(this, record);
                    cantidadFilasLeidas++;
                }

 else //Sin memoria
            {
                break;
            }
        }
    }
    return retorno;
}





//*************Defino los setters y getters

int prod_get_id(eProducto* this)
{
    return this->cod_prod;
}
char* prod_get_descripcion(eProducto* this)
{
    return this->descrip;
}
int prod_get_cantidad(eProducto* this)
{
    return this->cantidad;
}
int prod_set_Id(eProducto* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->cod_prod = dato;
    }
    return 0;
}
int prod_set_descrip(eProducto* this, char* dato)
{
    strcpy(this->descrip,dato);
    return 0;
}
int prod_set_cantidad(eProducto* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->cantidad = dato;
    }
    return 0;
}
int charToint(char* charInt)
{
    int nro;
    nro = atoi(charInt);
    return nro;
}
int prod_buscarId(ArrayList* this, int cod)
{
    int retorno=0;
    int i;
    eProducto* prod;
    if(this!=NULL && cod >0)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
        prod=this->get(this,i);
        if(prod !=NULL)
        {
            for(i=0;i<this->len(this);i++)
            {
            if(prod_get_id(prod)==cod)
            {
                retorno=i;
                break;
            }//fin if
            }//fin for
        }//fin if(prod)
        }
    }//fin if(this!)
    return retorno;
}
int prod_mover(ArrayList* this,ArrayList* that,int id)//,char* NOM_ARCH,char* NOM_ARCH2)
{
    int retorno=-1;
    eProducto* prod=NULL;

    if(this!=NULL && that!=NULL && id>0)
    {
        retorno=0;
       prod = this->pop(this, this->indexOf(this, prod));
     //   prod = this->pop(this, id));
        that->add(that,prod);
    }


}
