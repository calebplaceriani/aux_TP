#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Funciones.h"
#define CANT_EMPLEADOS 10 //cambiar cant empleados a 1000

int main()
{
    Employee empleados[CANT_EMPLEADOS];
    inicializarEmpleado(empleados,CANT_EMPLEADOS);
    int opcionMenu=0,indiceLibre,id,idAux;


do
{
    printf("\n1 - ALTA DE EMPLEADO\n");
    printf("\n2 - MODIFICACION DE EMPLEADO\n");
    printf("\n3 - BAJA DE EMPLEADO\n");
    printf("\n4 - INFORMAR EMPLEADOS\n");
    printf("\n\n5 - SALIR");

    fflush(stdin);

    scanf("\n\n%d",&opcionMenu);

    switch(opcionMenu)
    {
    case 1:
            indiceLibre=buscarLugarlibre(empleados,CANT_EMPLEADOS);
            if(indiceLibre>-1)
            {
                if(altaDeEmpleado(empleados,CANT_EMPLEADOS,indiceLibre)==0)
                {
                    system("cls");
                    printf("ALTA EXITOSA");
                    cargaMinima=1;
                }
                else
                {
                    system("cls");
                    printf("ERROR REALIZAR EL ALTA");
                }

            }
            else
            printf("ERROR - Cupo de empleados lleno");
            break;
    case 2:
            if(cargaMinima==1)
             {
                mostrarEmpleados(empleados,CANT_EMPLEADOS);
                if(utn_getInt(&idAux,"Ingrese el ID del empleado a modificar\n","ERROR - ID Invalido\n",0,CANT_EMPLEADOS-1,2)==0)
                {
                id=buscarEmpleadoPorId(empleados,CANT_EMPLEADOS,idAux);
                if(modificarEmpleado(empleados,CANT_EMPLEADOS,id)==0)
                {
                    system("cls");
                    printf("MODIFICACION EXITOSA");
                }
                else
                    {
                        printf("\nERROR - NO SE PUDO MODIFICAR EMPLEADO");
                    }
                }
                else
                {
                    system("cls");
                    printf("\nERROR - NO SE PUDO MODIFICAR EMPLEADO");
                }
             }
             else
                printf("\n ERROR - CARGUE AL MENOS UN EMPLEADO PARA UTILIZAR ESTA OPCION");
            break;
    case 3:
            if(cargaMinima==1)
             {
                mostrarEmpleados(empleados,CANT_EMPLEADOS);
                if(utn_getInt(&idAux,"Ingrese el ID del empleado al cual quiere Darle de baja","ERROR - ID INECISTENTE",0,CANT_EMPLEADOS-1,2)!=-1)
                {
                    if(bajaDeEmpleado(empleados,idAux,CANT_EMPLEADOS)==0)
                    {
                        system("cls");
                        printf("BAJA EXITOSA");

                    }

                }
             }
             else
                printf("\n ERROR - CARGUE AL MENOS UN EMPLEADO PARA UTILIZAR ESTA OPCION");
            break;
    case 4:
            if(cargaMinima==1)
             {
                if(ordenarEmpleados(empleados,CANT_EMPLEADOS)==0)
                mostrarEmpleados(empleados,CANT_EMPLEADOS);
                else
                {
                    system("cls");
                    printf("ERROR - NO HAY SUFICIENTES EMPLEADOS");
                }
             }
             else
                printf("\n ERROR - CARGUE AL MENOS UN EMPLEADO PARA UTILIZAR ESTA OPCION");
                break;
    case 5:
            break;
    default:
            system("cls");
            printf("\nERROR - INGRESE UNA OPCION VALIDA");

    }
}while(opcionMenu!=5);
    return 0;
}
