#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tools.h"
#include "Empleados.h"



eEmpleado* nuevo(void)
{
    eEmpleado* returnAux;
    returnAux = (eEmpleado*)malloc(sizeof(eEmpleado));
    return returnAux;
}
eEmpleado* archivo_nuevoEmp(int id,char nombre[], char descripcion[],int cantidad)
{
    eEmpleado* retorno = NULL;
    eEmpleado* pEmpleado = malloc(sizeof(eEmpleado));

    if(pEmpleado != NULL)
    {
        Empleado_setId(pEmpleado,id);
        Empleado_setName(pEmpleado,nombre);
        Empleado_setDire(pEmpleado,descripcion);
        Empleado_setHoras(pEmpleado,cantidad);
        retorno = pEmpleado;
    }
    return retorno;
}

int charToint(char* charInt)
{
    int nro;
    nro = atoi(charInt);
    return nro;
}
float charToFloat(char* charFlt)
{
    float num;
    num=atof(charFlt);
    return num;
}
int get_id(eEmpleado* this)
{
    return this->id;
}

char* get_Nombre(eEmpleado* this)
{
    return this->nombre;
}

char* get_dire(eEmpleado* this)
{
    return this->direccion;
}

int get_horas(eEmpleado* this)
{
    return this->horas;
}

int get_sueldo(eEmpleado* this)
{
    return this->sueldo;
}
//***********************************************************************************
eEmpleado* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eEmpleado *emp;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))==1)
                    {
                       emp=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        emp=aux;
                    }

                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        emp=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 emp=aux;
                }
                returnAux=0;
                }//fin if
            }//fin 1er for
          //  } //fin 2do for
        }//fin 1er for
    }

    return emp;
}

//-----------------------------------
int Empleado_setId(eEmpleado* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->id = dato;
    }

    return 0;
}
int Empleado_setSueldo(eEmpleado* this,int dato)
{
    if(this!=NULL && dato!=NULL)
    {
        this->sueldo=dato;
    }
    return 0;
}
int Empleado_setHoras(eEmpleado* this,int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->horas=dato;
    }
    return 0;
}

int Empleado_setDire(eEmpleado* this,  char *dato)
{
    strcpy(this->direccion,dato);
    return 0;
}

int Empleado_setName(eEmpleado* this, const char* name)
{
    strcpy(this->nombre, name);
    return 0;
}
//-----------------------------------------------------
/*
int get_id(eEmpleado * emp)
{
    int retorno;
    if(emp !=NULL)
    {
      retorno =emp->id;
    }

    return retorno;
}
char *get_Nombre(eEmpleado * emp)
{
    char retorno;
    if(emp !=NULL)
    {
        retorno=emp->nombre;
    }
    return retorno;
}
char *get_dire(eEmpleado * emp)
{
    char retorno;
    if(emp !=NULL)
    {
        retorno=emp->direccion;
    }
    return retorno;
}
int get_horas(eEmpleado *emp)
{
    int retorno;
    if(emp !=NULL)
    {
        retorno=emp->horas;
    }
    return retorno;
}

int get_sueldo(eEmpleado *emp)
{
    int retorno;
    if(emp !=NULL)
    {
        retorno=emp->sueldo;
    }
    return retorno;
}*/

int GuardarArchivoT(ArrayList* this, const char* nombre)
{
        int retorno=-1;
        int i;
        int tamanio=0;
        if(this!=NULL)
        {
            eEmpleado* emp;
            FILE *f;
            f=fopen(nombre, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                if(emp !=NULL)
                {
                    tamanio=al_len(this);
                    for (i=0; i<tamanio; i++)
                    {
                    emp = (eEmpleado*)al_get(this, i);
                    fprintf(f,"%d,%s,%s,%d,%f\n",get_id(emp),get_Nombre(emp),get_dire(emp),get_horas(emp),get_sueldo(emp));
                   // fprintf(f,"%d,%s,%s,%d,%d\n",emp->id,emp->nombre,emp->direccion,emp->horas,emp->sueldo);
                    retorno=1;
                    }//fin for
                    }//fin if(aux!=NULL)
                fclose(f);
            }//fin else
        }// fin if(!=null)
        if(retorno==1)
        {
            printf("Se creo el archivo sueldo.csv correctamente\n");
            system("pause");
        }
        else
        {
            printf("No se pudo crear el archivo sueldo.csv\n");
            system("pause");
        }

        return retorno;

}
int GuardarArchivoB(ArrayList* this,char nombrearchivo[])
{
    int retorno=-1;
    int i;

    if(this!=NULL)
    {
        eEmpleado* aux;
        FILE *f;

        f=fopen(nombrearchivo, "wb");
        if(f==NULL)
        {
            retorno=0;
        }
        else
        {
            int tamanio;
            tamanio=al_len(this);
            for (i=0; i<tamanio; i++)
            {
                aux = (eEmpleado*)al_get(this, i);
                fwrite(aux,sizeof(eEmpleado),1,f);
                retorno=1;
            }
            fclose(f);
        }
    }
    return retorno;
}

int ComparaEntero(void* eEmpleadoA,void* eEmpleadoB)
{
    eEmpleado *retorno;
   // if (((eEmpleado*)eEmpleadoA)->sueldo >((eEmpleado*)eEmpleadoB)->sueldo)
    if(get_sueldo(eEmpleadoA)> get_sueldo(eEmpleadoB))
    {
      retorno=eEmpleadoA;
    }
  //      if (((eEmpleado*)eEmpleadoA)->sueldo <((eEmpleado*)eEmpleadoB)->sueldo)
  //  {
     // retorno=eEmpleadoB;

  //  }
    return retorno;

}
int data_actualizarArchivo(ArrayList* this,char* nom_archivo)
{
    int retorno=-1;
    FILE* pArch;
    eEmpleado* emp=NULL;
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
       //     fprintf(pArch,"empucto,Descripcion,Cantidad\n");
            cantidad=this->len(this);
            for(i=0;i<cantidad;i++)
            {
               // emp=this->get(this,i);
                emp = (eEmpleado*)al_get(this, i);
                if(emp!=NULL)
                {
                    fprintf(pArch,"%d,%s,%d\n","%d,%s,%s,%d,%f\n",get_id(emp),get_Nombre(emp),get_dire(emp),get_horas(emp),get_sueldo(emp));
                    retorno=1;
                }//fin if(emp)
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

int arch_borrarPorNombre(ArrayList* this)
{
    int retorno=-1;
    int cod_emp,indice;
    char resp;
    char nom[20];
    eEmpleado* emp;

    if(this !=NULL)
    {
        retorno=0;
        printf("Ingrese el nombre del empleado\n");
        gets(nom);
     //   nom=RemoveSpaces(nom);
        if(nom !=NULL)
        {
           // indice=emp_buscarId(this,cod_emp);
            indice=emp_buscarNombre(this,nom);
            emp=al_get(this,indice);
            if(emp ==NULL)
            {
             printf("No se encontro el empleado:\n");
             system("pause");
             retorno=-1;
            }
            else if(emp !=NULL)
            {
            Muestra1UnElemento(emp);
            resp=Valida_confirmacion("Confirma dar de baja este empleado?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                  emp = this->pop(this, emp);
                  free(emp);
                  this->sort(this,ComparaNombre,1);
                 // data_actualizarArchivo(that,NOM_ARCH2);
                }
            }//fin else emp !=NULL

         }//fin if(cod_emp)

    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
}
int arch_borrar(ArrayList* this)
{
    int retorno=-1;
    int id,indice;
    char resp;
    eEmpleado* emp;
    if(this!=NULL)
    {
        retorno=0;
        MostrarElementosId(this,"Lista de Empleados",0,this->len(this));
        id=ingresarInt("Ingrese el id:",1,50);
        indice=tools_buscarId(this,id);
        emp=this->get(this,indice);

        if(emp ==NULL)
        {
            printf("No se encontro el empleado");
            retorno=-1;
        }
        else if(emp !=NULL)
        {
            tools_ShowTitulo("BAJA DE EMPLEADOS");
            Muestra1UnElemento(emp);
            resp=Responder("Confirma dar de baja este empleado?");
            if(resp=='N');
            {
                printf("Operacion cancelada");
            }
            if(resp=='S')
            {
                retorno=1;
                if(al_remove(this,indice)==0);
                retorno=1;
            }
        }//fin else if(emp)
        if(retorno==1)
        {
            printf("Se dio de baja el empleado");
            system("pause");
        }
    }
    return retorno;
}
int arch_Alta_Empleado(ArrayList* this)
{
    int retorno=-1;
    int i,id;
    char resp;
    if(this !=NULL)
    {
        eEmpleado* emp;
        eEmpleado aux;
        retorno=0;
        do
        {
            tools_ShowTitulo("INGRESO EMPLEADOS");
            aux.id=tools_siguienteId(this,get_id);
            ingresarTexto(aux.nombre,20,"Ingrese el nombre: ");
            ingresarTexto(aux.direccion,25,"Ingrese la direccion: ");
            aux.horas=ingresarInt("cantidad horas trabajadas",80,200);
            emp=archivo_nuevoEmp(aux.id,aux.nombre,aux.direccion,aux.horas);

            if(emp !=NULL)
            {
                retorno=1;
                tools_ShowTitulo("Empleado Nuevo:");
                Muestra1UnElemento(emp);
                resp=Responder("Confirma el ingreso de este empleado?");
                if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                    system("pause");
                }
                else if(resp=='S')
                {
                    this->add(this,emp);
                    this->sort(this,ComparaNombre,1);
                }

            }

        }while(Responder("Continua ingresando:")=='S');

    }//fin if(this !=NULL)
}
