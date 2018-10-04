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
/** \brief Inicializa todos los campos isEmpty del array del empleados en TRUE (1)
 *
 * \param lista Employee*
 * \param int len
 * \return int retorna -1 si es un puntero a NULL o si el len es < 0 / retorna 0 si esta ok
 *
 */

int inicializarEmpleado(Employee* empleados,int len);

/** \brief Busca el primer Indice libre (isEmpty == true) del array de empleados
 *
 * \param lista Employee*
 * \param int len
 * \return int retorna -1 si no hay lugar libre / retorna 0 si esta ok
 *
 */
int buscarLugarlibre(Employee* empleados,int len);

/** \brief Da de alta un empleado
 * \param lista Employee*
 * \param int len
 * \param indice libre
 * \return int retorna -1 si no se dio de alta / retorna el indice libre si esta ok
 *
 */
int altaDeEmpleado(Employee* empleados,int len,int indice);

/** \brief modifica campos de un empleado
 * \param lista Employee*
 * \param int len
 * \param indice elegido por usuario
 * \return int retorna -1 si no se pudo modificar / retorna 0 si esta ok
 *
 */
int modificarEmpleado(Employee* empleados, int len, int indice);

/** \brief busca el indice de un empleado recibiendo su ID
 * \param lista Employee*
 * \param int len
 * \param indice ingresado
 * \return int retorna -1 si no se pudo encontrar / retorna el indice encontrado si esta ok
 *
 */
int buscarEmpleadoPorId(Employee* empleados,int len,int id);

/** \brief muestra lista de empleados dados de alta
 * \param lista Employee*
 * \param int len
 *
 */
void mostrarEmpleados(Employee* empleados,int len);

/** \brief da de baja (logica) a un empleado
 * \param lista Employee*
 * \param int id
 * \param int len
 * \return int retorna -1 si no se pudo dar  de baja / retorna 0 si esta ok
 *
 */
int bajaDeEmpleado(Employee* empleados,int id,int len);

/** \brief Ordena array de empleados por nombre
 * \param lista Employee*
 * \param int len
 * \return int retorna -1 si no se pudo encontrar / retorna 0 si esta ok
 *
 */
int ordenarEmpleados(Employee* empleados,int len);

/** \brief informa los empleados por salario y apellido
 * \param lista Employee*
 * \param int len
 * \return int retorna -1 si da puntero a NULL o len < 0 / retorna 0 si esta ok
 *
 */
int informeSalarioEmpleado(Employee* empleado, int len);
#endif // ARRAYEMPLOYEES_H_INCLUDED
