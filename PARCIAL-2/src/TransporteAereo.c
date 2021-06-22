	/*
	 * TransporteAereo.c
	 *
	 *  Created on: 18 jun. 2021
	 *      Author: gabil
	 */

	#include <stdio.h>
	#include <stdlib.h>

	#include "string.h"
	#include "TransporteAereo.h"
	#include "utn.h"
	#include "PosicionArancelaria.h"
	#include "Producto.h"


	int print_transporteAereo(TransporteAereo* pValues)
	{
		int retorno = -1;

		if (pValues != NULL)
		{
			printf ("\nConstante volumetrica: %f\nPrecio por kg: %f",pValues->constanteVolumetrica,pValues->precioPorKg);
		}

		return retorno;
	}

	int transAereo_setAllParams(TransporteAereo* this, float constanteVolumetrica, float precioPorKG)
	{
		int retorno = -1;

		//Valido parametros
		if (constanteVolumetrica > 0 && precioPorKG > 0)
			{
				int resultadoSetterConstanteVolumetrica;
				int resultadoSetterPrecioPorKG;


				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoSetterConstanteVolumetrica = transAereo_setConstanteVolumetrica(this,constanteVolumetrica);
				resultadoSetterPrecioPorKG = transAereo_setPrecioPorKg(this,precioPorKG);

				//Si sale bien devuelvo 0 ya que el transporte aereo quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoSetterConstanteVolumetrica == 0 && resultadoSetterPrecioPorKG == 0)
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

	int transAereo_setAllParamsTxt(TransporteAereo* this, char* constanteVolumetrica, char* precioPorKG)
	{
		int retorno = -1;

		//Valido parametros
		if (constanteVolumetrica != NULL && precioPorKG != NULL)
			{
				int resultadoSetterConstanteVolumetricaTxt;
				int resultadoSetterPrecioPorKGTxt;

				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoSetterConstanteVolumetricaTxt = transAereo_setConstanteVolumetricaTxt (this,constanteVolumetrica);
				resultadoSetterPrecioPorKGTxt = transAereo_setPrecioPorKgTxt (this,precioPorKG);

				//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoSetterConstanteVolumetricaTxt == 0 && resultadoSetterPrecioPorKGTxt == 0)
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

	int transAereo_getAllParams(TransporteAereo* this, float* constanteVolumetrica, float* precioPorKG)
	{
		int retorno = -1;

		//Valido parametros
		if (constanteVolumetrica != NULL && precioPorKG != NULL)
			{
				int resultadoGetterConstanteVolumetrica;
				int resultadoGetterPrecioPorKG;


				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoGetterConstanteVolumetrica = transAereo_getConstanteVolumetrica (this,constanteVolumetrica);
				resultadoGetterPrecioPorKG = transAereo_getPrecioPorKG (this,precioPorKG);

				//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoGetterConstanteVolumetrica == 0 && resultadoGetterPrecioPorKG == 0)
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


	int transAereo_setConstanteVolumetrica(TransporteAereo* this, float constanteVolumetrica)
	{
		int retorno = -1;

		if (this != NULL && constanteVolumetrica >= 0)
		{
			retorno = -2;

			int validacionConstanteVolumetrica;
			validacionConstanteVolumetrica = esConstanteVolumetrica (constanteVolumetrica);

			if (validacionConstanteVolumetrica == 0)
			{
				this->constanteVolumetrica = constanteVolumetrica;
				retorno = 0;
			}
		}
		return retorno;
	}

	int transAereo_setConstanteVolumetricaTxt (TransporteAereo* this, char* constanteVolumetrica)
	{
		int retorno = -1;

		if (this != NULL && constanteVolumetrica != NULL)
		{
			retorno = -2;

			int validacionConstanteVolumetricaTxt;
			validacionConstanteVolumetricaTxt = esConstanteVolumetricaTxt(constanteVolumetrica,CHARACTERS_LEN);

			if (validacionConstanteVolumetricaTxt == 0)
			{
				float constanteVolumetricaFloat = atof (constanteVolumetrica);

				this->constanteVolumetrica = constanteVolumetricaFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int transAereo_getConstanteVolumetrica(TransporteAereo* this, float* constanteVolumetrica)
	{
		int retorno = -1;

		if (this != NULL && constanteVolumetrica != NULL)
		{
			retorno = -2;

			int validacionConstanteVolumetrica;
			validacionConstanteVolumetrica = esConstanteVolumetrica (this->constanteVolumetrica);

			if (validacionConstanteVolumetrica == 0)
			{
				*constanteVolumetrica = this->constanteVolumetrica;
				retorno = 0;
			}
		}
		return retorno;
	}

	int transAereo_setPrecioPorKg(TransporteAereo* this, float precioPorKg)
	{
		int retorno = -1;

		if (this != NULL && precioPorKg > 0)
		{
			retorno = -2;

			int validacionPrecioPorKg;
			validacionPrecioPorKg = esPrecioPorKg (precioPorKg);

			if (validacionPrecioPorKg == 0)
			{
				this->precioPorKg = precioPorKg;
				retorno = 0;
			}
		}
		return retorno;
	}

	int transAereo_setPrecioPorKgTxt (TransporteAereo* this, char* precioPorKg)
	{
		int retorno = -1;

		if (this != NULL && precioPorKg != NULL)
		{
			retorno = -2;

			int validacionPrecioPorKgTxt;
			validacionPrecioPorKgTxt = esPrecioPorKgTxt (precioPorKg);

			if (validacionPrecioPorKgTxt == 0)
			{
				float precioPorKgFloat = atof (precioPorKg);

				this->precioPorKg = precioPorKgFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int transAereo_getPrecioPorKG(TransporteAereo* this, float* precioPorKG)
	{
		int retorno = -1;

		if (this != NULL && precioPorKG != NULL)
		{
			retorno = -2;

			int validacionPrecioPorKG;
			validacionPrecioPorKG = esPrecioPorKg (this->precioPorKg);

			if (validacionPrecioPorKG == 0)
			{
				*precioPorKG = this->precioPorKg;
				retorno = 0;
			}
		}
		return retorno;
	}


	int calcularTransAereo_precioFinal (float baseImponible, float porcentajeImportacion, float porcentajeTasaEstadistica, float* pResultado)
	{
		int retorno = -1;

		if (baseImponible >= 0 && porcentajeImportacion >= 0 && porcentajeTasaEstadistica >= 0 && pResultado != NULL)
		{
			*pResultado = baseImponible + porcentajeImportacion + porcentajeTasaEstadistica;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_baseImponible (float valorFob, float porcentajeSeguro, float proporcionalTransporte, float* pResultado)
	{
		int retorno = -1;

		if (valorFob >= 0 && porcentajeSeguro >= 0 && proporcionalTransporte >= 0 && pResultado != NULL)
		{
			*pResultado = valorFob + porcentajeSeguro + proporcionalTransporte;

			retorno = 0;
		}

		return retorno;
	}


	int calcularTransAereo_porcentajeImportacion (float porcentajeImportacion, float baseImponible, float* pResultado)
	{
		int retorno = -1;

		if (porcentajeImportacion >= 0 && baseImponible >= 0 && pResultado != NULL)
		{
			*pResultado = (porcentajeImportacion * baseImponible) / 100;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_porcentajeTasaEstadistica (float porcentajeTasaEstadistica, float baseImponible, float* pResultado)
	{
		int retorno = -1;

		if (porcentajeTasaEstadistica >= 0 && baseImponible >= 0 && pResultado != NULL)
		{
			*pResultado = (porcentajeTasaEstadistica * baseImponible) / 100;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_porcentajeSeguro (float valorFob, float porcentajeSeguro, float* pResultado)
	{
		int retorno = -1;

		if (valorFob >= 0 && porcentajeSeguro >= 0 && pResultado != NULL)
		{
			*pResultado = (valorFob * porcentajeSeguro) / 100;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_proporcionalTransporte (float pesoVolumetrico, float pesoReal, float* pResultado)
	{
		int retorno = -1;

		if (pesoVolumetrico >= 0 && pesoReal >= 0 && pResultado != NULL)
		{
			if (pesoVolumetrico > pesoReal)
			{
				*pResultado = pesoVolumetrico;
			}
			else if (pesoReal > pesoVolumetrico)
			{
				*pResultado = pesoReal;
			}
			else
			{
				*pResultado = pesoReal;
			}

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_pesoReal (float pesoKgArticulo, float precioPorKg, float* pResultado)
	{
		int retorno = -1;

		if (pesoKgArticulo >= 0 && precioPorKg >= 0 && pResultado != NULL)
		{
			*pResultado = pesoKgArticulo * precioPorKg;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_pesoVolumetrico (float dimensiones, float constanteVolumetrica, float precioPorKg, float* pResultado)
	{
		int retorno = -1;

		if (dimensiones >= 0 && constanteVolumetrica >= 0 && precioPorKg >= 0 && pResultado != NULL)
		{
			*pResultado = (dimensiones / constanteVolumetrica) * precioPorKg;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_dimensiones (float ancho, float alto, float largo, float* pResultado)
	{
		int retorno = -1;

		if (ancho >= 0 && alto >= 0 && largo >= 0 && pResultado != NULL)
		{
			*pResultado = ancho * alto * largo;

			retorno = 0;
		}

		return retorno;
	}

	int calcularTransAereo_precioFinalTotal (Producto* pProducto, PosicionArancelaria* pPosArancelariaProducto, float constanteVolumetrica, float precioPorKg, float* pResultado)
	{
		int retorno = -1;

		if (pProducto != NULL && pPosArancelariaProducto != NULL && constanteVolumetrica >= 0 && precioPorKg >= 0 && pResultado != NULL)
		{

			//Obtengo valor fob y porcentaje seguro de pArancelaria.
			float valorFobUSD;
			producto_getValorFobUSD(pProducto,&valorFobUSD);

			float porcentajeSeguro;
			pArancelaria_getPorcentajeSeguro(pPosArancelariaProducto,&porcentajeSeguro);

			//Calculo el nuevo valor de porcentaje seguro.
			calcularTransAereo_porcentajeSeguro (valorFobUSD,porcentajeSeguro,&porcentajeSeguro);

			//Calculo peso volumetrico y peso real para calcular proporcional transporte.

			//---peso real.
			float pesoKgProducto;
			producto_getPeso (pProducto,&pesoKgProducto);

			float pesoReal;
			calcularTransAereo_pesoReal (pesoKgProducto,precioPorKg, &pesoReal);

			//---peso vol.

			float ancho;
			float alto;
			float largo;

			producto_getAnchoEmpaque(pProducto,&ancho);
			producto_getAltoEmpaque(pProducto,&alto);
			producto_getLargoEmpaque(pProducto,&largo);

			float dimensiones;
			calcularTransAereo_dimensiones (ancho,alto,largo,&dimensiones);

			float pesoVolumetrico;
			calcularTransAereo_pesoVolumetrico (dimensiones,constanteVolumetrica,precioPorKg,&pesoVolumetrico);

			//Ya con el peso volumetrico y el peso real calculo el proporcional transporte.
			float proporcionalTransporte;
			calcularTransAereo_proporcionalTransporte (pesoVolumetrico,pesoReal,&proporcionalTransporte);

			//Calculo la base imponible.
			float baseImponible;
			calcularTransAereo_baseImponible (valorFobUSD,porcentajeSeguro,proporcionalTransporte,&baseImponible);

			//Obtengo porcentaje importacion y tasa estadisitica para calcular porcentaje Importacion y porcentaje Tasa estadistica.
	 		float porcentajeImportacion;
			pArancelaria_getPorcentajeImportacion(pPosArancelariaProducto,&porcentajeImportacion);

			float porcentajeTasaEstadistica;
			pArancelaria_getPorcentajeTasaEstadistica(pPosArancelariaProducto,&porcentajeTasaEstadistica);

			//Calculo nuevo porcentaje importacion y tasa estadistica.
			calcularTransAereo_porcentajeImportacion (porcentajeImportacion,baseImponible,&porcentajeImportacion);

			calcularTransAereo_porcentajeTasaEstadistica (porcentajeTasaEstadistica,baseImponible,&porcentajeTasaEstadistica);

			//Calculo el resultado final.
			float precioFinal;
			calcularTransAereo_precioFinal (baseImponible,porcentajeImportacion,porcentajeTasaEstadistica,&precioFinal);

			*pResultado = precioFinal;

			retorno = 0;
		}

		return retorno;
	}


	int loadFromTxt_ConstanteVolumetrica_y_precioPorKG (char* path, float* pConstanteVolumetricaLeida, float* pPrecioPorKG)
	{
		int retorno = -1;

		if (path != NULL && pConstanteVolumetricaLeida != NULL)
		{

			FILE* pFile;
			pFile = fopen (path,"r");

			if (pFile != NULL)
			{

				int resultadoParser;
				resultadoParser = parser_precio_ConstanteVolumetrica_y_precioPorKg_FromTxt (pFile,pConstanteVolumetricaLeida,pPrecioPorKG);

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


	int parser_precio_ConstanteVolumetrica_y_precioPorKg_FromTxt (FILE* pFile, float* pConstanteVolumetricaLeida, float* pPrecioPorKG)
	{
		int retorno = -1;

		if (pFile != NULL && pConstanteVolumetricaLeida != NULL)
		{
			retorno = -2;

			int resultadoFscanf;

			float constanteVolumetrica;
			float precioPorKG;

			do{

				resultadoFscanf = fscanf(pFile,"%f,%f\n",&constanteVolumetrica,&precioPorKG);

			}while(feof(pFile) == 0);


			//Si se cargaron las variables deberia devolver 2
			if(resultadoFscanf == 2)
			{
				retorno = -3;

				//Los valido
				int resultadoValidacionConstanteVolumetrica;
				int resultadoValidacionPrecioPorKG;

				resultadoValidacionConstanteVolumetrica = esConstanteVolumetrica (constanteVolumetrica);
				resultadoValidacionPrecioPorKG = esPrecioValido (precioPorKG);

				if (resultadoValidacionConstanteVolumetrica == 0 && resultadoValidacionPrecioPorKG == 0)
				{
					//Lo devuelvo
					*pConstanteVolumetricaLeida = constanteVolumetrica;
					*pPrecioPorKG = precioPorKG;

					retorno = 0;
				}
			}
		}

		return retorno;
	}


	int save_valuesTransporteAereo (char* path, TransporteAereo* this)
	{
		int retorno = -1;

		if (path != NULL && this != NULL)
		{
			TransporteAereo aux;

			FILE* filePuntero;
			filePuntero = fopen (path,"w");

			if (filePuntero != NULL)
			{

				//Guardo en aux los campos de pPosicionArancelariall;
				int resultadoObtencionValidacion;
				resultadoObtencionValidacion = transAereo_getAllParams (this,&aux.constanteVolumetrica,&aux.precioPorKg);

				if (resultadoObtencionValidacion == 0)
				{
					fprintf (filePuntero,"%f,%f\n",aux.constanteVolumetrica,aux.precioPorKg);
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

