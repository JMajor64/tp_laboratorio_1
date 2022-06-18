#include "Passenger.h"
/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#define TAM 3
//print

/*Passenger_newParametros()
 * \brief Crea una variable tipo Passenger en memoria dinamica y le asigna valor
 * \param idStr, nombreStr, apellidoStr, PrecioStr, flyCodeStr, tipoPasajeroStr y status almacenan cada uno de los campos de una estructura tipo Passenger
 * \ return Retorna un puntero a un Passenger en memoria dinamica
 * */

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* PrecioStr,char* flyCodeStr,char* tipoPasajeroStr,char* status)
{
	Passenger aux;
	Passenger* new;
		//convertir datos;
		aux.id=atoi(idStr);
		aux.precio=atof(PrecioStr);
		aux.tipoPasajero=TypePassenger(tipoPasajeroStr);
		strcpy(aux.nombre,nombreStr);
		strcpy(aux.apellido,apellidoStr);
		strcpy(aux.codigoVuelo,flyCodeStr);
		strcpy(aux.status,status);

		//introducir datos
		new=Passenger_NonStrNewParametros(aux);

	return new;
}

/*Passenger_NonStrNewParametros()
 * \brief Crea una variable tipo Passenger en memoria dinamica y le asigna valor
 * \param aux Es una variable tipo Passenger que guarda los valores a asignar al Passenger en memoria dinamica
 * \return Retona un Puntero a Passenger
 * */

Passenger* Passenger_NonStrNewParametros(Passenger aux)
{
	Passenger* new;
	new=Passenger_new();
	if(new!=NULL)
	{
		Passenger_setId(new,aux.id);
		Passenger_setNombre(new,aux.nombre);
		Passenger_setApellido(new,aux.apellido);
		Passenger_setCodigoVuelo(new,aux.codigoVuelo);
		Passenger_setTipoPasajero(new,aux.tipoPasajero);
		Passenger_setPrecio(new,aux.precio);
		Passenger_setStatus(new,aux.status);
	}
	else{
		printf("Error, intente mas tarde\n");
	}
	return new;
}

/*TypePassenger()
 * \brief Asigna a un entero al parametro tipoPasajero mediante la cadena que recibe por parametro
 * \param typeStr
 * \return Retona el entero equivalente al tipo
 * */
int TypePassenger(char *typeStr)
{
	int typeInt=0;
	if(strcmp(typeStr,"FirstClass") == 0)
	{
		typeInt=1;
	}else
	{
		if(strcmp(typeStr,"ExecutiveClass") == 0)
		{
			typeInt=2;
		}
		else
		{
			if(strcmp(typeStr,"EconomyClass") == 0)
			{
				typeInt=3;
			}
		}
	}
	return typeInt;
}

/*printType()
 * \brief imprime un tipoPasajero en forma de caracteres
 * \param TypeInt entero equivalente a la cadena del tipoPasajero
 * */
void printType(int TypeInt)
{
	switch(TypeInt)
	{
	case 1:
		printf("Tipo: FirstClass\n");
		break;
	case 2:
		printf("Tipo: ExecutiveClass\n");
		break;
	case 3:
		printf("Tipo: EconomyClass\n");
		break;
	default:
		printf("Error, Tipo invalido\n");
		break;
	}
}

/*Passenger_getFromUser()
 * \brief Pide al usuario los datos y los asigna a una variable Passenger
 * \return Retona una variable tipo Passenger con los valores asignados
 * */
Passenger Passenger_getFromUser()
{
	Passenger aux;
	char auxStrStatus[10];
	int auxStatus;
	int validate=0;


	while(validate==0){
		validate=Utn_getString("ingrese el Nombre",aux.nombre,sizeof(aux.nombre));
	}
	validate=0;

	while(validate==0){
		validate=Utn_getString("ingrese el Apellido",aux.apellido,sizeof(aux.apellido));
	}
	validate=0;

	while(validate==0){
		validate=Utn_getString("ingrese el codigo de vuelo (8 caracteres)",aux.codigoVuelo,sizeof(aux.codigoVuelo));
	}
	validate=0;

	while(validate==0){
	printf("Ingrese el tipo de pasajero: \n");
	printf("1 ");
	printType(1);
	printf("2 ");
	printType(2);
	printf("3 ");
	printType(3);
	validate=Utn_getInt("",0,4,&aux.tipoPasajero);
	}
	validate=0;

	while(validate==0){
		validate=Utn_getFloat("ingrese el precio",0,9999999,&aux.precio);
	}
	validate=0;

	while(validate==0){
		Passenger_GetStatusStr(1,auxStrStatus);
		printf("1: %s\n",auxStrStatus);
		Passenger_GetStatusStr(2,auxStrStatus);
		printf("2: %s\n",auxStrStatus);
		validate=Utn_getInt("ingrese el Estado",0,3,&auxStatus);
		Passenger_GetStatusStr(auxStatus,aux.status);
	}

	return aux;
}
/*Passenger_new ()
 * \brief Crea un Passenger en memoria dinamica
 * \return Retorna un puntero a un Passenger en memoria dinamica
 * */
Passenger* Passenger_new()
{
	Passenger* new=(Passenger*) malloc(sizeof(Passenger));

	return new;
}

//SETERS

/* Passenger_setId()
 * \brief Asigna un valor al campo Id de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param id entero a asignar al campo Id del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setId(Passenger* this,int id)
{
	int retorno=0;

	if(this!=NULL && id>0)
	{
		(*this).id=id;
		retorno=1;
	}

	return retorno;
}

/* Passenger_setNombre()
 * \brief Asigna un valor al campo nombre de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param nombre cadena a asignar al campo nombre del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL && strlen(nombre)<sizeof((*this).nombre))
	{
			strcpy((*this).nombre,nombre);
			retorno=1;
	}

	return retorno;
}
/* Passenger_setApellido()
 * \brief Asigna un valor al campo Apellido de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param apellido cadena a asignar al campo apellido del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=0;
	if(this!=NULL && strlen(apellido)<sizeof((*this).apellido))
	{
			strcpy((*this).apellido,apellido);
			retorno=1;
	}

	return retorno;
}
/* Passenger_setCodigoVuelo()
 * \brief Asigna un valor al campo codigoVuelo de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param codigoVuelo cadena a asignar al campo codigoVuelo del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=0;

	if(this!=NULL && strlen(codigoVuelo)<sizeof((*this).codigoVuelo))
	{
			strcpy((*this).codigoVuelo,codigoVuelo);
			retorno=1;
	}

	return retorno;
}
/* Passenger_setTipoPasajero()
 * \brief Asigna un valor al campo tipoPasajero de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param tipoPasajero entero a asignar al campo tipoPasajero del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno=0;

	if(this!=NULL && tipoPasajero < 4)
	{
		(*this).tipoPasajero=tipoPasajero;
		retorno=1;
	}

	return retorno;
}
/* Passenger_setPrecio()
 * \brief Asigna un valor al campo precio de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param precio float a asignar al campo precio del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=0;

	if(this!=NULL && precio > 1000)
	{
		(*this).precio=precio;
		retorno=1;
	}

	return retorno;
}
/* Passenger_setStatus()
 * \brief Asigna un valor al campo status de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param status char a asignar al campo status del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setStatus(Passenger* this,char* Status)
{
	int retorno=0;

	if(this!=NULL && strlen(Status)<sizeof((*this).status))
	{
			strcpy((*this).status,Status);
			retorno=1;
	}

	return retorno;
}
/* Passenger_setIntType()
 * \brief Asigna un valor al campo type de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param int type a asignar al campo type del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Passenger_setIntType(Passenger* this,int type)
{
	int retorno=0;

	if(this!=NULL && type>0)
	{
		(*this).tipoPasajero=type;
		retorno=1;
	}

	return retorno;
}

//GETERS


/* Passenger_getId()
 * \brief Obtiene el valor del campo id de un Passenger
 * \param this puntero a Passenger
 * \param id entero que guarda el id obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=0;
	if(this!=NULL && id!=NULL)
	{
		*id=(*this).id;
		retorno=1;
	}
	return retorno;
}
/* Passenger_getNombre()
 * \brief Obtiene el valor del campo nombre de un Passenger
 * \param this puntero a Passenger
 * \param nombre char que guarda el nombre obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,(*this).nombre);
		retorno=1;
	}
	return retorno;
}
/* Passenger_getApellido()
 * \brief Obtiene el valor del campo apellido de un Passenger
 * \param this puntero a Passenger
 * \param apellido char que guarda el apellido obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=0;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,(*this).apellido);
		retorno=1;
	}
	return retorno;
}

/* Passenger_getCodigoVuelo()
 * \brief Obtiene el valor del campo codigoVuelo de un Passenger
 * \param this puntero a Passenger
 * \param codigoVuelo char que guarda el codigoVuelo obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,(*this).codigoVuelo);
		retorno=1;
	}
	return retorno;
}
/* Passenger_getTipoPasajero()
 * \brief Obtiene el valor del campo tipoPasajero de un Passenger
 * \param this puntero a Passenger
 * \param tipoPasajero entero que guarda el tipoPasajero obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno=0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero=(*this).tipoPasajero;
		retorno=1;
	}
	return retorno;
}
/* Passenger_getPrecio()
 * \brief Obtiene el valor del campo precio de un Passenger
 * \param this puntero a Passenger
 * \param precio float que guarda el precio obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio=(*this).precio;
		retorno=1;
	}
	return retorno;
}
/* Passenger_getStatus()
 * \brief Obtiene el valor del campo status de un Passenger
 * \param this puntero a Passenger
 * \param status char que guarda el status obtenido
 * \return entero 1 si funciona, 0 si falla
 * */
int Passenger_getStatus(Passenger* this,char* status)
{
	int retorno=0;
	if(this!=NULL && status!=NULL)
	{
		strcpy(status,(*this).status);
		retorno=1;
	}
	return retorno;
}
/* Passenger_getId()
 * \brief Obtiene char equivalente al campo Type de Passenger
 * \param this puntero a Passenger
 * \param Type char* que guarda el Type obtenido
 * */
void GetTypeStr(Passenger* this,char* Type)
{
	switch(this->tipoPasajero)
	{
	case 1:
		strcpy(Type,"FirstClass");
		break;
	case 2:
		strcpy(Type,"ExecutiveClass");
		break;
	case 3:
		strcpy(Type,"EconomyClass");
		break;
	}
}
/* Passenger_printPassenger()
 * \brief Imprime un Passenger
 * \param aux Passenger* a imprimir
 * */
void Passenger_printPassenger(Passenger* aux)
{
	char auxType[16];
	GetTypeStr(aux,auxType);
	printf("%-6d||%-16s %-12s\t||%-7.2f\t||%-6s\t||%-14s\t||%s\n",aux->id,aux->nombre,aux->apellido,aux->precio,aux->codigoVuelo,auxType,aux->status);
	//printf("%s\n",aux->apellido);
}
/* Passenger_GetStatusStr()
 * \brief Obtiene la cadena a asignar al parametro status
 * \param statusInt int que determina el status
 * \param StatusStr char* donde se guarda el status
 * */
void Passenger_GetStatusStr(int statusInt,char* StatusStr)
{
	switch(statusInt)
	{
	case 1:
		strcpy(StatusStr,"En Horario");
		break;
	case 2:
		strcpy(StatusStr,"Aterrizado");
		break;
	}
}
/* Passenger_Modify()
 * \brief Pregunta al usuario que parametros va a modificar
 * \param aux Passenger* a modificar
 * */
void Passenger_Modify(Passenger* aux)
{
	int  option;
	int valid;

	//////auxiliares////////
	char auxName[50];
	char auxLstName[50];
	char auxFlycode[10];
	float auxPrice;
	int auxInt;
	char auxStatus[11];
	///////////////////////
	do
	{
		valid=0;
		system("@cls||clear");

		printf("\n");
		printf("Vista previa del Pasajero:\n");
		printf("****************************************************************************\n");
		printf("\n");
		Passenger_printPassenger(aux);
		printf("\n");
		printf("****************************************************************************\n");
		printf("\n");
		printf("Ingrese el campo que desea modificar:\n");
		printf("1: Nombre\n");
		printf("2: Apellido\n");
		printf("3: Codigo de vuelo\n");
		printf("4: Precio\n");
		printf("5: Tipo de pasajero\n");
		printf("6: Estado de vuelo\n");
		printf("7: Salir\n");

		Utn_getInt("",0,8,&option);

		system("@cls||clear");

		switch(option)
		{
			case 1:

				while(valid==0)
				{
					valid=Utn_getString("Ingrese el nombre",auxName,sizeof(aux->nombre));
				}
				Passenger_setNombre(aux,auxName);
			break;
			case 2:

				while(valid==0)
				{
					valid=Utn_getString("Ingrese el apellido",auxLstName,sizeof(aux->apellido));
				}
				Passenger_setApellido(aux,auxLstName);
			break;
			case 3:
				while(valid==0)
				{
					valid = Utn_getString("Ingrese codigo de vuelo",auxFlycode,sizeof(aux->codigoVuelo));
				}
				Passenger_setCodigoVuelo(aux,auxFlycode);
			break;
			case 4:
				while(valid==0)
				{
					valid = Utn_getFloat("Ingrese el precio",0,9999999,&auxPrice);
				}
				Passenger_setPrecio(aux,auxPrice);
			break;
			case 5:

				while(valid==0)
				{
					printf("Ingrese el Tipo de pasajero\n");
					printf("1:");
					printType(1);
					printf("2:");
					printType(2);
					printf("3:");
					printType(3);
					valid = Utn_getInt(" ",0,4,&auxInt);
				}
				Passenger_setIntType(aux,auxInt);
				break;
			case 6:

				while(valid==0)
				{
					printf("Ingrese el Estado\n");
					printf("1: En Horario\n");
					printf("2: Aterrizado\n");
					valid = Utn_getInt("",0,3,&auxInt);
				}
				Passenger_GetStatusStr(auxInt,auxStatus);
				Passenger_setStatus(aux,auxStatus);

				break;
		}
	}while(option!=7);
			
}


/* Passenger_delete()
 * \brief Pregunta al usuario si desea eliminar el Passenger* que recibe por parametro
 * \param delete Passenger* a eliminar
 * \return int opcion elegida
 * */
int Passenger_delete(Passenger* delete)
{
	int  option;
	GetOption:
	system("@cls||clear");

	printf("\n");
	printf("Vista previa del Pasajero:\n");
	printf("****************************************************************************\n");
	printf("\n");
	Passenger_printPassenger(delete);
	printf("\n");
	printf("****************************************************************************\n");
	printf("\n");
	printf("Desea eliminar este pasajero?\n");
	printf("1: Si\n");
	printf("2: No\n");

	Utn_getInt("",0,3,&option);

	switch(option)
	{
		case 1:
			Passenger_free(delete);
			printf("Pasajero eliminado correctamente\n");
		break;
		case 2:
			printf("Pasajero no eliminado\n");
		break;
		default:
		goto GetOption;
		break;
	}

	return option;
}
/* Passenger_sortByApellido()
 * \brief crietrio de ordenamiento para la funcion ll_sort() mediante campo apellido
 * \param PassengerA void* que apunta a un Passenger
 * \param PassengerB void* que apunta a un Passenger
 * \return int positivo o negativo dependiendo la comparacion
 * */
int Passenger_sortByApellido(void* PassengerA,void* PassengerB)
{
	int retorno=-1;
	char auxApellidoA[50];
	char auxApellidoB[50];
	{
		if(PassengerA != NULL && PassengerB != NULL)
		{
			Passenger_getApellido(PassengerA,auxApellidoA);
			Passenger_getApellido(PassengerB,auxApellidoB);
			retorno=strcmp(auxApellidoA,auxApellidoB);
		}
	}
	return retorno;
}

/* Passenger_sortById()
 * \brief crietrio de ordenamiento para la funcion ll_sort() mediante campo id
 * \param PassengerA void* que apunta a un Passenger
 * \param PassengerB void* que apunta a un Passenger
 * \return int positivo o negativo dependiendo la comparacion
 * */
int Passenger_sortById(void* PassengerA,void* PassengerB)
{
	int retorno=-1;
	int auxIdA=0;
	int auxIdB=0;
	Passenger* AuxA;
	Passenger* AuxB;
	AuxA=(Passenger*)PassengerA;
	AuxB=(Passenger*)PassengerB;

	if(PassengerA != NULL && PassengerB != NULL)
	{
		Passenger_getId(AuxA,&auxIdA);
		Passenger_getId(AuxB,&auxIdB);
		if(auxIdA>auxIdB)
		{
			retorno=1;
		}else{
			retorno=-1;
		}

	}
	return retorno;
}

/* Passenger_free()
 * \brief elimina un Passenger de la memoria dinamica
 * \param delete Passenger* a eliminar
 * */
 void Passenger_free(Passenger* delete)
 {
	free(delete);
 }

 /* Passenger_SortCriteria()
  * \brief Pide al usuario el criterio de ordenamiento
  * \param pArrayListPassenger LinkedList*
  * */
 void Passenger_SortCriteria(LinkedList* pArrayListPassenger)
 {
	 int  option;
	 int testSort;

	 	GetOption:
	 	system("@cls||clear");
	 	printf("\n");
	 	printf("Seleccione el criterio de orden:\n");
	 	printf("\n");
	 	printf("1: Ordenar por Id (Orden default)\n");
	 	printf("2: Ordenar por Apellido (ascendente)\n");

	 	Utn_getInt("",0,3,&option);

	 	switch(option)
	 	{
	 		case 1:
	 			printf("Ordenando pasajeros, por favor espere...\n");
	 			testSort=ll_sort(pArrayListPassenger,Passenger_sortById,1);
	 			if(testSort==0)
	 			{
	 				printf("\n");
	 				printf("Pasajeros ordenados correctamente\n");
	 				system("pause");
	 			}
	 		break;
	 		case 2:
	 			printf("Ordenando pasajeros, por favor espere...\n");
	 			testSort=ll_sort(pArrayListPassenger,Passenger_sortByApellido,1);
	 			if(testSort==0)
	 			{
	 				printf("\n");
	 				printf("Pasajeros ordenados correctamente\n");
	 				system("pause");
	 			}
	 		break;
	 		default:
	 		goto GetOption;
	 		break;
	 	}

 }


/*FiltrarPassengers
 * \brief filtra pasajeros por tipo
 * \param this Passenger
 * */
 int Passenger_filtrarPorClase1(void* this)
 {
     int retorno = 0;
     if(this != NULL)
     {
    	 Passenger* Aux;
		 Aux=(Passenger*)this;
      if(Aux->tipoPasajero == 1){
         retorno = 1;
      }

     }
     return retorno;
 }

 /*FiltrarPassengers
  * \brief filtra pasajeros por tipo
  * \param this Passenger
  * */
  int Passenger_filtrarPorClase2(void* this)
  {
      int retorno = 0;
      if(this != NULL)
      {
    	  Passenger* Aux;
    	  Aux=(Passenger*)this;

       if(Aux->tipoPasajero == 2){
          retorno = 1;
       }

      }
      return retorno;
  }
  /*FiltrarPassengers
   * \brief filtra pasajeros por tipo
   * \param this Passenger
   * */
   int Passenger_filtrarPorClase3(void* this)
   {
       int retorno = 0;
       if(this != NULL)
       {
    	   Passenger* Aux;
    	   Aux=(Passenger*)this;
        if(Aux->tipoPasajero == 3){
           retorno = 1;
        }

       }
       return retorno;
   }

 /* calcularPrecioFinal
  * \brief Calcula el iva al precio del pasaje
  * \param this Passenger*
  * */
 void calcularPrecioFinal(void* this)
 {
     if(this != NULL)
     {
    	 Passenger* Aux;
    	 Aux=(Passenger*)this;
    	 float auxPrice;
         float iva;
         Passenger_getPrecio(Aux,&auxPrice);
         iva= auxPrice * IVA;
         iva = iva/100;
         auxPrice=auxPrice+iva;
         Passenger_setPrecio(Aux,auxPrice);

     }
     return;
 }




