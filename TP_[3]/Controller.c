#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE * pFile;
	if(ll_len(pArrayListPassenger)!=-1)
	{
		recalculateId(pArrayListPassenger,calulate_TextLastId(path));
	}

	pFile = fopen (path, "r");
	parser_PassengerFromText(pFile,pArrayListPassenger);
	fclose(pFile);
	ll_sort(pArrayListPassenger,Passenger_sortById,1);

    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE * pFile;
	if(ll_len(pArrayListPassenger)!=-1)
	{
		recalculateId(pArrayListPassenger,calulate_BinaryLastId(path));
	}

	pFile=fopen(path,"rb");
	parser_PassengerFromBinary(pFile,pArrayListPassenger);
	fclose(pFile);
	ll_sort(pArrayListPassenger,Passenger_sortById,1);

    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	Passenger* new;
	Passenger aux;

	aux = Passenger_getFromUser();
	Passenger_setId(&aux,calculate_NewId(pArrayListPassenger));
	new=Passenger_NonStrNewParametros(aux);
	if(new!=NULL)
	{
		ll_add(pArrayListPassenger,new);
		retorno=1;
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aux;
	int len;
	int idS;
	int valid=0;
	len=ll_len(pArrayListPassenger);

	while(valid==0)
	{
		valid=Utn_getInt("ingrese el Id del pasajero",0,len+1,&idS);
		if(valid==0)
		{
			printf("\n");
			printf("Error, ingrese un Id valido\n");
			printf("\n");
		}
	}

	aux=ll_get(pArrayListPassenger,idS-1);

	if(aux!=NULL)
	{
		Passenger_Modify(aux);
	}
	else{
		printf("Error, pasajero no encontrado\n");
		system("pause");
	}


    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aux;
	int len;
	int idS;
	int auxIndex;
	int valid=0;
	len=ll_len(pArrayListPassenger);

	while(valid==0)
	{
		valid=Utn_getInt("ingrese el Id del pasajero",0,len+1,&idS);
		if(valid==0)
		{
			printf("\n");
			printf("Error, ingrese un Id valido\n");
			printf("\n");
		}
	}
	aux=ll_get(pArrayListPassenger,idS-1);
	if(aux!=NULL)
	{
		auxIndex=ll_indexOf(pArrayListPassenger,aux);
		valid=Passenger_delete(aux);
		
		switch(valid)
		{
			case 1:
				ll_pop(pArrayListPassenger,auxIndex);
			break;

			case 2:
			break;
		}
	}
	
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int len;
	int i;
	Passenger* aux;
	len=ll_len(pArrayListPassenger);
	system("@cls||clear");
	printf("Id\tNombre \t\t  Apellido \t  Precio \t  Flycode \t Tipo de pasajero \t Estado\n");
	for(i=0;i<len;i++)
	{
		aux=ll_get(pArrayListPassenger,i);
		if(aux!=NULL)
		{
			Passenger_printPassenger(aux);
		}
		else{
			printf("ERROR\n");
			system("pause");
		}
	}
	system("pause");
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{

	 Passenger_SortCriteria(pArrayListPassenger);

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,int flag)
{
	int retorno=0;
	FILE* pFile;
	if(flag==1)
	{
		pFile=fopen(path,"w");
	}else{
		pFile=fopen(path,"a");

		recalculateId(pArrayListPassenger,calulate_TextLastId(path));

	}if(pFile!=NULL)
	{
		int len;

				len=ll_len(pArrayListPassenger);
				if(len!=-1)
				{
					printf("Guardando pasajeros, por favor espere...\n");
					ll_sort(pArrayListPassenger,Passenger_sortById,1);
					Passenger* aux;
					int auxId;
					char name[50];
					char lstname[50];
					float auxprice;
					char flycode[10];
					char auxTypeStr[16];
					char status[16];

					if(flag==1)
					{
						fprintf(pFile,"Id, Name, Lastname, Price, Flycode, typePassenger, StatusFlyght\n");
					}
					int i;
					for(i=0;i<len;i++)
					{
						aux=ll_get(pArrayListPassenger,i);

						Passenger_getId(aux,&auxId);
						Passenger_getNombre(aux,name);
						Passenger_getApellido(aux,lstname);
						Passenger_getCodigoVuelo(aux,flycode);
						GetTypeStr(aux,auxTypeStr);
						Passenger_getPrecio(aux,&auxprice);
						Passenger_getStatus(aux,status);

						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,name,lstname,auxprice,flycode,auxTypeStr,status);
					}

				}

	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger,int flag)
{
	int retorno=0;

	FILE* pFile;
	if(flag==1)
	{
		pFile=fopen(path,"wb");
	}else{
		pFile=fopen(path,"a");
		recalculateId(pArrayListPassenger,calulate_BinaryLastId(path));
	}

	if(pFile!=NULL)
	{
		int len;
		len=ll_len(pArrayListPassenger);
		printf("Guardando pasajeros, por favor espere...\n");
		ll_sort(pArrayListPassenger,Passenger_sortById,1);
		if(len>0)
		{
			Passenger* aux;
			Passenger* auxLst;

			int i;
			for(i=0;i<len;i++)
			{
				aux=ll_get(pArrayListPassenger,i);
				if(aux!=NULL && aux!=auxLst)
				{
					fwrite(aux,sizeof(Passenger),1,pFile);
				}
				auxLst=aux;
			}

		}

	}
	else
	{
		printf("Error al guardar el archivo\n");
	}
	fclose(pFile);
    return retorno;
}


/* ()
 * \brief calcula el id a asignar a un nuevo Passenger
 * \param pArrayListPassenger LinkedList*
 * \return int Id a asignar
 * */
int calculate_NewId(LinkedList* pArrayListPassenger)
{
	int len;
	len=ll_len(pArrayListPassenger);
	if(len==-1)
	{
		len=0;
	}
	len++;
	return len;
}

/* freeAll()
 * \brief Libera toda la memoria dinamica usada durante la ejecucion del programa
 * \param pArrayListPassenger LinkedList*
 * */
void freeAll(LinkedList* pArrayListPassenger)
{
	int len;
	int i;
	Passenger* aux;

	len=ll_len(pArrayListPassenger);
	for(i=0;i<len;i++)
	{
		aux=ll_get(pArrayListPassenger,i);
		if(aux!=NULL)
		{
			Passenger_free(aux);
		}
	}
	ll_clear(pArrayListPassenger);
	ll_deleteLinkedList(pArrayListPassenger);
}




/*recalculateId ()
 * \brief Reasigna valores de id a los Passenger
 * \param pArrayListPassenger LinkedList*
 * \param LastId int ultimo id de la lista a cargar
 * */
void recalculateId(LinkedList* pArrayListPassenger, int LastId)
{
	int auxId;
	Passenger* aux;
	auxId=LastId;
	auxId++;
	int len,i;
	len=ll_len(pArrayListPassenger);
	for(i=0;i<len;i++)
	{
		aux=ll_get(pArrayListPassenger,i);
		if(aux!=NULL)
		{
			if(Passenger_setId(aux,auxId))
			{
				auxId++;
			}
			else{
				printf("Error modificando\n");
				system("pause");
			}
		}
	}

}

/* calulate_BinaryLastId()
 * \brief Calcula el ultimo id en el archivo binario
 * \param path char* con el nombre del archivo
 * \return int ultimo Id
 * */
int calulate_BinaryLastId(char* path)
{
	int retorno=-1;
	//abrir modo bin, pisar la lista en aux y calcular el ultimo id
	//Uso: salvar en texto/binario datos nuevos sin pisar los previos

	Passenger aux;
	FILE* pFile;

	pFile=fopen(path,"rb");
	if(pFile!=NULL)
	{
		while(!feof(pFile))
			{
				fread(&aux,sizeof(Passenger),1,pFile);
			}
		retorno=aux.id;

	}
	fclose(pFile);
	return retorno;
}
/* calulate_TextLastId()
 * \brief Calcula el ultimo id en el archivo de texto
 * \param path char* con el nombre del archivo
 * \return int ultimo Id
 * */
int calulate_TextLastId(char* path)
{
	int retorno=-1;
	char auxId[8];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[20];
	char auxFlycode[10];
	char auxStatus[14];
	char auxType[16];
	//abrir modo bin, pisar la lista en aux y calcular el ultimo id
	//Uso: salvar en texto/binario datos nuevos sin pisar los previos

	Passenger* aux;
	FILE* pFile;

	pFile=fopen(path,"r");
	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFlycode,auxType,auxStatus);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFlycode,auxType,auxStatus);

			aux=Passenger_newParametros(auxId,auxNombre,auxApellido,auxPrecio,auxFlycode,auxType,auxStatus);


		}
		Passenger_getId(aux,&retorno);

	}
	fclose(pFile);
	return retorno;
}


