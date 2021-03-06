#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int flag=0;//si el usuario carga o no el archivo, cambiar criterio de guardado
    int flagT;
    int flagB;
    int verificar=0;
    int dataLoad=0;
    int filtredSaved=0;

    setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* ListaFiltrada;
    do{
    	GetOption:
    	//print
		system("@cls||clear");
		 printf("\n");
		 printf("****************************************************************\n");
		 printf("\n");
		 printf("1: Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
		 printf("2: Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
		 printf("3: Alta de pasajero\n");
		 printf("4: Modificar datos de pasajero\n");
		 printf("5: Baja de pasajero\n");
		 printf("6: Listar pasajeros\n");
		 printf("7: Ordenar pasajeros\n");
		 printf("8: Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
		 printf("9: Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
		 printf("\n");
		 printf("10:Salir\n");
		 printf("\n");
		 printf("11: Filtrar Lista por clase\n");
		 printf("12: Calcular precio de los pasajes con iva\n");
		 printf("13: Verificar lista filtrada\n");
		 printf("\n");
		 printf("****************************************************************\n");
		 printf("\n");

		 Utn_getInt("",0,20,&option);

        switch(option)
        {
            case 1:
            	if(flag!=1)
            	{
            		flag=controller_loadFromText("data.csv",listaPasajeros);
            		flagT=flag;
            		flagB=flag;
            		dataLoad=flag;
            	}
                break;
            case 2:
            	if(flag!=1)
            	{
            		flag=controller_loadFromBinary("data.bin",listaPasajeros);
            		flagT=flag;
            		flagB=flag;
            		dataLoad=flag;
            	}

            	break;
            case 3:
            	dataLoad=controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	if(dataLoad)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Ingrese algun dato antes de continuar\n");
            		system("pause");
            	}
            	break;
            case 5:
            	if(dataLoad)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            	    printf("Ingrese algun dato antes de continuar\n");
            	    system("pause");
            	}
            	break;
            case 6:
            	if(dataLoad)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            	    printf("Ingrese algun dato antes de continuar\n");
            	    system("pause");
            	}
            	break;
            case 7:
            	if(dataLoad)
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            	     printf("Ingrese algun dato antes de continuar\n");
            	     system("pause");
            	}
            	break;
            case 8:
            	flagT=controller_saveAsText("data.csv",listaPasajeros,flag);
            	break;
            case 9:
            	flagB=controller_saveAsBinary("data.bin",listaPasajeros,flag);
            	break;
            case 10:
            	if(flagB==0 || flagT==0)
            	{
            	    freeAll(listaPasajeros);
            	}
            	else{
            		printf("Error, no puede salir sin guardar los cambios\n");
            		system("pause");
            		goto GetOption;
            	}
            	break;
            case 11:
            	verificar=0;
            	ListaFiltrada=controller_FiltrarPorClase(listaPasajeros);
            	printf("Lista Filtrada:\n");
            	controller_ListPassenger(ListaFiltrada);

            	while(verificar==0)
            	{
            		printf("Desea Guargar la lista?(solo se puede guardar una lista filtrada a la vez)\n");
					printf("1: Si\n");
					printf("2: No\n");
					verificar=Utn_getInt("",0,3,&option);
            	}
            	if(option==1)
            	{
            		controller_saveAsBinary("FiltredList.bin",listaPasajeros,1);
            		filtredSaved=1;
            	}
            	break;
            case 12:
            	controller_CalcularIva(listaPasajeros);
            	break;
            case 13:
            	if(filtredSaved)
            	{
            		controler_VerifyFiltredList(listaPasajeros,"FiltredList.bin");
            	}else{
            		printf("No existe lista filtrada\n");
            		system("pause");
            	}
            	break;

            default:
            	break;
        }

    }while(option != 10);
    return 0;
}

