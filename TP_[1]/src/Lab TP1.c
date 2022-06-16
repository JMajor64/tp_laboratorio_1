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
#include <string.h>
#include "utnlib.h"
#include "aerolineas.h"


int main(void) {

	float PrecioAerolineas=0;
	float PrecioLatam=0;
	float Km=0;
	float debitoArg=0;
	float creditoArg=0;
	float BTCArg=0;
	float PrecioPorKmArg=0;
	float debitoLatam=0;
	float creditoLatam=0;
	float BTCLatam=0;
	float PrecioPorKmLatam=0;
	float DiferenciaDePrecios=0;
	int KmCargado=0;
	int PrecioCargado=0;
	int valoresCalculados=0;

    int operacion;
    do
    {
    printf("\n");
    printf("****************************************************************\n");
    printf("\n");
	printf("1_Ingresar cantidad de Km\n");
	printf("2_Ingresar Monto a pagar\n");
	printf("3_Calcular valores\n");
	printf("4_Mostrar Precios\n");
	printf("5_Carga forzada de datos\n");
	printf("6_Salir\n");
    printf("\n");
    printf("****************************************************************\n");
    printf("\n");

    Utn_getInt("Elija una opcion:\n",0,1000,&operacion);

    system("@cls||clear");
	switch(operacion){

    case 1:
    	KmCargado=LoadKm(&Km);
    	valoresCalculados=0;
        break;

    case 2:
    	printf("Aerolineas Argentinas:\n");
    	PrecioCargado=LoadPrice(&PrecioAerolineas);
    	printf("\n");
    	printf("Aerolineas Latam\n");
    	PrecioCargado=LoadPrice(&PrecioLatam);
    	valoresCalculados=0;
        break;

    case 3:
    		if(KmCargado&&PrecioCargado)
    		{
    			valoresCalculados=ComputeValues(Km,PrecioLatam,&debitoLatam,&creditoLatam,&BTCLatam,&PrecioPorKmLatam);
    			valoresCalculados=ComputeValues(Km,PrecioAerolineas,&debitoArg,&creditoArg,&BTCArg,&PrecioPorKmArg);
    			DiferenciaDePrecios=PriceDifference(PrecioAerolineas, PrecioLatam);
    			printf("Valores Calculados Exitosamente\n");
    			getch();
    		}else
    		{
    		  	printf("Por favor cargue Km y Precio antes de continuar\n");
    		}
        break;

    case 4:
			if(valoresCalculados)
			{
				printf("Km Ingresados: %.2f \n",Km);

				printf("Aerolineas Argentinas\n");
				printf("\n");
				PrintValues(Km,PrecioAerolineas,debitoArg,creditoArg,BTCArg,PrecioPorKmArg);
				printf("\n");
				printf("Aerolineas Latam\n");
				printf("\n");
				PrintValues(Km,PrecioLatam,debitoLatam,creditoLatam,BTCLatam,PrecioPorKmLatam);
				printf("\n");
				printf("La diferencia de precios es de $ %.2f\n",DiferenciaDePrecios);
				getch();
			}else
			{
				printf("Error: Calcular antes los valores\n");
				getch();
			}
        break;

    case 5:
    	LoadDefault(&Km,&PrecioAerolineas,&PrecioLatam);
    	ComputeValues(Km,PrecioLatam,&debitoLatam,&creditoLatam,&BTCLatam,&PrecioPorKmLatam);
    	valoresCalculados=ComputeValues(Km,PrecioAerolineas,&debitoArg,&creditoArg,&BTCArg,&PrecioPorKmArg);
    	DiferenciaDePrecios=PriceDifference(PrecioAerolineas, PrecioLatam);

		printf("Km Ingresados: %.2f \n",Km);

		printf("Aerolineas Argentinas\n");
		printf("\n");
		PrintValues(Km,PrecioAerolineas,debitoArg,creditoArg,BTCArg,PrecioPorKmArg);
		printf("\n");
		printf("Aerolineas Latam\n");
		printf("\n");
		PrintValues(Km,PrecioLatam,debitoLatam,creditoLatam,BTCLatam,PrecioPorKmLatam);
		printf("\n");
		printf("La diferencia de precios es de $ %.2f\n",DiferenciaDePrecios);
		getch();
        break;

    case 6:
    	printf("Godbye!\n");
    	getch();
    	break;

    default:
    	printf("Opcion Invalida\n");
    	getch();
    	break;
	}



	system("@cls||clear");

    }while(operacion!=6);

    return 0;
}
