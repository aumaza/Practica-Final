#include <stdio.h>
#include <stdlib.h>

#include "Controlador.h"
#include "Vista.h"
#include "Validaciones.h"
#include "ArrayList.h"
#define NOM_ARCH "dep0.csv"
#define NOM_ARCH2 "dep1.csv"
#define TAMA�O 5

int main()
{
    char seguir='S';
    int opcion;
   // int retorno=0;
    ArrayList *ListaDep0;
    ArrayList *ListaDep1;
    ListaDep0=al_newArrayList();
    ListaDep1=al_newArrayList();
    if(ListaDep0 !=NULL && ListaDep1 !=NULL)
    {
        while(seguir=='S')
        {
            ShowMenu("\n1:Cargar Deposito\n2:Listar productos de deposito\n3:Mover productos a deposito\n4:Descontar productos de deposito\n5:Agregar productos a deposito\n");
            scanf("%d",&opcion);
            ValidaMenu(opcion,0,5);
            switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaDep0,NOM_ARCH);
                cargarDesdeArchivo(ListaDep1,NOM_ARCH2);
                break;
            case 2:
                ShowMenu("\n1:Listar deposito 0 1\n2:Listar productos deposito 1\n");
                opcion=Valida_PedirEntero("Seleccione el numero de deposito:\n");
                 switch (opcion)
                 {
                 case 1:
                    if(ListaDep0 !=NULL)
                    {
                        vista_MostrarElementos(ListaDep0,"Listado productos Deposito 0",0,5);
                    }
                    else
                        printf("No hay productos\n");

                    break;
                 case 2:
                    vista_MostrarElementos(ListaDep1,"Listado productos Deposito 1",0,ListaDep1->len(ListaDep1));
                    break;
                 }

                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                seguir='N';
                break;

            }//fin switch
        }//fin while
    }//fin If(cont_Inicializa)




    return 0;
}