#include "utnlib.h"
#include <stdio.h>

int LoadKm(float* Km);
int LoadPrice(float* PriceAerolineas);
void LoadDefault(float* Km, float* PriceAerolineas, float* PriceLatam); //case 5
int ComputeValues(float Km,float Price,float* debit, float* credit, float* btc, float* KmPrice);//case 3
float PriceDifference(float PriceAerolineas,float PriceLatam);//complemento de Case 3
void PrintValues(float Km,float Price,float debit, float credit, float btc, float KmPrice);//case 4
//void DocumentResults();
