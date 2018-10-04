#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Funciones.h"
#include <strings.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int inicializarEmpleado(Employee* empleados,int len)
{
    int i;
    int retorno=-1;
    if(empleados!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            empleados[i].isEmpty=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

int buscarLugarlibre(Employee* empleados,int len)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<len;i++)
    {
        if(empleados[i].isEmpty==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}

int buscarEmpleadoPorId(Employee* empleados,int len,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(empleados[i].isEmpty==FALSE && empleados[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void mostrarEmpleados(Employee* empleados,int len)
{
    int i;
   if(empleados!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            if(empleados[i].isEmpty==FALSE)
                {
                    printf("\nNOMBRE:%s \nAPELLIDO:%s \nSALARIO:%.2f \n ID:%d \nSECTOR:%d \nISEMPTY:%d \n",empleados[i].nombre,empleados[i].apellido,empleados[i].salario,empleados[i].id,empleados[i].sector,empleados[i].isEmpty);
                }
        }
    }
}

int altaDeEmpleado(Employee* empleados,int len,int indice)
{
    int retorno=-1;
    char nombreAux[51];
    char apellidoAux[51];
    float salarioAux;
    int sectorAux;

    if(indice>=0 && indice<len)
    {
        system("cls");
        if(utn_getLetras(nombreAux,51,2,"\nIngrese nombre\n","\nerror\n")==0)
        {
            if(utn_getLetras(apellidoAux,51,2,"\nIngrese Apellido\n","\nerror\n")==0)
            {
                if(utn_getFloat(&salarioAux,"\ningrese salario (numero flotante)\n","\n error\n",10,9000000,2)==0)
                {
                    if(utn_getInt(&sectorAux,"\ningrese Numero de Sector ","\n error\n",0,500,2)==0)
                    {
                        strncpy(empleados[indice].nombre,nombreAux,50);
                        strncpy(empleados[indice].apellido,apellidoAux,50);
                        empleados[indice].salario=salarioAux;
                        empleados[indice].sector=sectorAux;
                        empleados[indice].id=generarID();
                        empleados[indice].isEmpty=FALSE;
                        retorno=0;
                    }

                }
            }
        }
    }

return retorno;

}

int modificarEmpleado(Employee* empleados, int len, int indice)
{
    int retorno=-1;
    char nombreAux[51];
    char apellidoAux[51];
    float salarioAux;
    int sectorAux;
    int opcionCambio;

    if(indice>-1&&indice<=len)
    {
        printf("1 - Cambiar Nombre\n");
        printf("2 - Cambiar Apellido\n");
        printf("3 - Cambiar Salario\n");
        printf("4 - Cambiar Sector\n");
        printf("5 - Salir\n");
        scanf("%d",&opcionCambio);
        switch(opcionCambio)
        {
        case 1:
                    if(utn_getLetras(nombreAux,51,2,"\nIngrese el nuevo nombre","\nERROR - NUEVO NOMBRE INVALIDO")==0)
                    {
                        strcpy(empleados[indice].nombre,nombreAux);
                        retorno=0;
                    }
                    break;
        case 2:
                    if(utn_getLetras(apellidoAux,51,2,"\nIngrese el nuevo apellido","\nERROR - NUEVO APELLIDO INVALIDO")==0)
                    {
                        strcpy(empleados[indice].apellido,apellidoAux);
                        retorno=0;
                    }
                    break;
        case 3:
                    if(utn_getFloat(&salarioAux,"\nIngrese nuevo salario","\nERROR - NUEVO SALARIO INVALIDO",10.0,9000000.0,2)==0)
                    {
                        empleados[indice].salario=salarioAux;
                        retorno=0;
                    }
                    break;
        case 4:
                    if(utn_getInt(&sectorAux,"Ingrese el nuevo sector (numero entero entre 1-5","Error - sector invalido",1,5,2)==0)
                    {
                        empleados[indice].sector=sectorAux;
                        retorno=0;
                    }

                    break;
        case 5:

                    break;
        default:
                    printf("\nERROR - INGRESE UNA OPCION VALIDA");
        }

    }
    else
    {
        printf("ERROR - Indice invalido");

    }
     return retorno;
}

int bajaDeEmpleado(Employee* empleados,int id,int len)
{
    int i=0;
    int retorno=-1;
    if(empleados!=NULL && id>=0)
        {
            for (i=0;i<len;i++)
                {
                    if(empleados[i].id==id)
                        {
                            empleados[i].isEmpty=TRUE;
                            retorno=0;
                            break;
                        }
                }
        }
        return retorno;
}

int ordenarEmpleados(Employee* empleados,int len)
{
    int retorno=-1;
    int i,flagswap;
    Employee auxEmpleado;

    if(empleados!=NULL && len > 1)
     {
      do
        {
            flagswap=0;
            for(i=0;i<len-1;i++)
            {
                if(strcmp(empleados[i].apellido,empleados[i+1].apellido)>0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[i+1];
                    empleados[i+1]=auxEmpleado;
                    flagswap=1;
                }
                retorno = 0;
            }
         }while(flagswap);
     }

    return retorno;
}

int informeSalarioEmpleado(Employee* empleado, int len)
{
    int retorno=-1;
    int i;
    float acumSalario=0;
    int empleadosPromedio=0;
    int cantEmpleadosCargados=0;
    float salarioPromedio;
    if(empleado!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(empleado[i].isEmpty==0)
            {
                cantEmpleadosCargados++;
                acumSalario+=empleado[i].salario;
            }
        }
        salarioPromedio=acumSalario/cantEmpleadosCargados;
        printf("\n\nEl salario promedio es: %.2f",salarioPromedio);

        for(i=0;i<len;i++)
        {
            if(empleado[i].salario>salarioPromedio)
            empleadosPromedio++;
        }
        printf("\n\nLa cantidad de empleados arriba del salario promedio es:%d \n\n", empleadosPromedio);
        retorno = 0;
    }


    return retorno;
}
