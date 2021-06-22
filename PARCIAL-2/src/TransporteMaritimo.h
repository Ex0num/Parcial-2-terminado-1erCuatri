	/*
	 * TransporteMaritimo.h
	 *
	 *  Created on: 17 jun. 2021
	 *      Author: gabil
	 */

	#ifndef TRANSPORTEMARITIMO_H_
	#define TRANSPORTEMARITIMO_H_

	#include "PosicionArancelaria.h"
	#include "Producto.h"

	#define CHARACTERS_LEN 32

	//----ESTRUCTURA PRODUCTO---------

	typedef struct pTransporteMaritimo
	{
		float mtsCubicosContainer;
		float precioPorMtCubico;

	}TransporteMaritimo;

	//----ESTRUCTURA PRODUCTO TXT---------

	typedef struct pTransporteMaritimoTxt
	{
		char mtsCubicosContainer[CHARACTERS_LEN];
		char precioPorMtCubico[CHARACTERS_LEN];

	}TransporteMaritimoTxt;

	//============================================  S E T T E R   Y   G E T T E R S ============================================//

	//----------SETTER Y GETTER GENERAL--------------------------------------------------
	int transMaritimo_setAllParams(TransporteMaritimo* this, float mtsCubicosContainer, float precioPorMtCubico);
	int transMaritimo_setAllParamsTxt(TransporteMaritimo* this, char* mtsCubicosContainer, char* precioPorMtCubico);
	int transMaritimo_getAllParams(TransporteMaritimo* this, float* mtsCubicosContainer, float* precioPorMtCubico);

	//----------METROS CUBICOS CONTAINER----------------------------------------------------------
	int transMaritimo_setMtsCubicos (TransporteMaritimo* this, float mtsCubicos);
	int transMaritimo_setMtsCubicosTxt (TransporteMaritimo* this, char* mtsCubicos);
	int transMaritimo_getMtsCubicos(TransporteMaritimo* this, float* pMtsCubicos);

	//---------- PRECIO DE METROS CUBICO----------------------------------------------------------
	int transMaritimo_setPrecioMtsCubicos (TransporteMaritimo* this, float precioMtsCubicos);
	int transMaritimo_setPrecioMtsCubicosTxt (TransporteMaritimo* this, char* precioMtsCubicos);
	int transMaritimo_getPrecioMtsCubicos(TransporteMaritimo* this, float* pPrecioMtsCubicos);

	//----------FUNCIONES EXTRA (PRINT - SAVER Y LOADER)---------------------------------------------------------------
	int print_transporteMaritimo(TransporteMaritimo* pValues);
	int save_valuesTransporteMaritimo (char* path, TransporteMaritimo* this);
	int loadFromTxtPrecioMetroCubico (char* path, float* pPrecioPorMetroCubico, float* pMetrosCubicosContainer);
	int parser_precioMetroCubicoFromTxt(FILE* pFile, float* pPrecioPorMetroCubicoLeido, float* pMetrosCubicosContainer);

	//----------FUNCIONES DE CALCULO---------------------------------------------------------------
	int calcularTransMaritimo_precioFinalTotal (Producto* pProducto, PosicionArancelaria* pPosArancelariaProducto, float precioPorMtCubico, float mtsCubicosContainer, float* pResultado);
	int calcularTransMaritimo_precioFinal (float baseImponible, float porcentajeImportacion, float porcentajeTasaEstadistica, float* pResultado);
	int calcularTransMaritimo_baseImponible (float valorFob, float porcentajeSeguro, float proporcionalTransporte, float* pResultado);
	int calcularTransMaritimo_proprocionalTransporte (float metrosCubicosContainer, float precioPorMtCubico, float volumenProductoMTS, float* pResultado);
	int calcularTransMaritimo_porcentajeSeguro (float valorFob, float porcentajeSeguro, float* pResultado);
	int calcularTransMaritimo_porcentajeImportacion (float porcentajeImportacion, float baseImponible, float* pResultado);
	int calcularTransMaritimo_porcentajeTasaEstadistica (float porcentajeTasaEstadistica, float baseImponible, float* pResultado);

	#endif /* TRANSPORTEMARITIMO_H_ */
