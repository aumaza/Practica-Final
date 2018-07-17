#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Controlador.h"
#include "DataManager.h"
#include "Producto.h"



void ShowMenu(char *opcion)
{
    system("cls");
    printf("MENU PRINCIPAL\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");
}

int vista_Muestra1UnElemento(eProducto * emp)
{
    int retorno=-1;
    if(emp !=NULL)
    {
        retorno=0;
        printf("%d\t%s\t%d\n",prod_get_id(emp),prod_get_descripcion(emp),prod_get_cantidad(emp));

    }
    return retorno;
}
void vista_MostrarElementos(ArrayList *this,char *Titulo,int desde, int hasta)
{
    int i;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------%s  --------\n",Titulo);
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                vista_Muestra1UnElemento(al_get(this,i));
            }//fin for i
        }
      //  system("\npause");
        else
        {
            printf("Lista vacia\n");
            system("pause");
        }
    }
}
