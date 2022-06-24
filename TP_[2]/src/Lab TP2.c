/*
 ============================================================================
 Name        : Lab.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#define TAM 10
#define flys 3
 Passenger PassengerList[TAM];
 fly flylist[3];

int main(void)
{
	setbuf(stdout, NULL);
	int loaded=0;
	int operacion;

	initPassenger(PassengerList,TAM);
	set_Flycodes(flylist);

	do
	{
	    printf("\n");
	    printf("****************************************************************\n");
	    printf("\n");
		printf("1_Alta de pasajero\n");
		printf("2_Modificar pasajero\n");
		printf("3_Dar de baja pasajero\n");
		printf("4_Mostrar Lista de pasajeros\n");
		printf("5_Ordenar lista\n");
		printf("6_Salir\n");
	    printf("\n");
	    printf("7_Cargar Opciones por defecto\n");
	    printf("\n");
	    printf("****************************************************************\n");
	    printf("\n");

	    Utn_getInt("Elija una opcion:\n",0,1000,&operacion);

	    system("@cls||clear");
		switch(operacion)
		{

	    case 1:
	    	Passenger_addPassengers(PassengerList,TAM,flylist);
	    	loaded=1;
	        break;

	    case 2:
	    	if(loaded){
	    		Passenger_Modify(PassengerList,TAM,flylist);
	    	}

	        break;

	    case 3:
	    	if(loaded){
	    		Passenger_removePassenger(PassengerList,TAM);
	    	}
	        break;

	    case 4:
	    	if(loaded){

	    		printPassengers(PassengerList,TAM);
	    	}
				getch();
	        break;

	    case 5:
	    	if(loaded){

	    		Passenger_sortPassengers(PassengerList,TAM);
	    	}
	        break;

	    case 6:
	    	printf("Godbye!\n");
	    	getch();
	    	break;

	    case 7:
	    	Passenger_Set_Default(PassengerList, TAM);
	    	loaded=1;
	    	break;

	    default:
	    	printf("Opcion Invalida\n");
	    	getch();
	    	break;
		}
		system("@cls||clear");
	}while(operacion!=6);
	return EXIT_SUCCESS;
}
