#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Producto.h"
#include "DataManager.h"
#include "Validaciones.h"

void ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)
        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);
}
int Valida_PedirEntero(char mensaje[])
{
    int auxiliar;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);

    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}
char Valida_confirmacion(char mensaje[])
{
    char retorno='N';
    printf("%s\n",mensaje);
    scanf("%c",&retorno);
    retorno=toupper(retorno);
    system("pause");
    return retorno;
}
