
/*
	 ============================================================================
	 Name        : PARCIAL-2.c
	 Author      : Gabriel Lopez G
	 Version     :
	 Copyright   : GLG
	 Description : Hello World in C, Ansi-style
	 ============================================================================
	 */

	#include <stdio.h>
	#include <stdlib.h>
	#include "string.h"

	#include "utn.h"
	#include "LinkedList.h"
	#include "Dictionary.h"
	#include "controller.h"
	#include "PosicionArancelaria.h"
	#include "Producto.h"
	#include "TransporteMaritimo.h"
	#include "TransporteAereo.h"


	int main(void)
	{
		setbuf(stdout,NULL);

		//Creo diccionarios.
		Dictionary* listaProductos;
		listaProductos = dict_new(0);

		Dictionary* listaPosicionesArancelarias;
		listaPosicionesArancelarias = dict_new(0);

		//Creo las variables que guardan valor maritimo y aereo.
		TransporteAereo valoresTransAereo;
		TransporteMaritimo valoresTransMaritimo;

		int valorIdMaxProductos = 0;
		int valorIdMaxPosicionesArancelarias = 0;

		//Cargo de los archivos la lista de productos y de posiciones arancelarias al iniciar el programa.
		valorIdMaxProductos = load_productos ("ListaProductos.csv",listaProductos);
		valorIdMaxPosicionesArancelarias = load_pArancelaria ("ListaPosicionesArancelarias.csv",listaPosicionesArancelarias);

		//Cargo de los archivos los valores maritimos y aereos al iniciar el programa.
		loadFromTxtPrecioMetroCubico ("PrecioPorMetroCubico(MAR).csv",&valoresTransMaritimo.precioPorMtCubico, &valoresTransMaritimo.mtsCubicosContainer);
		loadFromTxt_ConstanteVolumetrica_y_precioPorKG ("ConstVol-PrecioporKG.csv",&valoresTransAereo.constanteVolumetrica,&valoresTransAereo.precioPorKg);

		//printf ("\n\n CHEQUEO DE VALORES\n MAR:\n PRECIO POR METRO CUBICO: %f - METROS CUBICOS CONTAINER: %f \n AIRE: \n CONSTANTE VOLUMETRICA: %f - PRECIO POR KG: %f \n",valoresTransMaritimo.precioPorMtCubico,valoresTransMaritimo.mtsCubicosContainer,valoresTransAereo.constanteVolumetrica,valoresTransAereo.precioPorKg);

		int ordenDeMenu;

		do{
			//Imprimo menu y pido orden.
			printMenuProductos();
			utn_getNumero(&ordenDeMenu,"","", 1, 10, 0);

			//Realizo la orden
			switch(ordenDeMenu)
			{
				case 1:
				{
					//ALTA PRODUCTO
					controller_addProducto(listaProductos,listaPosicionesArancelarias,&valorIdMaxProductos,&valoresTransMaritimo,&valoresTransAereo);
					break;
				}
				case 2:
				{
					//BAJA PRODUCTO
					controller_deleteProducto(listaProductos);
					break;
				}
				case 3:
				{
					//MODIFICACION PRODUCTO
					controller_modifyProducto(listaProductos,listaPosicionesArancelarias,&valoresTransMaritimo,&valoresTransAereo);
					break;
				}
				case 4:
				{
					//LISTAR PRODUCTOS
					controller_listarProductos (listaProductos);
					break;
				}
				case 5:
				{
					//INGRESAR AL MENU POSICIONES ARANCELARIAS
					do
					{
						printMenuPosicionesArancelarias();
						utn_getNumero(&ordenDeMenu,"","", 1, 10, 0);

						switch(ordenDeMenu)
							{
								case 1:
								{
									//ALTA POSICION ARANCELARIA
									controller_addPosicionArancelaria (listaPosicionesArancelarias,&valorIdMaxPosicionesArancelarias);
									break;
								}
								case 2:
								{
									//BAJA POSICION ARANCELARIA
									controller_deletePosicionArancelaria (listaProductos,listaPosicionesArancelarias);
									break;
								}
								case 3:
								{
									//MODIFICACION POSICION ARANCELARIA
									controller_modificatePosicionArancelaria (listaProductos,listaPosicionesArancelarias);
									break;
								}
								case 4:
								{
									//LISTADO POSICIONES ARANCELARIAS
									controller_listarPosicionesArancelarias (listaPosicionesArancelarias);
									break;
								}
								case 5:
								{
									//SALIR DE MENU POSICION ARANCELARIA
									break;
								}
							}

					}while(ordenDeMenu != 5);

					break;
				}
				case 6:
				{
					//NUEVOS VALORES TRANSPORTE MARITIMO
					controller_newValuesTransporteByMar ("PrecioPorMetroCubico(MAR).csv",&valoresTransMaritimo);

					break;
				}
				case 7:
				{
					//NUEVOS VALORES TRANSPORTE AEREO
					controller_newValuesTransporteByAir ("ConstVol-PrecioporKG.csv",&valoresTransAereo);
					break;
				}
				case 8:
				{
					//SALIR
					controller_finalActions (listaProductos,listaPosicionesArancelarias);
					break;
				}
			}

		}while (ordenDeMenu != 8);

	}
