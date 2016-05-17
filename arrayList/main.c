#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
int main()
{
    int auxInt;
    arrayList auxLista;

    auxInt = newEmployeeArray(&auxLista);
    if(auxInt == 0)
    {
        auxInt = initArray(&auxLista);
        if(auxInt== 0)
        {
            auxInt = addEmployee(&auxLista);
            if(auxInt== 0)
            {
                printEmployee(&auxLista);
            }
        }
    }
    else
    {
        printf("ERROR!");
    }
    return 0;
}
