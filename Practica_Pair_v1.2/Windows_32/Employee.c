#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#define true1 1
#define false0 0

int listarDesdeHasta(ArrayList* arrayEmpleados)
{
    int inicio,limite,i,cant;
    Employee* empAux;
    cant=al_len(arrayEmpleados);
    printf("Listar desde: ");
    scanf(" %d",&inicio);
    printf("Listar hasta: ");
    scanf(" %d",&limite);
    while(inicio<1 || inicio>cant)
    {
        printf("Ingrese una id correcta. ( 1 a %d )\n",cant);
        printf("Listar desde: ");
        scanf(" %d",&inicio);
        printf("Listar hasta: ");
        scanf(" %d",&limite);
    }
    for(i=inicio;i<=limite;i++)
    {
        empAux=al_get(arrayEmpleados,i-1);
        employee_print(empAux);

    }
    return 1;
}

void* employee_getById(ArrayList* arrayEmpleados,int id)
{
    int i;
    int tam;

    Employee* empReturn;
    Employee* empAux;
    tam=al_len(arrayEmpleados);

    for(i=0;i<tam;i++)
    {
        empAux=al_get(arrayEmpleados,i);
        if(id==empAux->id)
        {
            empReturn=empAux;
        }
    }
    return empReturn;
}

int employee_remove(ArrayList* arrayEmpleados)
{
    int idIngresada;
    int index;
    int cant;
    char respuesta;
    Employee* empAux;
    employee_listar(arrayEmpleados);//muestro empelados
    cant=al_len(arrayEmpleados);//size del arrayList
    printf("\nIngrese id del empleado a remover: ");//pido id a eliminar
    scanf(" %d",&idIngresada);
    idIngresada=validarRango(idIngresada,1,cant,"Ingrese id valida: ");//valido la id
    empAux=employee_getById(arrayEmpleados,idIngresada);//encuentra la id, y devuelve el puntero
    index=al_indexOf(arrayEmpleados,empAux);
    if(empAux!=NULL)
    {
        employee_print(empAux);
        printf("Esta seguro que desea eliminar el empleado? s/n : ");
        scanf(" %c",&respuesta);
        respuesta=tolower(respuesta);
        if(respuesta=='s')
        {
            al_remove(arrayEmpleados,index);
            printf("El usuario fue eliminado.\n");
        }else
        {
            printf("Operacion cancelada.\n");

        }
      }else
        {
        printf("No se encontro el empleado..\n");
        return 0;
        }
    return 1;
}

int devolverIdSiguiente(ArrayList* arrayEmpleados)
{
    int id=0;
    id=(arrayEmpleados->size)+1;
    return id;
}

int employee_add(ArrayList* arrayEmpleados)
{
    Employee* empAux=employee_new();
    char name[50];
    char lastName[50];

    printf("Name: ");
    fflush(stdin);
    gets(name);
    printf("Lastname: ");
    fflush(stdin);
    gets(lastName);
    employee_setName(empAux,name);
    employee_setLastName(empAux,lastName);
    int id=devolverIdSiguiente(arrayEmpleados);
    empAux->id=id;
    empAux->isEmpty=1;

    al_add(arrayEmpleados,empAux);


}

int employee_listar(ArrayList* arrayEmpleados)
{
    int i;
    int retorno = 0;
    int cant=0;
    Employee* unEmpleado = NULL;
    if(arrayEmpleados!=NULL)
    {
    cant=al_len(arrayEmpleados);

    printf("        |  id |  name  |  lastname |    status       |       \n");
    for(i = 0; i < cant; i++)
    {
        unEmpleado = (Employee*)al_get(arrayEmpleados, i);

        if(unEmpleado != NULL)
        {
            employee_print(unEmpleado);
            retorno = 1;
        }
        if(i==50 || i==100 || i==150 || i==200 || i==250 || i==300 || i==350 || i==400 || i==450 || i==500 || i==550 || i==600 || i==650 || i==700 || i==750 || i==800 || i==850 || i==900 || i==950 || i==1000 )
        {
            system("pause");
            system("cls");
        }
    }
    }
    return retorno;
}

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=0;
    Employee* e1=(Employee*)pEmployeeA;//parseo el void* a mi elemento del array
    Employee* e2=(Employee*)pEmployeeB;

    retorno=strcmpi(e1->name,e2->name);//comparo por nombre
    return retorno;
}


void employee_print(Employee* this)
{

    printf("%10d  %10s  %10s  %10d\n",this->id,this->name,this->lastName,this->isEmpty);
}


Employee* employee_new(void)
{

    Employee* returnAux;
    returnAux=(Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{


}


/**FUNCIONES GET Y SET**/

int employee_getId(Employee* this)
{

    return 0;

}
int employee_getStatus(Employee* emp)
{
    int retorno;
    retorno=emp->isEmpty;

    return retorno;
}

int employee_setStatus(Employee* emp,char* status)
{
    int retorno=1;

    if(strcmpi(status,"true"))
    {
        emp->isEmpty=true1;
    }else
    {
        emp->isEmpty=false0;
    }


    return retorno;
}

int employee_setLastName(Employee* emp,char* lastName)
{
    int retorno=1;

    strcpy(emp->lastName,lastName);

    return retorno;
}

int employee_setName(Employee* emp,char* name)
{
    int retorno=1;

    strcpy(emp->name,name);

    return retorno;
}

int employee_setId(Employee* emp,int id)
{
    int retorno=1;

    emp->id=id;

    return retorno;
}


