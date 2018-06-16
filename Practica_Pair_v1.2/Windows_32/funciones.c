#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

int validarRango(int validar ,int num1,int num2,char mensaje[40])
{

    while(validar<num1 || validar>num2)
    {
        printf(mensaje);
        scanf(" %d",&validar);
    }

    return validar;
}
