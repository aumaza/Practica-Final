#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Producto.h"
#include "DataManager.h"



int cargarDesdeArchivo(ArrayList *this,const char* nombre)
{
	int flag = 0;
	FILE *pArchivo;

    if(this !=NULL && nombre !=NULL)
    {
        pArchivo=fopen(nombre,"r");
        if(pArchivo != NULL)
        {
            flag=0;
		//pArchivo= fopen("nombre", "wb");
            if(parserProducto(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);
            }
        }
    }
        if(flag ==1)
        {
	    printf("Carga Correcta:\n");
    system("pause");
        }
        else
        {
            printf("No se pudo cargar\n");
            system("pause");
        }


	return flag;

}
eProducto* nuevo(void)
{
    eProducto* returnAux;
    returnAux = (eProducto*)malloc(sizeof(eProducto));
    return returnAux;
}
