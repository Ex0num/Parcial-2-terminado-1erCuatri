	/*
	 * controller.h
	 *
	 *  Created on: 18 jun. 2021
	 *      Author: gabil
	 */

	#ifndef CONTROLLER_H_
	#define CONTROLLER_H_

	#include "TransporteMaritimo.h"
	#include "TransporteAereo.h"

	//----------PRODUCTO---------------------------------------------
	int controller_addProducto(Dictionary* pDiccionarioProductos, Dictionary* pDiccionarioPosicionesArancelarias, int* pValorIDMaximoProductos,TransporteMaritimo* pValoresTransMaritimo, TransporteAereo* pValoresTransAereo);
	int controller_deleteProducto(Dictionary* listaProductos);
	int controller_modifyProducto(Dictionary* listaProductos, Dictionary* listapArancelarias, TransporteMaritimo* pValoresTransMaritimo, TransporteAereo* pValoresTransAereo);
	int controller_listarProductos (Dictionary* pListaProductos);

	//-----------POSICION ARANCELARIA--------------------------------------------------------
	int controller_addPosicionArancelaria (Dictionary* pListaPosicionesArancelarias, int* pValorIDMaximopArancelaria);
	int controller_deletePosicionArancelaria (Dictionary* plistaProductos, Dictionary* listaPosicionesArancelarias);
	int controller_modificatePosicionArancelaria (Dictionary* listaProductos, Dictionary* listaPosicionesArancelarias);
	int controller_listarPosicionesArancelarias (Dictionary* pListaPArancelarias);

	//-------------TRANSPORTE---------------------------------------------
	int controller_newValuesTransporteByMar (char* path, TransporteMaritimo* pValoresActuales);
	int controller_newValuesTransporteByAir (char* path, TransporteAereo* pValoresActuales);

	//---------------------------------------------------------------------------
	int controller_finalActions (Dictionary* listaProductos, Dictionary* listaPArancelarias);

	#endif /* CONTROLLER_H_ */
