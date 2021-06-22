/*
 * TransporteMaritimo.c
 *
 *  Created on: 17 jun. 2021
 *      Author: gabil
 */

	#include <stdio.h>
	#include <stdlib.h>

	#include "string.h"
	#include "TransporteMaritimo.h"
	#include "utn.h"
	#include "PosicionArancelaria.h"
	#include "Producto.h"

	int print_transporteMaritimo(TransporteMaritimo* pValues)
	{
		int retorno = -1;

		if (pValues != NULL)
		{
			printf ("\nPrecio por metro cubico: %f\nMetros cubicos container: %2.f",pValues->precioPorMtCubico,pValues->mtsCubicosContainer);
		}

		return retorno;
	}

	int calcularTransMaritimo_precioFinal (float baseImponible, float porcentajeImportacion, float porcentajeTasaEstadistica, float* pResultado)
	{
		int retorno = -1;

		if (baseImponible >= 0 && porcentajeImportacion >= 0 && porcentajeTasaEstadistica >= 0 && pResultado != NULL)
		{
			*pResultado = baseImponible + porcentajeImportacion + porcentajeTasaEstadistica;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransMaritimo_baseImponible (float valorFob, float porcentajeSeguro, float proporcionalTransporte, float* pResultado)
	{
		int retorno = -1;

		if (valorFob >= 0 && porcentajeSeguro >= 0 && proporcionalTransporte >= 0 && pResultado != NULL)
		{

			*pResultado = valorFob + porcentajeSeguro + proporcionalTransporte;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransMaritimo_proprocionalTransporte (float metrosCubicosContainer, float precioPorMtCubico, float volumenProductoMTS, float* pResultado)
	{
		int retorno = -1;

		if (metrosCubicosContainer >= 0 && precioPorMtCubico >= 0 && volumenProductoMTS >= 0 && pResultado != NULL)
		{
			*pResultado = (metrosCubicosContainer / precioPorMtCubico) * volumenProductoMTS;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransMaritimo_porcentajeSeguro (float valorFob, float porcentajeSeguro, float* pResultado)
	{
		int retorno = -1;

		if (valorFob >= 0 && porcentajeSeguro >= 0 && pResultado != NULL)
		{
			*pResultado = (valorFob * porcentajeSeguro) / 100;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransMaritimo_porcentajeImportacion (float porcentajeImportacion, float baseImponible, float* pResultado)
	{
		int retorno = -1;

		if (porcentajeImportacion >= 0 && baseImponible >= 0 && pResultado != NULL)
		{
			*pResultado = (porcentajeImportacion * baseImponible) / 100;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransMaritimo_porcentajeTasaEstadistica (float porcentajeTasaEstadistica, float baseImponible, float* pResultado)
	{
		int retorno = -1;

		if (porcentajeTasaEstadistica >= 0 && baseImponible >= 0 && pResultado != NULL)
		{
			*pResultado = (porcentajeTasaEstadistica * baseImponible) / 100;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransMaritimo_precioFinalTotal (Producto* pProducto, PosicionArancelaria* pPosArancelariaProducto, float precioPorMtCubico, float mtsCubicosContainer, float* pResultado)
	{
		int retorno = -1;

		if (pProducto != NULL && pPosArancelariaProducto != NULL && precioPorMtCubico >= 0 && mtsCubicosContainer >= 0 && pResultado != NULL)
		{

			//Obtengo valor fob
			float valorFobProducto;
			producto_getValorFobUSD(pProducto,&valorFobProducto);

			//Obtengo valor porcentajeSeguro
			float porcentajeSeguro;
			pArancelaria_getPorcentajeSeguro(pPosArancelariaProducto,&porcentajeSeguro);

			//Calculo el nuevo porcentajeSeguro
			calcularTransMaritimo_porcentajeSeguro (valorFobProducto,porcentajeSeguro,&porcentajeSeguro);

			//Obtengo largo-alto-ancho del producto para calcular su volumenMT
			float largoProducto;
			float altoProducto;
			float anchoProducto;

			producto_getLargoEmpaque(pProducto, &largoProducto);
			producto_getAltoEmpaque(pProducto, &altoProducto);;
			producto_getAnchoEmpaque(pProducto, &anchoProducto);

			float volumenMTSProducto;
			calcular_volumenDeEmpaqueMETROS (altoProducto,largoProducto,anchoProducto,&volumenMTSProducto);

			//Calculo el proporcional transporte.
			float proporcionalTransporte;
			calcularTransMaritimo_proprocionalTransporte (mtsCubicosContainer,precioPorMtCubico,volumenMTSProducto,&proporcionalTransporte);

			//Calculo base imponible.
			float baseImponible;
			calcularTransMaritimo_baseImponible (valorFobProducto,porcentajeSeguro,proporcionalTransporte,&baseImponible);

			//Obtengo porcentaje importacion.
			float porcentajeImportacion;
			pArancelaria_getPorcentajeImportacion(pPosArancelariaProducto,&porcentajeImportacion);

			//Calculo el nuevo porcentaje importacion.
			calcularTransMaritimo_porcentajeImportacion (porcentajeImportacion,baseImponible,&porcentajeImportacion);

			//Obtengo porcentaje tasa estadistica.
			float porcentajeTasaEstadistica;
			pArancelaria_getPorcentajeTasaEstadistica(pPosArancelariaProducto,&porcentajeTasaEstadistica);

			//Calculo el nuevo porcentaje tasa estadistica.
			calcularTransMaritimo_porcentajeTasaEstadistica (porcentajeTasaEstadistica,baseImponible,&porcentajeTasaEstadistica);

			//Calculo el resultado final.
			float precioFinal;
			calcularTransMaritimo_precioFinal (baseImponible,porcentajeImportacion,porcentajeTasaEstadistica,&precioFinal);

			*pResultado = precioFinal;

			retorno = 0;

		}

		return retorno;
	}



	int loadFromTxtPrecioMetroCubico (char* path, float* pPrecioPorMetroCubico, float* pMetrosCubicosContainer)
	{
		int retorno = -1;

		if (path != NULL && pPrecioPorMetroCubico != NULL)
		{

			FILE* pFile;
			pFile = fopen (path,"r");

			if (pFile != NULL)
			{

				int resultadoParser;
				resultadoParser = parser_precioMetroCubicoFromTxt(pFile,pPrecioPorMetroCubico,pMetrosCubicosContainer);

				//Salga como salga el load en el parser, cierro el archivo.
				fclose(pFile);

				if (resultadoParser == 0)
				{
					retorno = 0;
				}

			}
			else
			{
				retorno = -2;
				printf ("\nError en la apertura del archivo.\n");
			}
		}

		return retorno;
	}

	int parser_precioMetroCubicoFromTxt(FILE* pFile, float* pPrecioPorMetroCubicoLeido, float* pMetrosCubicosContainer)
	{
		int retorno = -1;

		if (pFile != NULL && pPrecioPorMetroCubicoLeido != NULL)
		{
			retorno = -2;

			int resultadoFscanf;
			float auxPrecioPorMetroCubicoLeido;
			float auxMetrosCubicosContainer;

			do{

				resultadoFscanf = fscanf(pFile,"%f,%f\n",&auxPrecioPorMetroCubicoLeido,&auxMetrosCubicosContainer);

			}while(feof(pFile) == 0);


			//Si se cargo la variable deberia devolver 2
			if(resultadoFscanf == 2)
			{
				retorno = -3;

				//Lo valido
				int resultadoValidacionPrecioPorMetroCubicoLeido;
				resultadoValidacionPrecioPorMetroCubicoLeido = esPrecioPorMtCubico (auxPrecioPorMetroCubicoLeido);

				int resultadoValidacionMetrosCubicosContainer;
				resultadoValidacionMetrosCubicosContainer = esMetrosCubicosContainer(auxMetrosCubicosContainer);

				if (resultadoValidacionPrecioPorMetroCubicoLeido == 0 && resultadoValidacionMetrosCubicosContainer == 0)
				{
					//Lo devuelvo
					*pPrecioPorMetroCubicoLeido = auxPrecioPorMetroCubicoLeido;
					*pMetrosCubicosContainer = auxMetrosCubicosContainer;
					retorno = 0;

				}
			}

		}

		return retorno;
	}

	int save_valuesTransporteMaritimo (char* path, TransporteMaritimo* this)
	{
		int retorno = -1;

		if (path != NULL && this != NULL)
		{
			TransporteMaritimo aux;

			FILE* filePuntero;
			filePuntero = fopen (path,"w");

			if (filePuntero != NULL)
			{

				//Guardo en aux los campos de pPosicionArancelariall;
				int resultadoObtencionValidacion;
				resultadoObtencionValidacion = transMaritimo_getAllParams (this,&aux.precioPorMtCubico,&aux.mtsCubicosContainer);

				if (resultadoObtencionValidacion == 0)
				{
					fprintf (filePuntero,"%f,%f\n",aux.precioPorMtCubico,aux.mtsCubicosContainer);
					retorno = 0;
				}
				else
				{
					retorno = -3;
				}

				//Salga como salga el save en el parser, cierro el archivo.
				fclose(filePuntero);
			}
			else
			{
				retorno = -2;
			}

		}

		return retorno;
	}




	////////////////////////////////////////////////////////////////////////////////////////

	int transMaritimo_setAllParams(TransporteMaritimo* this, float mtsCubicosContainer, float precioPorMtCubico)
	{
		int retorno = -1;

		//Valido parametros
		if (mtsCubicosContainer > 0 && precioPorMtCubico > 0)
			{
				int resultadoSetterMtsCubicosContainer;
				int resultadoSetterPrecioMtsCubicos;


				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoSetterMtsCubicosContainer = transMaritimo_setMtsCubicos (this,mtsCubicosContainer);
				resultadoSetterPrecioMtsCubicos = transMaritimo_setPrecioMtsCubicos (this,precioPorMtCubico);


				//Si sale bien devuelvo 0 ya que el transporte maritimo quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoSetterMtsCubicosContainer == 0 && resultadoSetterPrecioMtsCubicos == 0)
				{
					retorno = 0;
				}
				else
				{
					retorno = -2;
				}
		}

		return retorno;
	}

	int transMaritimo_setAllParamsTxt(TransporteMaritimo* this, char* mtsCubicosContainer, char* precioPorMtCubico)
	{
		int retorno = -1;

		//Valido parametros
		if (mtsCubicosContainer != NULL && precioPorMtCubico != NULL)
			{
				int resultadoSetterMtsCubicosContainerTxt;
				int resultadoSetterPrecioMtsCubicosTxt;

				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoSetterMtsCubicosContainerTxt = transMaritimo_setMtsCubicosTxt (this,mtsCubicosContainer);
				resultadoSetterPrecioMtsCubicosTxt = transMaritimo_setPrecioMtsCubicosTxt (this,precioPorMtCubico);

				//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoSetterMtsCubicosContainerTxt == 0 && resultadoSetterPrecioMtsCubicosTxt == 0)
				{
					retorno = 0;
				}
				else
				{
					retorno = -2;
				}
		}

		return retorno;
	}

	int transMaritimo_getAllParams(TransporteMaritimo* this, float* mtsCubicosContainer, float* precioPorMtCubico)
	{
		int retorno = -1;

		//Valido parametros
		if (mtsCubicosContainer != NULL && precioPorMtCubico != NULL)
			{
				int resultadoGetterMtsCubicosContainer;
				int resultadoGetterPrecioMtsCubicos;


				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoGetterMtsCubicosContainer = transMaritimo_getMtsCubicos (this,mtsCubicosContainer);
				resultadoGetterPrecioMtsCubicos = transMaritimo_getPrecioMtsCubicos (this,precioPorMtCubico);


				//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoGetterMtsCubicosContainer == 0 && resultadoGetterPrecioMtsCubicos == 0)
				{
					retorno = 0;
				}
				else
				{
					retorno = -2;
				}
		}

		return retorno;
	}

	int transMaritimo_setMtsCubicos (TransporteMaritimo* this, float mtsCubicos)
	{
		int retorno = -1;

		if (this != NULL && mtsCubicos > 0)
		{
			retorno = -2;
			int validacionMtsCubicos;
			validacionMtsCubicos = esMetrosCubicosContainer(mtsCubicos);

			if (validacionMtsCubicos == 0)
			{
				this->mtsCubicosContainer = mtsCubicos;
				retorno = 0;
			}

		}

		return retorno;
	}

	int transMaritimo_setMtsCubicosTxt (TransporteMaritimo* this, char* mtsCubicos)
	{
		int retorno = -1;

		if (this != NULL && mtsCubicos != NULL)
		{
			retorno = -2;
			int validacionMtsCubicos;
			validacionMtsCubicos = esMetrosCubicosContainerTxt(mtsCubicos,CHARACTERS_LEN);

			if (validacionMtsCubicos == 0)
			{
				float mtsCubicosFloat;
				mtsCubicosFloat = atof(mtsCubicos);
				this->mtsCubicosContainer = mtsCubicosFloat;

				retorno = 0;
			}

		}

		return retorno;
	}

	int transMaritimo_getMtsCubicos(TransporteMaritimo* this, float* pMtsCubicos)
	{
		int retorno = -1;

		if (this != NULL && pMtsCubicos != NULL)
		{
			retorno = -2;

			int validacionMtsCubicos;
			validacionMtsCubicos = esMetrosCubicosContainer(this->mtsCubicosContainer);

			if (validacionMtsCubicos == 0)
			{
				*pMtsCubicos = this->mtsCubicosContainer;
				retorno = 0;
			}
		}
		return retorno;
	}

	int transMaritimo_setPrecioMtsCubicos (TransporteMaritimo* this, float precioMtsCubicos)
	{
		int retorno = -1;

		if (this != NULL && precioMtsCubicos > 0)
		{
			retorno = -2;
			int validacionprecioMtsCubicos;
			validacionprecioMtsCubicos = esMetrosCubicosContainer(precioMtsCubicos);

			if (validacionprecioMtsCubicos == 0)
			{
				this->precioPorMtCubico = precioMtsCubicos;
				retorno = 0;
			}

		}

		return retorno;
	}

	int transMaritimo_setPrecioMtsCubicosTxt (TransporteMaritimo* this, char* precioMtsCubicos)
	{
		int retorno = -1;

		if (this != NULL && precioMtsCubicos != NULL)
		{
			retorno = -2;

			int validacionprecioMtsCubicos;
			validacionprecioMtsCubicos = esPrecioPorMtCubicoTxt(precioMtsCubicos,CHARACTERS_LEN);

			if (validacionprecioMtsCubicos == 0)
			{
				float mtsCubicosFloat;
				mtsCubicosFloat = atof(precioMtsCubicos);
				this->precioPorMtCubico = mtsCubicosFloat;

				retorno = 0;
			}

		}

		return retorno;
	}


	int transMaritimo_getPrecioMtsCubicos(TransporteMaritimo* this, float* pPrecioMtsCubicos)
	{
		int retorno = -1;

		if (this != NULL && pPrecioMtsCubicos != NULL)
		{
			retorno = -2;

			int validacionPrecioMtsCubicos;
			validacionPrecioMtsCubicos = esPrecioPorMtCubico(this->precioPorMtCubico);

			if (validacionPrecioMtsCubicos == 0)
			{
				*pPrecioMtsCubicos = this->precioPorMtCubico;
				retorno = 0;
			}
		}
		return retorno;
	}
