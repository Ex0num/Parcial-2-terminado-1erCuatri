	/*
	 * PosicionArancelaria.c
	 *
	 *  Created on: 19 jun. 2021
	 *      Author: gabil
	 */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "Producto.h"
	#include "PosicionArancelaria.h"
	#include "utn.h"

	int print_posicionArancelaria (PosicionArancelaria* this)
	{
		int retorno = -1;

		if (this != NULL)
		{
			printf ("\nID:(%d),NOMENCLADOR:(%s),PORCENTAJE SEGURO:(%.2f),PORCENTAJE IMPORTANCION:(%.2f), PORCENTAJE TASA-ESTADISTICA:(%.2f), TIPO-LICENCIA:(%d)\n",this->idPosicionArancelaria,this->nomenclador,this->porcentajeSeguro,this->porcentajeImportacion,this->porcentajeTasaEstadistica,this->tipoLicencia);
			retorno = 0;
		}

		return retorno;
	}

	/*
	 *
	 * //Convierto el id a char para usarlo como key
			char auxKey[CHARACTERS_LEN];
			snprintf(auxKey,sizeof(auxKey),"%d",id);

			PosicionArancelaria pPosicionArancelaria;
			pPosicionArancelaria = dict_get (pListaPosicionesArancelarias,auxKey)
	 *
	 */

	int pArancelaria_setAll (PosicionArancelaria* this, int id, char* nomenclador, float porcentajeSeguro, float porcentajeImportacion, float porcentajeTasaEstadistica, int tipoLicencia)
	{
		int retorno = -1;

		if (this != NULL && id > 0 && nomenclador != NULL && porcentajeSeguro >= 0 && porcentajeImportacion >= 0 && porcentajeTasaEstadistica >= 0 && tipoLicencia >= 0)
		{
			retorno = -2;

			int resultadoSetterId;
			int resultadoSetterNomenclador;
			int resultadoSetterPorcentajeSeguro;
			int resultadoSetterPorcentajeImportacion;
			int resultadoSetterPorcentajeTasaEstadistica;
			int resultadoSetterTipoLicencia;

			resultadoSetterId = pArancelaria_setId (this,id);
			resultadoSetterNomenclador = pArancelaria_setNomenclador (this,nomenclador);
			resultadoSetterPorcentajeSeguro = pArancelaria_setPorcentajeSeguro (this,porcentajeSeguro);
			resultadoSetterPorcentajeImportacion = pArancelaria_setPorcentajeImportacion (this,porcentajeImportacion);
			resultadoSetterPorcentajeTasaEstadistica = pArancelaria_setPorcentajeTasaEstadistica (this,porcentajeTasaEstadistica);
			resultadoSetterTipoLicencia = pArancelaria_setTipoLicencia(this,tipoLicencia);


			if (resultadoSetterId == 0 && resultadoSetterNomenclador == 0 && resultadoSetterPorcentajeSeguro == 0 && resultadoSetterPorcentajeImportacion == 0 && resultadoSetterPorcentajeTasaEstadistica == 0 && resultadoSetterTipoLicencia == 0)
			{
				retorno = 0;
			}

		}

		return retorno;
	}

	int pArancelaria_setAllTxt (PosicionArancelaria* this, char* id, char* nomenclador, char* porcentajeSeguro, char* porcentajeImportacion, char* porcentajeTasaEstadistica, char* tipoLicencia)
	{
		int retorno = -1;

		if (this != NULL && id != NULL && nomenclador != NULL && porcentajeSeguro != NULL && porcentajeImportacion != NULL && porcentajeTasaEstadistica != NULL && tipoLicencia != NULL)
		{
			retorno = -2;

			int resultadoSetterIdTxt;
			int resultadoSetterNomencladorTxt;
			int resultadoSetterPorcentajeSeguroTxt;
			int resultadoSetterPorcentajeImportacionTxt;
			int resultadoSetterPorcentajeTasaEstadisticaTxt;
			int resultadoSetterTipoLicenciaTxt;

			resultadoSetterIdTxt = pArancelaria_setIdTxt (this,id);
			resultadoSetterNomencladorTxt = pArancelaria_setNomenclador (this,nomenclador);
			resultadoSetterPorcentajeSeguroTxt = pArancelaria_setPorcentajeSeguroTxt (this,porcentajeSeguro);
			resultadoSetterPorcentajeImportacionTxt = pArancelaria_setPorcentajeImportacionTxt (this,porcentajeImportacion);
			resultadoSetterPorcentajeTasaEstadisticaTxt = pArancelaria_setPorcentajeTasaEstadisticaTxt (this,porcentajeTasaEstadistica);
			resultadoSetterTipoLicenciaTxt = pArancelaria_setTipoLicenciaTxt(this,tipoLicencia);


			if (resultadoSetterIdTxt == 0 && resultadoSetterNomencladorTxt == 0 && resultadoSetterPorcentajeSeguroTxt == 0 && resultadoSetterPorcentajeImportacionTxt == 0 && resultadoSetterPorcentajeTasaEstadisticaTxt == 0 && resultadoSetterTipoLicenciaTxt == 0)
			{
				retorno = 0;
			}

		}

		return retorno;
	}

	int pArancelaria_getAll (PosicionArancelaria* this, int* id, char* nomenclador, float* porcentajeSeguro, float* porcentajeImportacion, float* porcentajeTasaEstadistica, int* tipoLicencia)
	{
		int retorno = -1;

		if (this != NULL && id > 0 && nomenclador != NULL && porcentajeSeguro >= 0 && porcentajeImportacion >= 0 && porcentajeTasaEstadistica >= 0 && tipoLicencia != NULL)
		{
			retorno = -2;

			int resultadoGetterId;
			int resultadoGetterNomenclador;
			int resultadoGetterPorcentajeSeguro;
			int resultadoGetterPorcentajeImportacion;
			int resultadoGetterPorcentajeTasaEstadistica;
			int resultadoGetterTipoLicencia;

			resultadoGetterId = pArancelaria_getId (this,id);
			resultadoGetterNomenclador = pArancelaria_getNomenclador (this,nomenclador);
			resultadoGetterPorcentajeSeguro = pArancelaria_getPorcentajeSeguro (this,porcentajeSeguro);
			resultadoGetterPorcentajeImportacion = pArancelaria_getPorcentajeImportacion (this,porcentajeImportacion);
			resultadoGetterPorcentajeTasaEstadistica = pArancelaria_getPorcentajeTasaEstadistica (this,porcentajeTasaEstadistica);
			resultadoGetterTipoLicencia = pArancelaria_getTipoLicencia(this,tipoLicencia);

			if (resultadoGetterId == 0 && resultadoGetterNomenclador == 0 && resultadoGetterPorcentajeSeguro == 0 && resultadoGetterPorcentajeImportacion == 0 && resultadoGetterPorcentajeTasaEstadistica == 0 && resultadoGetterTipoLicencia == 0)
			{
				retorno = 0;
			}
			else
			{
				printf (" %d -  %d -  %d - %d - %d -  %d -",resultadoGetterId,resultadoGetterNomenclador,resultadoGetterPorcentajeSeguro,resultadoGetterPorcentajeImportacion,resultadoGetterPorcentajeTasaEstadistica,resultadoGetterTipoLicencia);
			}

		}

		return retorno;
	}

	int pArancelaria_getAllFieldFromConsoleValidated (PosicionArancelaria* this)
	{
		int retorno = -1;

		if (this != NULL)
		{
			retorno = -2;

			PosicionArancelaria aux;

			int resultadoObtencionNomenclador;
			int resultadoObtencionPorcentajeSeguro;
			int resultadoObtencionPorcentajeImportacion;
			int resultadoObtencionPorcentajeTasaEstadistica;
			int resultadoObtencionTipoLicencia;

			resultadoObtencionNomenclador = utn_getDescripcion(aux.nomenclador,NOMENCLADOR_LEN,"\nIngrese el nomenclador de la posicion arancelaria.\n","\nError en el ingreso de la nomenclatura.\n",3);
			resultadoObtencionPorcentajeSeguro = utn_getNumeroFlotante(&aux.porcentajeSeguro,"\nIngrese el porcentaje de seguro de la posicion arancelaria.\n","\nError en el ingreso del porcentaje.\n",0,100,3);
			resultadoObtencionPorcentajeImportacion = utn_getNumeroFlotante(&aux.porcentajeImportacion,"\nIngrese el porcentaje de la importacion de la posicion arancelaria.\n","\nError en el ingreso del porcentaje.\n",0,100,3);
			resultadoObtencionPorcentajeTasaEstadistica = utn_getNumeroFlotante(&aux.porcentajeTasaEstadistica,"\nIngrese el porcentaje de la tasa estadistica.\n","\nError en el ingreso del porcentaje.\n",0,100,3);
			resultadoObtencionTipoLicencia = utn_getNumero(&aux.tipoLicencia,"\nIngrese el numero del tipo de licencia. Automatica (0) - No Automatica (1) \n","\nError en el ingreso del numero representativo al tipo de licencia.\n", 0, 3, 3);

			if (resultadoObtencionNomenclador == 0 && resultadoObtencionPorcentajeSeguro == 0 && resultadoObtencionPorcentajeImportacion == 0 && resultadoObtencionPorcentajeTasaEstadistica == 0 && resultadoObtencionTipoLicencia == 0)
			{
				int resultadoSetterNomenclador;
				int resultadoSetterPorcentajeSeguro;
				int resultadoSetterPorcentajeImportacion;
				int resultadoSetterPorcentajeTasaEstadistica;
				int resultadoSetterTipoLicencia;

				resultadoSetterNomenclador = pArancelaria_setNomenclador (this,aux.nomenclador);
				resultadoSetterPorcentajeSeguro = pArancelaria_setPorcentajeSeguro (this,aux.porcentajeSeguro);
				resultadoSetterPorcentajeImportacion = pArancelaria_setPorcentajeImportacion (this,aux.porcentajeImportacion);
				resultadoSetterPorcentajeTasaEstadistica = pArancelaria_setPorcentajeTasaEstadistica (this,aux.porcentajeTasaEstadistica);
				resultadoSetterTipoLicencia = pArancelaria_setTipoLicencia(this,aux.tipoLicencia);

				if (resultadoSetterNomenclador == 0 && resultadoSetterPorcentajeSeguro == 0 && resultadoSetterPorcentajeImportacion == 0 && resultadoSetterPorcentajeTasaEstadistica == 0 && resultadoSetterTipoLicencia == 0)
				{
					retorno = 0;
				}
			}

		}

		return retorno;
	}



	int pArancelaria_setId(PosicionArancelaria* this, int id)
	{
		int retorno = -1;

		if (this != NULL && id > 0)
		{
			retorno = -2;

			int validacionId;
			validacionId = esIdValidoInt (id);

			if (validacionId == 0)
			{
				this->idPosicionArancelaria = id;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setIdTxt(PosicionArancelaria* this, char* id)
	{
		int retorno = -1;

		if (this != NULL && id != NULL)
		{
			retorno = -2;

			int validacionId;
			validacionId = esIdValido (id, CHARACTERS_LEN);

			if (validacionId == 0)
			{
				int idNumerico;
				idNumerico = atoi (id);

				this->idPosicionArancelaria = idNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_getId(PosicionArancelaria* this, int* id)
	{
		int retorno = -1;

		if (this != NULL && id > 0)
		{
			retorno = -2;

			int validacionId;
			validacionId = esIdValidoInt (this->idPosicionArancelaria);

			if (validacionId == 0)
			{
				*id = this->idPosicionArancelaria;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setNomenclador(PosicionArancelaria* this, char* nomenclador)
	{
		int retorno = -1;

		if (this != NULL && nomenclador != NULL)
		{
			retorno = -2;

			int validacionNomenclador;
			validacionNomenclador = esNomenclatura(nomenclador,NOMENCLADOR_LEN);

			if (validacionNomenclador == 0 )
			{
				strncpy (this->nomenclador,nomenclador,NOMENCLADOR_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}


	int pArancelaria_getNomenclador(PosicionArancelaria* this, char* nomenclador)
	{
		int retorno = -1;

		if (this != NULL && nomenclador != NULL)
		{
			retorno = -2;

			int validacionNomenclador;
			validacionNomenclador = esNomenclatura(this->nomenclador,NOMENCLADOR_LEN);

			if (validacionNomenclador == 0 )
			{
				strncpy (nomenclador,this->nomenclador,NOMENCLADOR_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}



	int pArancelaria_setPorcentajeSeguro(PosicionArancelaria* this, float porcentajeSeguro)
	{
		int retorno = -1;

		if (this != NULL && porcentajeSeguro >= 0)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValido (porcentajeSeguro);

			if (validacionPorcentaje == 0)
			{
				this->porcentajeSeguro = porcentajeSeguro;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setPorcentajeSeguroTxt(PosicionArancelaria* this, char* porcentajeSeguro)
	{
		int retorno = -1;

		if (this != NULL && porcentajeSeguro != NULL)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValidoTxt(porcentajeSeguro,CHARACTERS_LEN);

			if (validacionPorcentaje == 0)
			{
				int porcentajeNumerico;
				porcentajeNumerico = atof (porcentajeSeguro);

				this->porcentajeSeguro = porcentajeNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_getPorcentajeSeguro(PosicionArancelaria* this, float* porcentajeSeguro)
	{
		int retorno = -1;

		if (this != NULL && porcentajeSeguro != NULL)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValido (this->porcentajeSeguro);

			if (validacionPorcentaje == 0)
			{
				*porcentajeSeguro = this->porcentajeSeguro;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setPorcentajeImportacion(PosicionArancelaria* this, float porcentajeImportacion)
	{
		int retorno = -1;

		if (this != NULL && porcentajeImportacion >= 0)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValido (porcentajeImportacion);

			if (validacionPorcentaje == 0)
			{
				this->porcentajeImportacion = porcentajeImportacion;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setPorcentajeImportacionTxt(PosicionArancelaria* this, char* porcentajeImportacion)
	{
		int retorno = -1;

		if (this != NULL && porcentajeImportacion != NULL)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValidoTxt(porcentajeImportacion,CHARACTERS_LEN);

			if (validacionPorcentaje == 0)
			{
				int porcentajeNumerico;
				porcentajeNumerico = atof (porcentajeImportacion);

				this->porcentajeImportacion = porcentajeNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_getPorcentajeImportacion(PosicionArancelaria* this, float* porcentajeImportacion)
	{
		int retorno = -1;

		if (this != NULL && porcentajeImportacion != NULL)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValido (this->porcentajeImportacion);

			if (validacionPorcentaje == 0)
			{
				*porcentajeImportacion = this->porcentajeImportacion;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setPorcentajeTasaEstadistica(PosicionArancelaria* this, float porcentajeTasaEstadistica)
	{
		int retorno = -1;

		if (this != NULL && porcentajeTasaEstadistica >= 0)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValido (porcentajeTasaEstadistica);

			if (validacionPorcentaje == 0)
			{
				this->porcentajeTasaEstadistica = porcentajeTasaEstadistica;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setPorcentajeTasaEstadisticaTxt(PosicionArancelaria* this, char* porcentajeTasaEstadistica)
	{
		int retorno = -1;

		if (this != NULL && porcentajeTasaEstadistica != NULL)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValidoTxt(porcentajeTasaEstadistica,CHARACTERS_LEN);

			if (validacionPorcentaje == 0)
			{
				int porcentajeNumerico;
				porcentajeNumerico = atof (porcentajeTasaEstadistica);

				this->porcentajeTasaEstadistica = porcentajeNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_getPorcentajeTasaEstadistica(PosicionArancelaria* this, float* porcentajeTasaEstadistica)
	{
		int retorno = -1;

		if (this != NULL && porcentajeTasaEstadistica != NULL)
		{
			retorno = -2;

			int validacionPorcentaje;
			validacionPorcentaje = esPorcentajeValido (this->porcentajeTasaEstadistica);

			if (validacionPorcentaje == 0)
			{
				*porcentajeTasaEstadistica = this->porcentajeTasaEstadistica;
				retorno = 0;
			}
		}
		return retorno;
	}



	int pArancelaria_setTipoLicencia(PosicionArancelaria* this, int tipoLicencia)
	{
		int retorno = -1;

		if (this != NULL && tipoLicencia >= 0)
		{
			retorno = -2;

			int validacionTipoLicencia;
			validacionTipoLicencia = esTipoLicenciaValido (tipoLicencia);

			if (validacionTipoLicencia == 0)
			{
				this->tipoLicencia = tipoLicencia;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_setTipoLicenciaTxt(PosicionArancelaria* this, char* tipoLicencia)
	{
		int retorno = -1;

		if (this != NULL && tipoLicencia != NULL)
		{
			retorno = -2;

			int validacionTipoLicencia;
			validacionTipoLicencia =  esTipoLicenciaValidoTxt(tipoLicencia,CHARACTERS_LEN);

			if (validacionTipoLicencia == 0)
			{
				int tipoLicenciaNumerico;
				tipoLicenciaNumerico = atoi (tipoLicencia);

				this->tipoLicencia = tipoLicenciaNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}

	int pArancelaria_getTipoLicencia(PosicionArancelaria* this, int* tipoLicencia)
	{
		int retorno = -1;

		if (this != NULL && tipoLicencia != NULL)
		{
			retorno = -2;

			int validacionTipoLicencia;
			validacionTipoLicencia = esTipoLicenciaValido (this->tipoLicencia);

			if (validacionTipoLicencia == 0)
			{
				*tipoLicencia = this->tipoLicencia;
				retorno = 0;
			}
		}
		return retorno;
	}


	PosicionArancelaria* pArancelaria_new (void)
	{
		return (PosicionArancelaria*) malloc (sizeof(PosicionArancelaria));
	}


	void pArancelaria_delete(PosicionArancelaria* this)
	{
		if (this != NULL)
		{
			free (this);
			this = NULL;
		}
	}


	int save_pArancelaria (char* path, Dictionary* this)
	{
		int retorno = -1;

		if (path != NULL && this != NULL)
		{
			retorno = -2;

			LinkedList* listapArancelarias = dict_getValues(this);

			FILE* filePuntero;
			filePuntero = fopen (path,"w");

			if (filePuntero != NULL)
			{
				retorno = 0;

				PosicionArancelaria aux;

				int resultadoObtencionValidacion;
				PosicionArancelaria* pPosicionArancelariall;

				for (int i = 0 ; i < ll_len(listapArancelarias) ; i++)
				{
					pPosicionArancelariall = ll_get(listapArancelarias, i);

					if (pPosicionArancelariall != NULL)
					{
						//Guardo en aux los campos de pPosicionArancelariall;
						resultadoObtencionValidacion = pArancelaria_getAll (pPosicionArancelariall,&aux.idPosicionArancelaria,aux.nomenclador,&aux.porcentajeSeguro,&aux.porcentajeImportacion,&aux.porcentajeTasaEstadistica,&aux.tipoLicencia);

						if (resultadoObtencionValidacion == 0)
						{
							fprintf (filePuntero,"%d,%s,%f,%f,%f,%d\n",aux.idPosicionArancelaria,aux.nomenclador,aux.porcentajeImportacion,aux.porcentajeSeguro,aux.porcentajeTasaEstadistica,aux.tipoLicencia);
						}
						else
						{
							//printf("\nSalio mal saver\n");
							retorno = -3;
						}
					}
				}

				//Salga como salga el save en el parser, cierro el archivo.
				fclose(filePuntero);

			}
			else
			{
				retorno = -3;
			}

			ll_deleteLinkedList(listapArancelarias);
		}


		return retorno;
	}

	int load_pArancelaria (char* path, Dictionary* pListapArancelaria)
	{
		int retorno = -1;
		int idMax;

		if (path != NULL && pListapArancelaria != NULL)
		{
			retorno = -2;

			FILE* pFile;
			pFile = fopen (path,"r");

			if (pFile != NULL)
			{

				idMax = parser_pArancelariaFromText(pFile, pListapArancelaria);
				//printf ("RESULTADO PARSER: %d",resultadoParser);

				fclose(pFile);

				retorno = idMax;

			}
			else
			{
				printf ("\nError en la carga de posiciones Arancelarias.\n");
			}

		}


		return retorno;
	}

	int parser_pArancelariaFromText(FILE* pFile , Dictionary* pListapArancelaria)
	{
		int retorno = -1;

		if (pFile != NULL && pListapArancelaria != NULL)
		{
			retorno = -2;

			int resultadoFscanf;
			int resultadoSetAllByTxt;
			int contadorParancelariaLoadeadas = 0;

			PosicionArancelariaTxt pArancelariaTxt;
			PosicionArancelaria* pNewPArancelaria;

			int idAux;
			int idMax;

			do
			{
				resultadoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",pArancelariaTxt.idPosicionArancelaria, pArancelariaTxt.nomenclador, pArancelariaTxt.porcentajeSeguro, pArancelariaTxt.porcentajeImportacion, pArancelariaTxt.porcentajeTasaEstadistica, pArancelariaTxt.tipoLicencia);

				if (resultadoFscanf == 6)
				{

					pNewPArancelaria = pArancelaria_new();

					resultadoSetAllByTxt = pArancelaria_setAllTxt (pNewPArancelaria,pArancelariaTxt.idPosicionArancelaria,pArancelariaTxt.nomenclador,pArancelariaTxt.porcentajeSeguro,pArancelariaTxt.porcentajeImportacion,pArancelariaTxt.porcentajeTasaEstadistica,pArancelariaTxt.tipoLicencia);

					if (pNewPArancelaria != NULL && resultadoSetAllByTxt == 0)
					{
						idAux = atoi(pArancelariaTxt.idPosicionArancelaria);

						if(contadorParancelariaLoadeadas == 0 || idAux > idMax)
						{
							idMax = idAux;
						}

						//print_posicionArancelaria (pNewPArancelaria);
						dict_insert (pListapArancelaria,pArancelariaTxt.idPosicionArancelaria,pNewPArancelaria);
						contadorParancelariaLoadeadas++;
					}
					else if (resultadoSetAllByTxt != 0 && pNewPArancelaria != NULL)
					{
						//Si sale mal el setteo borro la memoria pedida
						pArancelaria_delete(pNewPArancelaria);
						pNewPArancelaria = NULL;
					}

				}


			}while(feof(pFile) == 0);

			if (contadorParancelariaLoadeadas > 0)
			{
				retorno = idMax;
				//printf ("POSICIONES ARANCELARIAS LODEADAS: %d IDMAX: %d",contadorParancelariaLoadeadas,idMax);
			}
		}


		return retorno;

	}


