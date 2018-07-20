#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Producto.h"
#include "DataManager.h"
#include "Validaciones.h"
#include "Vista.h"
#define NOM_ARCH "dep0.csv"
#define NOM_ARCH2 "dep1.csv"



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
    int i,cantidad;

    if(this !=NULL && nom_archivo!=NULL)
    {
        pArch=fopen(nom_archivo,"w");
        if(pArch==NULL)
        {
            retorno=0;
        }//fin If(pArch==
            else
            {
       //     fprintf(pArch,"Producto,Descripcion,Cantidad\n");
            cantidad=this->len(this);
            for(i=0;i<cantidad;i++)
            {
               // prod=this->get(this,i);
                prod = (eProducto*)al_get(this, i);
                if(prod!=NULL)
                {
                    fprintf(pArch,"%d,%s,%d\n",prod_get_id(prod),prod_get_descripcion(prod),prod_get_cantidad(prod));
                    retorno=1;
                }//fin if(prod)
            }//fin for
        }//else (if pArch==
    }//fin if(nom_archivo)
    fclose(pArch);
    if(retorno==1)
        {
            printf("Se actualizo el archivo: %s correctamente\n",nom_archivo);
            system("pause");
        }
        else
        {
            printf("No se pudo actualizar el archivo: %s\n",nom_archivo);
            system("pause");
        }
        return retorno;
}
int data_borrarProducto(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int cod_prod,indice;
    char resp;
    eProducto* prod;

    if(this !=NULL && that !=NULL)
    {
        retorno=0;
        cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a dar de baja:\n");
        if(cod_prod >0)
        {
            indice=prod_buscarId(this,cod_prod);
            prod=al_get(this,indice);
            if(prod ==NULL)
            {
             indice=prod_buscarId(that,cod_prod);
             prod=al_get(that,indice);
             retorno=1;
            }
            if(prod ==NULL)
            {
                printf("No se encontro el producto\n");
                vista_pausar();
            }
            else if(prod !=NULL)
            {
            vista_Muestra1UnElemento(prod);
            resp=Valida_confirmacion("Confirma dar de baja este producto?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                 //prod=this->pop(this,this->indexOf(this, prod));
                 if(retorno==1)
                 {
                  prod = that->pop(that, prod);
                  free(prod);
                  that->sort(that,prod_comparaProducto,1);
                  data_actualizarArchivo(that,NOM_ARCH2);
                 }
                 else
                 {
                    prod = this->pop(that, prod);
                    free(prod);
                    this->sort(this,prod_comparaProducto,1);
                    data_actualizarArchivo(this,NOM_ARCH);
                 }
                 retorno=1;
                }
            }//fin else prod !=NULL

         }//fin if(cod_prod)

    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
}
