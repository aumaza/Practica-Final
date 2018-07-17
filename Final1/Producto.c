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
    char cabecera[80];
    int guardoDato;

    eProducto* record;

    //char Nombre[20];
    char Id[2];
    char descrip[25];
    char canti[2];
   // char horas[10];

    if(pFile != NULL)
    {
        retorno = -2;
        if(ENCABEZADO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo();
            if(record != NULL)
            {
                cantidadDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",Id,descrip,canti/*,sueldo,horas*/);
                if(cantidadDatosLeidos == CANTIDAD)
                {
                   guardoDato=prod_set_Id(record,charToint(Id));
                    if(guardoDato !=0)
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
               //     guardoDato = Empleado_setSueldo(record, charToFloat(sueldo) );
                //    guardoDato = Empleado_setHoras(record, charToint(horas) );
                    al_add(this, record);
                    cantidadFilasLeidas++;
                }
                else //Fin de archivo u otro error
                {
                    break;
                }
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
int prod_set_descrip(eProducto* this, char *dato)
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
