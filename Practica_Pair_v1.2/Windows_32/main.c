#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>
#define ASCENDENTE 0
#define DESCENDENTE 1
/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{


    ArrayList *listaDeEmpleados;//puntero de arraylist
    listaDeEmpleados=al_newArrayList();//asignamos al puntero la direccion de memoria del arraylist
    Employee* empAux;
    FILE* pFile;
    int aux,cant;
    int i;
    pFile=fopen("data.csv","r");


    char seguir='s';
    int opcion;


    do
    {
        printf("1-Parse del archivo data.csv\n");
        printf("2-Listar Empleados \n");
        printf("3-Ordenar por nombre\n");
        printf("4-Agregar un elemento\n");
        printf("5-Elimina un elemento\n");
        printf("6-Listar Empleados (Desde/Hasta)\n");
        printf("7-SALIR \n");

        scanf("%d",&opcion);
        opcion=validarRango(opcion,1,7,"Error.Ingrese opcion correcta: ");

        switch(opcion)
        {

            case 1:
                aux=parserEmployee(pFile,listaDeEmpleados);
                cant=al_len(listaDeEmpleados);

                if(aux==1)
                {
                    printf("Se han cargado %d registros.\n",cant);
                }else
                {
                    printf("El archivo no pudo ser leido o el arraylist esta NULL.\n");
                }

                system("pause");
                system("cls");

            break;

            case 2:


                if(employee_listar(listaDeEmpleados)==0)
                {
                    printf("No se pudo listar.\n");
                }
                system("pause");
                system("cls");


            break;

            case 3:

                if(al_sort(listaDeEmpleados,employee_compare,ASCENDENTE)==0)
                {
                    printf("Se ordeno exitosamente.\n");
                }else
                {
                    printf("No pudo ordenarse.\n");
                }
                system("pause");
                system("cls");
            break;

            case 4:

                employee_add(listaDeEmpleados);
                system("pause");
                system("cls");
            break;

            case 5:
                employee_remove(listaDeEmpleados);
                system("pause");
                system("cls");

            break;
            case 6:
                listarDesdeHasta(listaDeEmpleados);
                system("pause");
                system("cls");
            break;
            case 7:
                seguir='n';
                system("pause");
                system("cls");
            break;

}

}while(seguir=='s');



    return 0;
}
