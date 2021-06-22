	/*
	 * TransporteAereo.h
	 *
	 *  Created on: 17 jun. 2021
	 *      Author: gabil
	 */

	#ifndef TRANSPORTEAEREO_H_
	#define TRANSPORTEAEREO_H_

	#include "PosicionArancelaria.h"
	#include "Producto.h"

	//-----DEFINES-------------------

	#define CHARACTERS_LEN 32


	//----ESTRUCTURA TRANSPORTE AEREO---------

	typedef struct pTransporteAereo
	{
		float constanteVolumetrica;
		float precioPorKg;

	}TransporteAereo;

	//----ESTRUCTURA TRANSPORTE AEREO TXT---------

	typedef struct pTransporteAereoTxt
	{
		char constanteVolumetrica[CHARACTERS_LEN];
		char precioPorKg[CHARACTERS_LEN];

	}TransporteAereoTxt;


	//============================================  S E T T E R   Y   G E T T E R S ============================================//

	//----------SETTER Y GETTER GENERAL--------------------------------------------------
	int transAereo_setAllParams(TransporteAereo* this, float constanteVolumetrica, float precioPorKG);
	int transAereo_setAllParamsTxt(TransporteAereo* this, char* constanteVolumetrica, char* precioPorKG);
	int transAereo_getAllParams(TransporteAereo* this, float* constanteVolumetrica, float* precioPorKG);

	//----------CONSTANTE VOLUMETRICA----------------------------------------------------------
	int transAereo_setConstanteVolumetrica(TransporteAereo* this, float constanteVolumetrica);
	int transAereo_setConstanteVolumetricaTxt (TransporteAereo* this, char* constanteVolumetrica);
	int transAereo_getConstanteVolumetrica(TransporteAereo* this, float* constanteVolumetrica);

	//----------PRECIO POR KG----------------------------------------------------------
	int transAereo_setPrecioPorKg(TransporteAereo* this, float precioPorKg);
	int transAereo_setPrecioPorKgTxt (TransporteAereo* this, char* precioPorKg);
	int transAereo_getPrecioPorKG(TransporteAereo* this, float* precioPorKG);

	//----------FUNCIONES EXTRA (PRINT - SAVER Y LOADER)---------------------------------------------------------
	int print_transporteAereo(TransporteAereo* pValues);
	int save_valuesTransporteAereo (char* path, TransporteAereo* this);
	int loadFromTxt_ConstanteVolumetrica_y_precioPorKG (char* path, float* pConstanteVolumetricaLeida, float* pPrecioPorKG);
	int parser_precio_ConstanteVolumetrica_y_precioPorKg_FromTxt (FILE* pFile, float* pConstanteVolumetricaLeida, float* pPrecioPorKG);

	//----------FUNCIONES DE CALCULO---------------------------------------------------------
	int calcularTransAereo_precioFinalTotal (Producto* pProducto, PosicionArancelaria* pPosArancelariaProducto, float constanteVolumetrica, float precioPorKg, float* pResultado);
	int calcularTransAereo_precioFinal (float baseImponible, float porcentajeImportacion, float porcentajeTasaEstadistica, float* pResultado);
	int calcularTransAereo_baseImponible (float valorFob, float porcentajeSeguro, float proporcionalTransporte, float* pResultado);
	int calcularTransAereo_porcentajeImportacion (float porcentajeImportacion, float baseImponible, float* pResultado);
	int calcularTransAereo_porcentajeTasaEstadistica (float porcentajeTasaEstadistica, float baseImponible, float* pResultado);
	int calcularTransAereo_porcentajeSeguro (float valorFob, float porcentajeSeguro, float* pResultado);
	int calcularTransAereo_proporcionalTransporte (float pesoVolumetrico, float pesoReal, float* pResultado);
	int calcularTransAereo_pesoReal (float pesoKgArticulo, float precioPorKg, float* pResultado);
	int calcularTransAereo_pesoVolumetrico (float dimensiones, float constanteVolumetrica, float precioPorKg, float* pResultado);
	int calcularTransAereo_dimensiones (float ancho, float alto, float largo, float* pResultado);

	#endif /* TRANSPORTEAEREO_H_ */
