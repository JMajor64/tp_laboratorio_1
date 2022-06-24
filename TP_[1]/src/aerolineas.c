#include "aerolineas.h"

int LoadKm(float* Km)
{
	float aux;
	int val=0;
	ingreso:
	val=Utn_getFloat("Ingrese la cantidad de km del viaje\n",0,10000,&aux);
	if(val)
	{
		*Km=aux;
	}else
	{
		printf("Error: La cantidad de Km es invalida\n");
		goto ingreso;
	}
	return val;
}

int LoadPrice(float* Price)
{
	float aux;
	int val=0;
	ingreso:
	val=Utn_getFloat("Ingrese el precio del viaje\n",0,10000000,&aux);
	if(val)
	{
		*Price=aux;
	}else
	{
		printf("Error: El precio es invalido\n");
		goto ingreso;
	}

	return val;
}

int ComputeValues(float Km,float Price,float* debit, float* credit, float* btc, float* KmPrice)//case 3
{
	float DebitDiscount;
	float CreditInterest;
	float BTCValue=4606954.55;

	//debit
	float aux;
	DebitDiscount=Price*0.1;
	aux=Price-DebitDiscount;
	*debit=aux;

	//credit
	CreditInterest=Price*0.25;
	*credit=Price+CreditInterest;

	//BTC Convert
	*btc=Price/BTCValue;

	//Price/Km
	*KmPrice=Price/Km;
	return 1;
}

void PrintValues(float Km,float Price,float debit, float credit, float btc, float KmPrice)
{
	//printf("Km Ingresados: %.2f \n",Km);
	printf("Precio Final: %.2f\n",Price);
	printf("Precio final abonando con debito: %.2f \n",debit);
	printf("Precio final abonando con credito: %.2f \n",credit);
	printf("Precio abonado en BTC: %.4f \n",btc);
	printf("Precio unitario por Km: %.2f \n",KmPrice);
}

void LoadDefault(float* Km, float* PriceAerolineas, float* PriceLatam)//case 5
{
	float DefaultKm=7090;
	float DefaultPriceAerolineas=133500;
	float DefaultPriceLatam=135000;

	*Km=DefaultKm;
	*PriceAerolineas=DefaultPriceAerolineas;
	*PriceLatam=DefaultPriceLatam;

}
float PriceDifference(float PriceAerolineas,float PriceLatam)
{
	float difference;
	if(PriceAerolineas>PriceLatam)
	{
		difference=PriceAerolineas-PriceLatam;
	}
	else
	{
		difference=PriceLatam-PriceAerolineas;
	}
	return difference;
}
/*

  case5()
 {
   cargarValoresDefault();

   valoresCalculados=1;
 }


  case2();
  {
     pedirF(precioAerolineas);
     pedirF(precioLatam);

     *preciosCargados=1;

     //¿devolver por referencia?
  }
  case1();
  {
     pedirF(Km);
     *kmsCargados=1;

     //¿devolver por referencia?
  }

	//case 4
   printValores();
  {
     “Latam:
 	 a) Precio con tarjeta de débito: r
 	 b) Precio con tarjeta de crédito: r
 	 c) Precio pagando con bitcoin : r
 	 d) Precio unitario: r
 	 Aerolíneas:
 	 a) Precio con tarjeta de débito: r
 	 b) Precio con tarjeta de crédito: r
 	 c) Precio pagando con bitcoin : r
 	 d) Precio unitario: r
 	 La diferencia de precio es : r “
  }

	//case 3
	CalcularValores(km, precioLatam, precioAerolineas)
  {
     a) Tarjeta de débito (descuento 10%)
 	 b) Tarjeta de crédito (interés 25%)
 	 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 	 d) calcular precio por km (precio unitario)
 	 e) calcular diferencia de precio ingresada (Latam - Aerolíneas)

 	 valoresCalculados=1;
  }

 */
