	/*
	 * PosicionArancelaria.h
	 *
	 *  Created on: 17 jun. 2021
	 *      Author: gabil
	 */

	#include "Dictionary.h"

	#ifndef POSICIONARANCELARIA_H_
	#define POSICIONARANCELARIA_H_

	#define NOMENCLADOR_LEN 42
	#define LIC_AUTOMATICA 0
	#define LIC_NOAUTOMATICA 1
	#define CHARACTERS_LEN 32

	typedef struct pPosicionArancelaria
	{
		int idPosicionArancelaria;
		char nomenclador[NOMENCLADOR_LEN];

		float porcentajeSeguro;
		float porcentajeImportacion;
		float porcentajeTasaEstadistica;

		int tipoLicencia;

	}PosicionArancelaria;

	typedef struct pPosicionArancelariaTxt
	{
		char idPosicionArancelaria[CHARACTERS_LEN];
		char nomenclador[NOMENCLADOR_LEN];

		char porcentajeSeguro[CHARACTERS_LEN];
		char porcentajeImportacion[CHARACTERS_LEN];
		char porcentajeTasaEstadistica[CHARACTERS_LEN];

		char tipoLicencia[CHARACTERS_LEN];

	}PosicionArancelariaTxt;

	//===============  F U N C I O N E S   P O S I C I O N   A R A N C E L A R I A  ===================
	PosicionArancelaria* pArancelaria_new (void);
	void pArancelaria_delete(PosicionArancelaria* this);

	//----------SETTER Y GETTER GENERAL--------------------------------------------------
	int pArancelaria_setAll (PosicionArancelaria* this, int id, char* nomenclador, float porcentajeSeguro, float porcentajeImportacion, float porcentajeTasaEstadistica, int tipoLicencia);
	int pArancelaria_setAllTxt (PosicionArancelaria* this, char* id, char* nomenclador, char* porcentajeSeguro, char* porcentajeImportacion, char* porcentajeTasaEstadistica, char* tipoLicencia);
	int pArancelaria_getAll (PosicionArancelaria* this, int* id, char* nomenclador, float* porcentajeSeguro, float* porcentajeImportacion, float* porcentajeTasaEstadistica, int* tipoLicencia);

	//----------GETTER GENERAL POR CONSOLA------------------------------------------------
	int pArancelaria_getAllFieldFromConsoleValidated (PosicionArancelaria* this);

	//----------ID-----------------------------------------------------------
	int pArancelaria_setId(PosicionArancelaria* this, int id);
	int pArancelaria_setIdTxt(PosicionArancelaria* this, char* id);
	int pArancelaria_getId(PosicionArancelaria* this, int* id);

	//----------NOMENCLADOR-----------------------------------------------------
	int pArancelaria_setNomenclador(PosicionArancelaria* this, char* nomenclador);
	int pArancelaria_getNomenclador(PosicionArancelaria* this, char* nomenclador);

	//----------PORCENTAJE SEGURO-----------------------------------------------
	int pArancelaria_setPorcentajeSeguro(PosicionArancelaria* this, float porcentajeSeguro);
	int pArancelaria_setPorcentajeSeguroTxt(PosicionArancelaria* this, char* porcentajeSeguro);
	int pArancelaria_getPorcentajeSeguro(PosicionArancelaria* this, float* porcentajeSeguro);

	//----------PORCENTAJE IMPORTACION-----------------------------------------------
	int pArancelaria_setPorcentajeImportacion(PosicionArancelaria* this, float porcentajeImportacion);
	int pArancelaria_setPorcentajeImportacionTxt(PosicionArancelaria* this, char* porcentajeImportacion);
	int pArancelaria_getPorcentajeImportacion(PosicionArancelaria* this, float* porcentajeImportacion);

	//----------PORCENTAJE TASA ESTADISTICA-----------------------------------------------
	int pArancelaria_setPorcentajeTasaEstadistica(PosicionArancelaria* this, float porcentajeTasaEstadistica);
	int pArancelaria_setPorcentajeTasaEstadisticaTxt(PosicionArancelaria* this, char* porcentajeTasaEstadistica);
	int pArancelaria_getPorcentajeTasaEstadistica(PosicionArancelaria* this, float* porcentajeTasaEstadistica);

	//----------TIPO LICENCIA-----------------------------------------------------
	int pArancelaria_setTipoLicencia(PosicionArancelaria* this, int tipoLicencia);
	int pArancelaria_setTipoLicenciaTxt(PosicionArancelaria* this, char* tipoLicencia);
	int pArancelaria_getTipoLicencia(PosicionArancelaria* this, int* tipoLicencia);

	//----------FUNCIONES EXTRA (PRINT - SAVER Y LOADER)---------------------------------------------------------------
	int print_posicionArancelaria (PosicionArancelaria* this);
	int save_pArancelaria (char* path, Dictionary* this);
	int load_pArancelaria (char* path, Dictionary* pListapArancelaria);
	int parser_pArancelariaFromText(FILE* pFile , Dictionary* pListapArancelaria);

	#endif /* POSICIONARANCELARIA_H_ */
