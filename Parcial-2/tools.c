#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleados.h"
#include "Archivo.h"


int ValidarCantCaracteres(char* cadena,int cantidad)
{
    int longi,flag;
    longi=strlen(cadena);
    flag=0;
    if(longi<=cantidad)
    {
        flag=1;
    }
    return flag;
}
void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;

  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
    {
    i++;
    }
  }

  *i = 0;
}
void tools_ShowTitulo(char titulo[])
{
    system("cls");
    printf("\n\n");
    printf("*****%s******\n\n",titulo);
}
int ComparaFrases(char* frase1,char* frase2)
 {
    char aux[20]={};
    char aux2[20]={};
    printf("Ingrese una frase\n");
    gets(frase1);
    printf("Ingrese una frase\n");
    gets(frase2);
    RemoveSpaces(frase1);
    RemoveSpaces(frase2);
    strlwr(frase1);
    strlwr(frase2);
    printf("frase1:%s",frase1);
    printf("frase1:%s",frase2);
    if(strcmp(frase1,frase2)==0)
    {
        printf("ya ingreso esa frase:");
    }
    else
        printf("Son distintas");
}
int PedirEntero(char mensaje[])
{
    int auxiliar;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}
long PedirNumLargo(char mensaje[])
{
    long auxiliar=0;
    do
    {
       printf("%s",mensaje);
       fflush(stdin);
       if(auxiliar >= 10000000 && auxiliar < 99999999)
       {
           auxiliar=1;
       }

    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
    }


char Responder(char mensaje[])
{
    char resp;
    //int flag=-1;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",&resp);
    resp=toupper(resp);
    while(resp!='S'&& resp!='N')
    {
      printf("\nDebe ingresar S(si) N(no)\n");
      scanf("%s",&resp);
      resp=toupper(resp);
    }

    return resp;
}

void ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)
        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);
}

void ShowMenu(char *opcion)
{
    system("cls");
    printf("MENU PRINCIPAL\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");
}
void Inicializar()
{
    ArrayList *ListaUrgent;
    ArrayList *ListaRegul;
    ArrayList *ListaAtendidosReg;
    ArrayList *ListaAtendidosUrg;
    ArrayList *ListaTemp;

    ListaUrgent=al_newArrayList();
    ListaRegul=al_newArrayList();
    ListaAtendidosReg=al_newArrayList();
    ListaAtendidosUrg=al_newArrayList();
    ListaTemp=al_newArrayList();

}
int ValidarNull(ArrayList *Lista1,ArrayList *List2, ArrayList *Lista2,ArrayList *Lista3, ArrayList *Lista4)
{
    int retorno=0;
    if(Lista1 !=NULL && Lista2 !=NULL && Lista3 !=NULL && Lista4!=NULL)
    {
        retorno=1;
    }
    return retorno;
}
void pedirString(char* retorno, char* mensajeIngreso)
{
   printf("%s", mensajeIngreso);
   fflush(stdin);
   gets(retorno);
}
//-----------------------------------------------------------------------------------------------//
int pedirStringValido(char* stringValido, char* mensajeIngreso, char* mensajeReingreso, int limite)
{
   int retorno = -1;
   int longitud;
   char valido = 'N';
   char* stringValidar;

   //stringValidar = eString_new(limite+5);

   if(stringValidar !=NULL && stringValido != NULL)
   {
      retorno = 0;
   }
   pedirString(stringValidar, mensajeIngreso);
   do
   {
      longitud = strlen(stringValidar);

      if(longitud > limite)
      {
         printf("\nEl texto ingresado supera el l¡mite de %d caracteres establecido.", limite);
         pedirString(stringValidar, mensajeIngreso);
      }
      else if(longitud == 0)
      {
         printf("\nEl texto ingresado no puede estar vacio. Ingrese al menos 1 caracter.");
         pedirString(stringValidar, mensajeIngreso);
      }
      else
      {
         valido = 'S';
         strncpy(stringValido, stringValidar, sizeof(char)*limite);
      }

   }
   while(valido == 'N');

   return retorno;
}
/*void pedirDescripcion(eEmpleado pelicula [], int j, int lenDescrip)
  {
      char buffer [1500];
      char aux [lenDescrip];
      int i;
       printf("Ingrese Descripcion\t");
       fflush(stdin);
       gets(buffer);
      for (i=0; i<lenDescrip; i++)
        {
            aux[i]=buffer[i];
        }
      strcpy(pelicula[j].descripcion, aux);*/

      char Valida_confirmacion(char mensaje[])

    /*char retorno='S';

    printf("%s\n",mensaje);

    scanf("%c",&retorno);

    retorno=toupper(retorno);

    //system("pause");

    return retorno;*/

 {
   char retorno;
   printf("\n%s (S/N): ", mensaje);
   fflush(stdin);
   scanf("%c", &retorno);
   do
   {
      switch(retorno)
      {
         case 'S':
         case 's':
            retorno = 'S';
            break;
         case 'N':
         case 'n':
            retorno = 'N';
            break;
         default:
            printf("\nPor favor ingrese 'S' o 'N': ");
            fflush(stdin);
            scanf("%c", &retorno);
            break;
      }
   }
   while(retorno != 'S' && retorno != 'N');
   return retorno;
}
void ingresarTexto (char texto[], int cantTexto, char pregunta[])
{
    char titulo [50];
    char auxtitulo [cantTexto-1];
    int i;

    printf("%s\t", pregunta);
    fflush(stdin);
    gets (titulo);
    for (i=0; i<cantTexto; i++)
    {
        auxtitulo[i]=titulo[i];
    }
    strcpy(texto, auxtitulo);
}
int ingresarInt (char pregunta[], int minimo,int maximo)
{
    int numero;
    printf("%s\t", pregunta);
    fflush(stdin);
    scanf("%d", &numero);
    while(numero < minimo ||  numero  > maximo) //|| isalpha(numero))
    {
        fflush(stdin);
        printf("\n%s\t",pregunta);
        scanf("%d", &numero);
    }
    return numero;
}
int tools_siguienteId(ArrayList* this, int (*pGetId)(void*))
{
    int returnAux = -1;
    eEmpleado* pElement;
    int i;

    if(this != NULL && (*pGetId) != NULL)
    {
        returnAux = 0;
        for(i=0 ; i<this->len(this) ; i++)
        {
            pElement = this->get(this, i);

            if((*pGetId)(pElement) > returnAux)
            {
                returnAux = (*pGetId)(pElement);
            }
        }
    }
    return (returnAux+1);
}
int tools_buscarId(ArrayList* this, int cod)
{
    int retorno=0;
    int i;
    eEmpleado* emp;
    if(this!=NULL && cod >0)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(emp !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            emp=this->get(this,i);
            if(get_id(emp)==cod)
            {
                retorno=i;
                break;
            }//fin if
            else if(get_id(emp)!=cod)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(emp)
        }
    }//fin if(this!)
    return retorno;
}

