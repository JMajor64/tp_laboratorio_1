#include "ArrayPassenger.h"
/*
 * ArrayPassenger.c
 *
 *  Created on: 5 may 2022
 *      Author: Agus
 */

 int initPassenger(Passenger lista[], int len)
{
    int i;
   for (i=0;i<len;i++)
   {
       lista[i].isEmpty=1;
       lista[i].id=i+1;
   }
 return 0;
}

 //Entrada de datos
 void Passenger_GetName(Passenger list[], int index)
 {
	 Utn_getString("ingrese el nombre",list[index].name);
 }

 void Passenger_GetLastname(Passenger list[], int index)
 {
	 Utn_getString("ingrese el apellido",list[index].lastname);
 }

 void Passenger_GetFlycode(Passenger list[], int index,fly flylist[])
 {
	 int i;
	 int getflycode=0;
	 error:
	 printf("\n");
	 printf("Seleccione el codigo de vuelo\n");
	 for(i=0;i<3;i++)
	 {
		 printf("Opcion %d:\n",i+1);
		 printFlys(flylist,i);
	 }
	 	 Utn_getInt("",0,4,&getflycode);

	 if(getflycode)
	 {
	 	strcpy(list[index].flycode,flylist[getflycode-1].flycode);
	 	system("@cls||clear");
	 }
	 else
	 {
		printf("Opcion Invalida\n");
	 	getch();
	 	goto error;
	 }
 }

 void Passenger_GetPrice(Passenger list[], int index)
 {
	 int i=0;
	 while(i==0)
	 {
		 i=Utn_getFloat("Ingrese el precio del vuelo",0,99999999999,&list[index].Price);
 	 }
 }


 void Get_Passenger(Passenger list[], int index,fly flylist[])
 {

	 Passenger_GetName(list,index);
	 Passenger_GetLastname(list,index);
	 Passenger_GetFlycode(list,index,flylist);
	 Passenger_GetPrice(list,index);
	 Passenger_GetType(list,index);
	 Passenger_GetStatus(list,index);

     list[index].isEmpty=0;
 }

void Passenger_GetType(Passenger list[], int index)
{
	int i=0;
	while(i==0)
	{
		i=Utn_getInt("Ingrese el tipo de pasajero\n1: Menor\n2: Adulto\n3: Adulto Mayor",0,4,&list[index].typePassenger);
	}

}

void Passenger_GetStatus(Passenger list[], int index)
{
	int i=0;
	while(i==0)
	{
		i=Utn_getInt("Ingrese el estado del vuelo\n1: Activo \n2: Suspendido\n3: Cancelado",0,4,&list[index].statusFlight);
	}
}

void Passenger_printType(int type)
{
	switch(type)
	{
	case 1:
		printf("Tipo de Pasajero: Menor\n");
		break;
	case 2:
		printf("Tipo de Pasajero: Adulto\n");
		break;
	case 3:
		printf("Tipo de Pasajero: Adulto Mayor\n");
		break;
	default:
		printf("Ha habido un error en el ingreso de un dato\n");
		break;
	}
}

void Passenger_printStatus(int status)
{
	switch(status)
	{
	case 1:
		printf("Estado de vuelo: Activo\n");
		break;
	case 2:
		printf("Estado de vuelo: Suspendido\n");
		break;
	case 3:
		printf("Estado de vuelo: Cancelado\n");
		break;
	default:
		printf("Ha habido un error en el ingreso de un dato\n");
		break;
	}
}

int find_LastId(Passenger list[],int tam)
{
	int i;
	int Auxid=0;
	for(i=0;i<tam;i++)
	{
		if(list[i].id>Auxid)
		{
			 Auxid=list[i].id;
		}
	}
	return Auxid;
}

 int Passenger_addPassengers(Passenger list[],int tam,fly flylist[])
 {
	 int i;

	 //Buscar un lugar libre
	 for(i=0;i<tam;i++)
	 {
		 if(list[i].isEmpty)
		 {
			 Get_Passenger(list,i,flylist);
			 break;
		 }
	 }
	 return i;
 }

 void Print_Passenger(Passenger list[], int index)
 {
	 printf("ID: %d\n",list[index].id);
	 printf("Apellido: %s\n",list[index].lastname);
	 printf("Nombre: %s\n",list[index].name);
	 printf("Codigo de vuelo: %s\n",list[index].flycode);
	 printf("Precio: %.2f\n",list[index].Price);
	 Passenger_printType(list[index].typePassenger);
	 Passenger_printStatus(list[index].statusFlight);
 }

 int ModifyPassenger(Passenger list[], int index,fly flylist[])
 {
	 int  i;
	 do
	 {
		 system("@cls||clear");

		 printf("\n");
		 printf("****************************************************************\n");
		 printf("Vista previa del Pasajero:\n");
		 printf("\n");
		 Print_Passenger(list,index);
		 printf("\n");
		 printf("****************************************************************\n");
		 printf("\n");
		 printf("Ingrese el campo que desea modificar:\n");
		 printf("1: Nombre\n");
		 printf("2: Apellido\n");
		 printf("3: Codigo de vuelo\n");
		 printf("4: Precio del vuelo\n");
		 printf("5: Salir\n");

		 Utn_getInt("",0,6,&i);

		 system("@cls||clear");

		 switch(i)
		 {
		 	 case 1:
		 		Passenger_GetName(list,index);
		 		 break;
		 	 case 2:
		 		Passenger_GetLastname(list,index);
		 		 break;
		 	 case 3:
		 		Passenger_GetFlycode(list,index,flylist);
		 		 break;
		 	 case 4:
		 		Passenger_GetPrice(list,index);
		 		 break;
		 }
	 }while(i!=5);
	 return i;
 }

 int findPassengerById(Passenger list[],int tam,int id)
 {
	 int i;
	 int Return=-1;
	 for(i=0;i<tam;i++)
	 	 {
	 		 if(list[i].id==id)
	 		 {
	 			 if(list[i].isEmpty==0)
	 			 {
	 				Return=i;
	 				break;
	 			 }
	 		 }
	 	 }
	 	 return Return;
 }

 int Passenger_Search(Passenger list[],int tam)
 {
	 int id=-1;
	 int founded;
	 Utn_getInt("ingrese el Id del Pasajero a buscar:",-1,tam,&id);

	 founded=findPassengerById(list,tam,id);

	 if(founded!=-1)
	 {
		 printf("Pasajero Encontrado\n");
	 }else
	 {
		 printf("Error: Pasajero no Encontrado\n");
	 }
	 getch();
	return founded;
 }

 int Passenger_Modify(Passenger list[],int tam,fly flylist[])
 {
	 int index=-1;
	 while(index==-1)
	 {
		 index=Passenger_Search(list,tam);
		 system("@cls||clear");
	 }
	 ModifyPassenger(list,index,flylist);
	 system("@cls||clear");
	printf("Cambios Aplicados\n");
	getch();
	return index;
 }

 void printPassengers(Passenger list[],int tam)
 {
	 int i;
	 for(i=0;i<tam;i++)
	 {
		 if(list[i].isEmpty==0)
		 {
			 Print_Passenger(list,i);
		 }
		 printf("\n");
	 }
 }

 void Passenger_removePassenger(Passenger list[],int tam)
 {
	 int index;
	 int Eliminar=0;
	 int Cancelar=0;

	 system("@cls||clear");
	 printf("Remover Pasajero:\n");
	 Search:
	 index=Passenger_Search(list,tam);
	 system("@cls||clear");
	 Invalid:
	 Print_Passenger(list,index);
	 printf("\n");
	 printf("\n");
	 printf("¿Desea Eliminar este Pasajero?\n");
	 printf("1_Si\n");
	 printf("2_No\n");

	 //pedir Eliminar
	 Utn_getInt("",0,3,&Eliminar);

	 switch(Eliminar)
	 {
	 case 1:
		 printf("Pasajero Eliminado\n");
		 list[index].isEmpty=1;
		 getch();
		 break;
	 case 2:
		 printf("Desea Cancelar la baja?\n");
		 printf("1_Si\n");
		 printf("2_No\n");
		 Utn_getInt("",0,3,&Cancelar);
		 //pedir Cancelar
		 if(Cancelar==2)
		 {
			 goto Search;
		 }
		 break;
	 default:
		 printf("Opcion invalida\n");
		 goto Invalid;
	 }
 }

//Ordenamiento

 void SwapPassengers(Passenger list[],int Firstindex,int SecIndex)
 {
	 Passenger Auxiliar;

	 Auxiliar=list[Firstindex];
	 list[Firstindex]=list[SecIndex];
	 list[SecIndex]=Auxiliar;
 }

void sortPassengers_ByName(Passenger list[],int tam)
{
	int i;
	int j;

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(strcmp(list[i].lastname,list[i+1].lastname)>0)
			{
				SwapPassengers(list,i,i+1);
			}

		}
	}
}

void sortPassengers_ByNameDecendent(Passenger list[],int tam)
{
	int i;
	int j;

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(strcmp(list[i].lastname,list[i+1].lastname)<0)
			{
				SwapPassengers(list,i,i+1);
			}

		}
	}
}

void sortPassengers_ByIdAscendent(Passenger list[],int tam)
{
	int i;
	int j;

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(list[i].id>list[i+1].id)
			{
					SwapPassengers(list,i,i+1);
			}

		}
	}
}

void sortPassengers_ByIdDescendent(Passenger list[],int tam)
{
	int i;
	int j;

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(list[i].id<list[i+1].id)
			{
				SwapPassengers(list,i,i+1);
			}

		}
	}
}

void sortPassengers_ByTypeAscendent(Passenger list[],int tam)
{
	int i;
	int j;

		for(j=0;j<tam-1;j++)
		{
			for(i=0;i<tam-1;i++)
			{
				if(list[i].typePassenger>list[i+1].typePassenger)
				{
					SwapPassengers(list,i,i+1);
				}

			}
		}
}

void sortPassengers_ByTypeDescendent(Passenger list[],int tam)
{
	int i;
	int j;

		for(j=0;j<tam-1;j++)
		{
			for(i=0;i<tam-1;i++)
			{
				if(list[i].typePassenger<list[i+1].typePassenger)
				{
					SwapPassengers(list,i,i+1);
				}

			}
		}
}

void sortPassengers_ByflycodeAscendent(Passenger list[],int tam)
{
	int i;
	int j;

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(strcmp(list[i].flycode,list[i+1].flycode)>0)
			{
				SwapPassengers(list,i,i+1);
			}

		}
	}
}
void sortPassengers_ByflycodeDescendent(Passenger list[],int tam)
{
	int i;
	int j;

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(strcmp(list[i].flycode,list[i+1].flycode)<0)
			{
				SwapPassengers(list,i,i+1);
			}

		}
	}
}

void sortPassengers_ByTypeAndName(Passenger list[],int tam)
{
	int i;
	int j;

	sortPassengers_ByTypeAscendent(list,tam);

	for(j=0;j<tam-1;j++)
	{
		for(i=0;i<tam-1;i++)
		{
			if(list[i].typePassenger==1 && list[i+1].typePassenger==1)
			{
				if(strcmp(list[i].lastname,list[i+1].lastname)>0)
				{
					SwapPassengers(list,i,i+1);
				}
			}
			if(list[i].typePassenger==2 && list[i+1].typePassenger==2)
			{
				if(strcmp(list[i].lastname,list[i+1].lastname)>0)
				{
					SwapPassengers(list,i,i+1);
				}
			}
			if(list[i].typePassenger==3 && list[i+1].typePassenger==3)
			{
				if(strcmp(list[i].lastname,list[i+1].lastname)>0)
				{
					SwapPassengers(list,i,i+1);
				}
			}

		}
	}
}

void sortPassengers_ByTypeAndNameDecendent(Passenger list[],int tam)
{
		int i;
		int j;

		sortPassengers_ByTypeDescendent(list,tam);

		for(j=0;j<tam-1;j++)
		{
			for(i=0;i<tam-1;i++)
			{
				if(list[i].typePassenger==1 && list[i+1].typePassenger==1)
				{
					if(strcmp(list[i].lastname,list[i+1].lastname)<0)
					{
						SwapPassengers(list,i,i+1);
					}
				}
				if(list[i].typePassenger==2 && list[i+1].typePassenger==2)
				{
					if(strcmp(list[i].lastname,list[i+1].lastname)<0)
					{
						SwapPassengers(list,i,i+1);
					}
				}
				if(list[i].typePassenger==3 && list[i+1].typePassenger==3)
				{
					if(strcmp(list[i].lastname,list[i+1].lastname)<0)
					{
						SwapPassengers(list,i,i+1);
					}
				}

			}
		}
}

 void Passenger_sortPassengers(Passenger list[],int tam)
 {
	 int  i;

	 	 	 select:
	 		 system("@cls||clear");

	 		 printf("\n");

	 		 printf("\n");
	 		 printf("Ingrese el Criterio de ordenamiento:\n");
	 		 printf("\n");
	 		 printf("1: Por apellido (A-Z)\n");
	 		 printf("2: Por Id (Orden default)\n");
	 		 printf("3: Por Tipo de pasajero (Ascendente)\n");
	 		 printf("4: Por Apellido y tipo de pasajero (Ascendente)\n");
	 		 printf("5: Por codigo de vuelo (Ascendente)\n");
	 		 printf("6: Por Tipo de pasajero (Decendente)\n");
	 		 printf("7: Por Apellido y tipo de pasajero (Decendente)\n");
	 		 printf("8: Por Codigo de vuelo (Decendente)\n");
	 		 printf("\n");
	 		 printf("9: Salir\n");


	 		 Utn_getInt("",0,10,&i);

	 		 system("@cls||clear");

	 		 switch(i)
	 		 {
	 		 	 case 1:
	 		 		sortPassengers_ByName(list,tam);
	 		 		 break;
	 		 	 case 2:
	 		 		sortPassengers_ByIdAscendent(list,tam);
	 		 		 break;
	 		 	 case 3:
	 		 		printf("\n");
	 		 		printf("Nota: El criterio de ordenamiento es: 1: Menor, 2: Adulto, 3: Adulto Mayor\n");
	 		 		printf("\n");
	 		 		getch();
	 		 		sortPassengers_ByTypeAscendent(list,tam);
	 		 		 break;
	 		 	 case 4:
	 		 		sortPassengers_ByTypeAndName(list,tam);

	 		 		 break;
	 		 	case 5:
	 		 		sortPassengers_ByflycodeAscendent(list,tam);
	 		 		break;
	 		 	case 6:
	 		 		sortPassengers_ByTypeDescendent(list,tam);
	 		 		break;
	 		 	case 7:
	 		 		sortPassengers_ByTypeAndNameDecendent(list,tam);
	 		 		break;
	 		 	case 8:
	 		 		sortPassengers_ByflycodeDescendent(list,tam);
	 		 		break;
	 		 	case 9:
	 		 		break;
	 		 	default:
	 		 		printf("Opcion invalida\n");
	 		 		getch();
	 		 		goto select;
	 		 		break;
	 		 }

 }

 void Passenger_Set_Default(Passenger list[],int tam)
 {
	 int i=0;

	 for(i=0;i<tam;i++)
	 {
		 if(list[i].isEmpty==1)
		 {
			 //Juan Perez; Adulto; vuelo Activo
			 list[i].isEmpty=0;
			 strcpy(list[i].flycode,"AR7847");
			 list[i].Price=100000;
			 strcpy(list[i].name,"Juan");
			 strcpy(list[i].lastname,"Perez");
			 list[i].statusFlight=1;
			 list[i].typePassenger=2;
			 break;
		 }
	 }

	 for(i=0;i<tam;i++)
	 {
		 if(list[i].isEmpty==1)
		 {
			 //Isabela Lopez; Niño; vuelo Activo
			 list[i].isEmpty=0;
			 strcpy(list[i+1].flycode,"AR7847");
			 list[i].Price=80000;
			 strcpy(list[i].name,"Isabela");
			 strcpy(list[i].lastname,"Lopez");
			 list[i].statusFlight=1;
			 list[i].typePassenger=1;
			 break;
		 }
	 }

	for(i=0;i<tam;i++)
	{
		if(list[i].isEmpty==1)
		{
			//Artuto Illia; Adulto Mayor; vuelo Cancelado
			list[i].isEmpty=0;
			strcpy(list[i].flycode,"AR7454");
			list[i].Price=120000;
			strcpy(list[i].name,"Artuto");
			strcpy(list[i].lastname,"Illia");
			list[i].statusFlight=3;
			list[i].typePassenger=3;
			break;
		}
	}
 }

 void set_Flycodes(fly list[])
 {
	 strcpy(list[0].flycode,"AR4578");
	 strcpy(list[0].description,"Vuelo sin escalas");
	 strcpy(list[0].destination,"Cordoba");
	 strcpy(list[0].fecha,"06/07/2022");

	 strcpy(list[1].flycode,"AR7847");
	 strcpy(list[1].description,"Vuelo sin escalas");
	 strcpy(list[1].destination,"Bariloche");
	 strcpy(list[1].fecha,"04/08/2022");

	 strcpy(list[2].flycode,"AR7454");
	 strcpy(list[2].description,"Vuelo con escala en Corrientes");
	 strcpy(list[2].destination,"Jujuy");
	 strcpy(list[2].fecha,"18/08/2022");
 }

 void printFlys(fly list[],int index)
 {
	 printf("\n");
	 printf("Codigo de vuelo: %s\n",list[index].flycode);
	 printf("Destino: %s\n",list[index].destination);
	 printf("Descripcion: %s\n",list[index].description);
	 printf("Fecha: %s\n",list[index].fecha);
	 printf("\n");
 }
