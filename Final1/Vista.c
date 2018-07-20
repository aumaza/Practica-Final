#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Controlador.h"
#include "DataManager.h"
#include "Producto.h"
#include "Validaciones.h"



void ShowMenu(char *opcion)
{
    system("cls");
    printf("MENU PRINCIPAL\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");
}
void vista_ShowTitulo(char titulo[])
{
    printf("%s----\n\n",titulo);
}
void vista_pausar()
{
    system("pause");
}
int vista_Muestra1UnElemento(eProducto * emp)
{
    int retorno=-1;
    if(emp !=NULL)
    {
        retorno=0;
        printf("%02d\t\t%10s\t\t%2d\n",prod_get_id(emp),/*emp->descrip*/prod_get_descripcion(emp),prod_get_cantidad(emp));
       // printf("%d\t%s\t%d\n",prod_get_id(emp),/*emp->descrip*/prod_get_descripcion(emp),prod_get_cantidad(emp));

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
        printf("\n\n--------%s--------\n\n",Titulo);
        printf("\nCod Producto\tDescripcion\tCantidad\n\n");

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
int vista_Pedir_Deposito(int choice)
{
    int retorno=0;
    system("cls");
    vista_ShowTitulo("\n\t\tMOVER PRODUCTOS ENTRE DEPOSITOS\n");
    choice:Valida_PedirEntero("Ingrese el Nro de deposito origen (0/1):\n");//se puede pasar por parametro del main??
    if(choice ==0 || choice==1)
    {
        retorno=choice;
    }
    else
    {
        printf("Debe ingresar una opcion valida (0/1)");
    }
    return retorno;
}
