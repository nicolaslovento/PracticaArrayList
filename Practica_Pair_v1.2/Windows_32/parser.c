#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#define REGISTROS 50


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int returnAux=1;
    int i=1;

    Employee* aux;

    if(pFile==NULL && pArrayListEmployee==NULL)
    {
        returnAux=-1;
    }else
    {
        char id [10];
        char name[50];
        char lastName[50];
        char status[50];



        while(i<REGISTROS)
            {
            int r;
            Employee* empleado;
            empleado=employee_new();
            r=fscanf(pFile," %[^,],%[^,],%[^,],%[^,\n]\n",id,name,lastName,status);

            employee_setId(empleado,charIdToId(id));
            employee_setName(empleado,name);
            employee_setLastName(empleado,lastName);
            employee_setStatus(empleado,status);

            al_add(pArrayListEmployee,empleado);
            i++;


            }
        }


    fclose(pFile);


    return returnAux;
}

int charIdToId(char* charId)
{
    int id;
    id = atoi(charId);

    return id;
}

int setStatusInt(char *status)
{
    int isEmpty;
    if(strcmp(status,"true"))
    {
        isEmpty=1;
    }else
    {
        isEmpty=0;
    }

    return isEmpty;
}
