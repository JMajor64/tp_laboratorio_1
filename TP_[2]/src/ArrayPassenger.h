#include "utnlib.h"
#include <stdio.h>
/*
 * ArrayPassenger.h
 *
 *  Created on: 5 may 2022
 *      Author: Agus
 */

typedef struct {
	int id;
	char name[51];
	char lastname[51];
	float Price;
	char flycode[10];
	int typePassenger;//1_niño; 2_Adulto; 3_Adulto Mayor
	int statusFlight;//3_Cancelado; 1_Activo; 2_...(Suspendido)
	int isEmpty;
}Passenger;

typedef struct
{
	char fecha[12];
	char destination [10];//Destino
	char description[20];
	char flycode[11];
}fly;

int initPassenger(Passenger lista[], int len);

void Passenger_GetName(Passenger list[], int index);

void Passenger_GetLastname(Passenger list[], int index);

void Passenger_GetFlycode(Passenger list[], int index,fly flylist[]);

void Passenger_GetPrice(Passenger list[], int index);

void Get_Passenger(Passenger list[], int index,fly flylist[]);

void Passenger_GetType(Passenger list[], int index);

void Passenger_printStatus(int status);

void Passenger_printType(int type);

void Passenger_GetStatus(Passenger list[], int index);

int Passenger_addPassengers(Passenger list[],int tam,fly flylist[]);

void Print_Passenger(Passenger list[], int index);

int ModifyPassenger(Passenger list[], int index,fly flylist[]);

int findPassengerById(Passenger list[],int tam,int index);

int Passenger_Search(Passenger list[],int tam);

int Passenger_Modify(Passenger list[],int tam,fly flylist[]);

void printPassengers(Passenger list[],int tam);

void Passenger_removePassenger(Passenger list[],int tam);

void SwapPassengers(Passenger list[],int Firstindex,int SecIndex);

void sortPassengers_ByName(Passenger list[],int tam);

void sortPassengers_ByName(Passenger list[],int tam);

void sortPassengers_ByNameDecendent(Passenger list[],int tam);

void sortPassengers_ByIdAscendent(Passenger list[],int tam);

void sortPassengers_ByIdDescendent(Passenger list[],int tam);

void sortPassengers_ByTypeAscendent(Passenger list[],int tam);

void sortPassengers_ByTypeDescendent(Passenger list[],int tam);

void Passenger_sortPassengers(Passenger list[],int tam);

void sortPassengers_ByflycodeAscendent(Passenger list[],int tam);

void sortPassengers_ByflycodeDescendent(Passenger list[],int tam);

void sortPassengers_ByTypeAndName(Passenger list[],int tam);

void sortPassengers_ByTypeAndNameDecendent(Passenger list[],int tam);

void Passenger_Set_Default(Passenger list[],int tam);

void printFlys(fly list[],int index);

void set_Flycodes(fly list[]);
