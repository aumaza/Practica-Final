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
int data_actualizarArchivo(ArrayList* this,char* nom_archivo)
{
    int retorno=-1;
    FILE* pArch;
    eProducto* prod=NULL;
    int i;
    if(nom_archivo!=NULL)
    {
        pArch=fopen(nom_archivo,"w");
        if(pArch!=NULL)
        {
            retorno=0;
       //     fprintf(pArch,"Producto,Descripcion,Cantidad\n");
            for(i=0;i<this->len(this);i++)
            {
                prod=this->get(this,i);
                if(prod!=NULL)
                {
                    fprintf(pArch,"%d,%s,%d\n",prod_get_id(prod),prod_get_descripcion(prod),prod_get_cantidad(prod));
                }//fin if(prod)
                else
                {
                    retorno=-2;
                }
            }//fin for
        }//if(pArch)

    }//fin if(nom_archivo)
    fclose(pArch);

}
