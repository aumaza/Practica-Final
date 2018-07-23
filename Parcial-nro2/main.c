#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tools.h"
#include "Empleados.h"
#include "Archivo.h"
#define NOM_ARCHIVO "archivo.csv"
#define NOM_GUARDAR "sueldo.csv"
#define MAX 1

#define UP 0
#define DOWN 1

int main()
{
    char seguir='S';
    int opcion;
    int retorno=0;

    ArrayList *ListaEmpleados;
    ListaEmpleados=al_newArrayList();
    ArrayList *ListaAux;
    ListaAux=al_newArrayList();
    eEmpleado *emp;

    if(ListaEmpleados !=NULL && ListaAux !=NULL)
    {

        while(seguir=='S')
        {
          ShowMenu("1:Cargar Archivo\n2:Listar Ordenado \n3:Listar\n4:Calcula Salario\n5: Guardar Archivo\n6: Salario Maximo\n7:Ordenar por Salario\n");
          scanf("%d",&opcion);
          ValidaMenu(opcion,0,7);
            switch(opcion)
            {
                case 1:
                    cargarDesdeArchivo(ListaEmpleados,NOM_ARCHIVO);
                    break;
                case 2:
                    ListaAux=ListarPorNombre(ListaEmpleados,0);
                   if(ListaAux !=NULL)
                   {
                       MostrarElementos(ListaAux,"Ordenador por Nombre",0,ListaAux->len(ListaAux));
                   }
                   else
                    printf("No hay nada para mostrar\n");
                   // system("pause");
                    break;
                case 3:
                    MostrarElementos(ListaEmpleados,"Listado de Empleados",0,ListaEmpleados->len(ListaEmpleados));
                    break;
                case 4:
                   // ListaAux=al_map(ListaEmpleados, CalcularSalary);
                   if(al_map(ListaEmpleados,CalcularSalary)==1)
                   {
                       printf("Se pudieron calcular todos los salarios\n");
                       system("pause\n");
                       MostrarElementosconSalario(ListaEmpleados,0,ListaEmpleados->len(ListaEmpleados));
                   }
                   // if(ListaEmpleados!=NULL ) ya esta evaluado al principio

                    else
                        printf("No se pudieron calcular todos\n");
                    break;
                case 5:
                    GuardarArchivoT(ListaEmpleados,NOM_GUARDAR);
                    break;
                case 6:
                    emp=BuscaMaximo(ListaEmpleados,comparaEmpleado,0);
                   // printf("%s\t%s\t%d\t $ %.2f \n",get_Nombre(emp),get_dire(emp),get_horas(emp), emp->sueldo/*get_sueldo(emp)*/);
                   // system("pause");

                    Muestra1UnElementoSalario(emp);
                    system("pause");
                    break;
                case 7:
                    ListaAux=ListarPorSalario(ListaEmpleados,1);
                    MostrarElementosconSalario(ListaAux,0,ListaAux->len(ListaAux));
                    break;
                case 0:
                    seguir='n';
                    break;
            }//FIN switch
        }//fin while




            }//fin if(ListaAlumnos !=NULL)
    return 0;
}
