#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#include "input.h"
int newEmployeeArray(arrayList* list)
{
    int retorno = -1;

    void* pAux;
    if(list != NULL)
    {
        pAux = malloc(sizeof(Employee)*3);
        if(pAux !=NULL)
        {
            list->sizeArray = 3;
            list->punteroArray = pAux;
            retorno = 0;
        }
    }
    return retorno;
}

int initArray(arrayList* list)
{
    int retorno = -1;
    int i;
    Employee* pAuxEmployee;
    if(list != NULL) // if(list != NULL && list->sizeArray>0)
    {
        retorno = 0;
        pAuxEmployee = (Employee*)list->punteroArray;
        for(i=0;i<list->sizeArray;i++)
        {
            (pAuxEmployee+i)->isEmpty = 1;
        }
    }
    return retorno;
}

int buscarLibre(arrayList* list)
{
    int indice = -1;
    int i;
    Employee* pAuxEmployee;
    if(list != NULL) //if(arrayList != NULL && list->sizeArray > 0)
    {
        pAuxEmployee = (Employee*)list->punteroArray;
        for(i=0;i<list->sizeArray;i++)
        {
            if((pAuxEmployee+i)->isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int pedirDatos(int* id, char* nombre,char* apellido)
{
    int auxInt;

    do
    {
        auxInt = getInt(id, "Ingrese el id: ", "Error: el id tiene que ser numerico", 0, 100);
    }while(auxInt!=0);

    do
    {
        auxInt = getName(nombre, "Ingrese su nombre: ", "ERROR: maximo 50 caracteres", 0, 51);
    }while(auxInt!=0);

    do
    {
        auxInt = getName(apellido, "Ingrese su apellido: ", "ERROR: maximo 50 caracteres", 0, 51);
    }while(auxInt!=0);
    return auxInt;
}
int addEmployee(arrayList* list)
{
    int indice;
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    int id;
    int auxInt;
    Employee* auxEmployee;
    if(list != NULL)
    {
        retorno = 0;
        indice = buscarLibre(list);
        if(indice != -1)
        {
            auxInt = pedirDatos(&id, nombre, apellido);
            if(auxInt == 0)
            {
                auxEmployee = (Employee*)list->punteroArray;
                (auxEmployee+indice)->id = id;
                strcpy((auxEmployee+indice)->nombre, nombre);
                strcpy((auxEmployee+indice)->apellido, apellido);
                (auxEmployee+indice)->isEmpty = 0;
            }
        }
    }
    return retorno;
}

int printEmployee(arrayList * list)
{
    int retorno = -1;
    Employee* auxEmployee;
    int i;
    if(list !=NULL)
    {
        auxEmployee = (Employee*)list->punteroArray;
        retorno = 0;
        for(i=0;i<list->sizeArray;i++)
        {
            if((auxEmployee+i)->isEmpty == 0)
            {
                printf("Nombre:%s\nApellido:%s\nid:%d\n",(auxEmployee+i)->nombre, (auxEmployee+i)->apellido, (auxEmployee+i)->id);
            }
        }
    }
    return retorno;
}


