#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



int getFloat(float* pBuffer);
int getInt(int* pBuffer);
int utn_getFloat(  float* pFloat, char* msg,char* msgError,float min, float max,int reintentos);
int utn_getInt(  int* pInt, char* msg,char msgErr[],int min, int max,int reintentos);
int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);
int utn_getMail(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int verificarArregloSoloLetras(char *pArreglo);
int verificarArreglosoloFlotantes(char* pBuffer);
int verificarArregloSoloNumeros(char *pArreglo);
int verificarArregloAlfanumerica(char *pArreglo);
int verificarNumeroTelefono(char *pArreglo);

void initArray(int* pArray, int limite, int valor);
void mostrarArray(int* pArray, int limite);
int calcularMaximoArray(int* pArray, int limite, int* pMaximo);
void ordenarArreglo(int *pArray,int limite,int flagMayorMenor);


void insertion(int data[],int len);

int verificarCuit(char *pArreglo);
int generarID(void);


#endif // FUNCIONES_H_INCLUDED
