#include "utnlib.h"
#include <stdio.h>

int Get_Int(char mensaje [100])
{
	int aux;
	printf(mensaje);
	scanf("%d",&aux);
	return aux;
}

float Get_Float(char mensaje [100])
{
	float aux;
	printf(mensaje);
	scanf("%f",&aux);
	return aux;
}


int Utn_getInt(char mensaje [100], int min, int max, int* Num)
{
	int validate=0;
	int aux;
	aux=Get_Int(mensaje);
	if(aux>min&&aux<max)
	{
		*Num=aux;
		validate = 1;
	}
	return validate;
}

int Utn_getFloat(char mensaje [100], float min, float max, float* Num)
{
	int validate=0;
	float aux;
	aux=Get_Float(mensaje);
	if(aux>min&&aux<max)
	{
		*Num=aux;
		validate = 1;
	}
	return validate;
}


void Utn_getString(char mensaje[],char input [])
{
    printf("%s", mensaje);
    //fflush(stdin);
    gets(input);
}
