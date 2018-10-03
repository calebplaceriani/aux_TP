#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;

}Employee;

int inicializarEmpleado(Employee* empleados,int len);
int buscarLugarlibre(Employee* empleados,int len);
int altaDeEmpleado(Employee* empleados,int len,int indice);
int modificarEmpleado(Employee* empleados, int len, int indice);
int buscarEmpleadoPorId(Employee* empleados,int len,int id);
void mostrarEmpleados(Employee* empleados,int len);
int bajaDeEmpleado(Employee* empleados,int id,int len);
int ordenarEmpleados(Employee* empleados,int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
