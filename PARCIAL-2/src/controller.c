
	/*
	 * controller.c
	 *
	 *  Created on: 16 jun. 2021
	 *      Author: gabil
	 */

	#include <stdio.h>
	#include <stdlib.h>

	#include "LinkedList.h"
	#include "string.h"
	#include "Producto.h"
	#include "Dictionary.h"
	#include "PosicionArancelaria.h"
	#include "utn.h"
	#include "TransporteMaritimo.h"
	#include "TransporteAereo.h"

	/**
	 * \brief Alta de productos.
	 * \param valorMaximoExistenteID int El valor maximo existente del ID (al llamar a la funcion).
	 * \param pArrayListEmployee LinkedList* Lista de empleados.
	 * \return int Retorna 0 si el empleado fue anadido a la linkedList. Si no un numero menor a 0.
	 */
	int controller_addProducto(Dictionary* pDiccionarioProductos, Dictionary* pDiccionarioPosicionesArancelarias, int* pValorIDMaximoProductos,TransporteMaritimo* pValoresTransMaritimo, TransporteAereo* pValoresTransAereo)
	{
		int retorno = -1;

		if (pDiccionarioProductos != NULL && pDiccionarioPosicionesArancelarias != NULL && pValorIDMaximoProductos != NULL && pValoresTransMaritimo != NULL  && pValoresTransAereo != NULL)
		{
			retorno = -2;

			//Pido memoria para un nuevo producto.
			Producto* pNewProducto;
			pNewProducto = producto_new();

			//Si hubo lugar y se obtuvo un puntero, sigo.
			if (pNewProducto != NULL)
			{
				int resultadoObtencionDeDatosPorConsola;
				resultadoObtencionDeDatosPorConsola = getAllFieldsFromConsoleValidatedProduct (pNewProducto,pNewProducto->nombre,&pNewProducto->pesokg,pNewProducto->descripcion,pNewProducto->paisOrigen,pNewProducto->codigoAlfanumerico,&pNewProducto->largoEmpaque,&pNewProducto->altoEmpaque,&pNewProducto->anchoEmpaque,&pNewProducto->valorFobUSD,&pNewProducto->idPosicionArancelaria);

				//Obtengo ese id y lo transformo a char para buscar por key.
				char auxKeyIDPosicionArancelaria[CHARACTERS_LEN];
				snprintf(auxKeyIDPosicionArancelaria,sizeof(auxKeyIDPosicionArancelaria),"%d",pNewProducto->idPosicionArancelaria);

				PosicionArancelaria* pPosicionArancelariaEncontrada;
				pPosicionArancelariaEncontrada = dict_get(pDiccionarioPosicionesArancelarias,auxKeyIDPosicionArancelaria);

				//Si la obtencion salio bien y definitivamente me ingresaron algo valido. Resta completar y calcular los demas campos con las funciones pertinentes.
				if (resultadoObtencionDeDatosPorConsola == 0 && pPosicionArancelariaEncontrada != NULL)
				{
					//Le imprimo al usuario que posicion arancelaria corresponde a esa ID.
					print_posicionArancelaria (pPosicionArancelariaEncontrada);

					//Confirmar si es posicion arancelaria elegida para continuar con el alta.
					int resultadoObtencionOrden;
					resultadoObtencionOrden = utn_obtener_orden_si_no ("\n¿Es correcta la posicion arancelaria y desea continuar con el alta? Ingrese SI o NO.\n","\nError, ingrese SI o NO en mayusculas.\n", 3);

					if (resultadoObtencionOrden == 1) //Si dijo "SI"
					{

						//Me creo un nuevo valor de id.
						*pValorIDMaximoProductos = *pValorIDMaximoProductos + 1;

						//Setteo el nuevo valor ID.
						producto_setId(pNewProducto,*pValorIDMaximoProductos);

						//Me guardo el valor del ID pero en caracter para despues guardarlo en el diccionario.
						char auxKeyIDProducto[CHARACTERS_LEN];
						snprintf(auxKeyIDProducto,sizeof(auxKeyIDProducto),"%d",pNewProducto->idProducto);

						//Calculo campo de volumen.
						float volumenCalculadoCmCubico;
						calcular_volumenDeEmpaqueCENTIMETROS (pNewProducto->altoEmpaque,pNewProducto->largoEmpaque,pNewProducto->anchoEmpaque,&volumenCalculadoCmCubico);

						//Setteo el volumen calculado.
						producto_setVolumenEmpaque(pNewProducto, volumenCalculadoCmCubico);


						//--ACA EMPIEZA LA SECCION DE CALCULO PARA LOS VALORES FINALES (CAMPOS DEL PRODUCTO)---//

						//Obtengo los valores maritimos del archivo. (Los mismos que los que estan en el main).
						float precioPorMtCubico;
						float metrosCubicosContainer;

						transMaritimo_getAllParams(pValoresTransMaritimo,&metrosCubicosContainer,&precioPorMtCubico);

						//Calculo el precio final maritimo.
						float precioFinalMaritimoDelProducto;
						calcularTransMaritimo_precioFinalTotal (pNewProducto,pPosicionArancelariaEncontrada,precioPorMtCubico,metrosCubicosContainer,&precioFinalMaritimoDelProducto);


						//Obtengo los valores aereos del archivo. (Los mismos que los que estan en el main).
						float constanteVolumetrica;
						float precioPorKg;

						transAereo_getAllParams(pValoresTransAereo,&constanteVolumetrica,&precioPorKg);

						float precioFinalAereoDelProducto;
						calcularTransAereo_precioFinalTotal (pNewProducto,pPosicionArancelariaEncontrada,constanteVolumetrica,precioPorKg,&precioFinalAereoDelProducto);


						//Setteo ambos valores valores, el precio maritimo calculado y el precio aereo calculado.
						int resultadoSetterPrecioFinalMar;
						int resultadoSetterPrecioFinalAire;
						resultadoSetterPrecioFinalMar = producto_setPrecioTransporteByMar(pNewProducto,precioFinalMaritimoDelProducto);
						resultadoSetterPrecioFinalAire = producto_setPrecioTransporteByAir(pNewProducto,precioFinalAereoDelProducto);

						//printProducto(pNewProducto);

						//Si los valores fueron seteados correctamente.
						if (resultadoSetterPrecioFinalMar == 0 && resultadoSetterPrecioFinalAire == 0)
						{
							//Inserto el producto en el diccionario.
							dict_insert(pDiccionarioProductos,auxKeyIDProducto,pNewProducto);

							//Guardo el nuevo producto en el archivo de productos. (RECORRO LA LL Y GUARDO DESDE 0 TODOS LOS PRODUCTOS).
							save_productos ("ListaProductos.csv",pDiccionarioProductos);

							printf ("\nEl alta ha sido satisfactoria.\n");
						}
						else
						{
							printf ("\nError en el resultado de los calculos correspondientes a los datos del producto. El alta fue cancelada.\n");
							producto_delete (pNewProducto);
							retorno = -6;
						}

					}
					else if (resultadoObtencionOrden == 0) //Si no si dijo que "NO"
					{
						producto_delete (pNewProducto);
						printf ("\nEl alta del producto fue cancelada debido a que la posicion arancelaria que se ingreso fue incorrecta.\n");
						retorno = -7;
					}
					else //Si no dijo ni "SI" ni "NO"
					{
						producto_delete (pNewProducto);
						printf ("\nEl alta del producto fue cancelada debido a que la posicion arancelaria no fue confirmada si era o no la correcta.\n");
						retorno = -8;
					}

				}
				else
				{
					//Borro la memoria pedida si salio mal el pedido de datos basicos.
					producto_delete (pNewProducto);

					if(resultadoObtencionDeDatosPorConsola != 0)
					{
						printf ("\nEl producto no ha sido dado de alta debido a errores en la obtencion de sus datos.\n");
						retorno = -4;
					}
					else if (pPosicionArancelariaEncontrada == NULL)
					{
						printf ("\nNo se pudo encontrar una posicion arancelaria con ese id.\n");
						retorno = -5;
					}
				}
			}
			else
			{
				retorno = -3;
				printf ("\nNo hay mas lugar en memoria para dar de alta un nuevo empleado.\n");
			}
		}

		return retorno;
	}

	int controller_deleteProducto(Dictionary* listaProductos)
	{
		int retorno = -1;

		if (listaProductos != NULL)
		{
			retorno = -2;

			//Pido id
			int idparaBuscar;
			int resultadoObtencionIDAborrar;
			resultadoObtencionIDAborrar = utn_getNumero(&idparaBuscar,"\nIngrese el ID del producto que desea borrar.\n","\nError en el ingreso del id a borrar.\n", 1,9999999,3);

			if (resultadoObtencionIDAborrar == 0)
			{
				//Lo convierto a char para buscarlo como key
				char idParaBuscarChar[CHARACTERS_LEN];
				snprintf(idParaBuscarChar,sizeof(idParaBuscarChar),"%d",idparaBuscar);

				//Busco la key con esa id
				Producto* pProductoEncontrado;
				pProductoEncontrado = dict_get(listaProductos,idParaBuscarChar);

				if (pProductoEncontrado != NULL)
				{
					//Imprimo al usuario el producto
					printf ("\nEl producto que se dara de baja es el siguiente:\n");
					printProducto (pProductoEncontrado);

					//Pido confirmacion
					int ordenConfirmacion;
					ordenConfirmacion = utn_obtener_orden_si_no ("\n¿Desea confirmar la eliminacion? Ingrese SI o NO.\n","\nError, ingrese SI o NO.\n",3);

					if (ordenConfirmacion == 1)
					{

						//Remuevo el producto del dict.
						dict_remove(listaProductos,idParaBuscarChar);

						//Guardo cambios en archivo de productos.
						save_productos ("ListaProductos.csv",listaProductos);
						printf ("\nLa baja ha sido satisfactoria.\n");

					}
					else if (ordenConfirmacion == 0)
					{
						printf ("\nLa baja del producto fue cancelada.\n");
						retorno = -3;
					}
					else
					{
						printf ("\nLa baja del producto fue cancelada debido a que la confirmacion no salio bien.\n");
						retorno = -4;
					}
				}
				else
				{
					printf ("\nNo se pudo encontrar un producto con esa id.\n");
					retorno = -3;
				}
			}
		}

		return retorno;
	}

	int controller_modifyProducto(Dictionary* listaProductos, Dictionary* listapArancelarias, TransporteMaritimo* pValoresTransMaritimo, TransporteAereo* pValoresTransAereo)
	{
		int retorno = -1;

		if (listaProductos != NULL && listapArancelarias != NULL && pValoresTransMaritimo != NULL && pValoresTransAereo != NULL)
		{
			retorno = -2;

			//Pido id
			int idparaBuscar;
			int resultadoObtencionIDAModificar;
			resultadoObtencionIDAModificar = utn_getNumero(&idparaBuscar,"\nIngrese el ID del producto que desea modificar.\n","\nError en el ingreso del id.\n", 1,9999999,3);

			if (resultadoObtencionIDAModificar == 0)
			{
				//Lo convierto a char para buscarlo como key
				char idParaBuscarProd[CHARACTERS_LEN];
				snprintf(idParaBuscarProd,sizeof(idParaBuscarProd),"%d",idparaBuscar);

				//Busco la key con esa id
				Producto* pProductoEncontrado;
				pProductoEncontrado = dict_get(listaProductos,idParaBuscarProd);

				if (pProductoEncontrado != NULL)
				{
					//Imprimo al usuario el producto
					printf ("\nEl producto que se va a modificar es el siguiente:\n");
					printProducto (pProductoEncontrado);

					//Pido confirmacion
					int ordenConfirmacion;
					ordenConfirmacion = utn_obtener_orden_si_no ("\n¿El producto que desea modificar es el impreso? Ingrese SI o NO.\n","\nError, ingrese SI o NO.\n",3);

					if (ordenConfirmacion == 1)
					{
						//Obtengo los nuevos datos
						int resultadoObtencionDeDatosPorConsola;
						resultadoObtencionDeDatosPorConsola = getAllFieldsFromConsoleValidatedProduct (pProductoEncontrado,pProductoEncontrado->nombre,&pProductoEncontrado->pesokg,pProductoEncontrado->descripcion,pProductoEncontrado->paisOrigen,pProductoEncontrado->codigoAlfanumerico,&pProductoEncontrado->largoEmpaque,&pProductoEncontrado->altoEmpaque,&pProductoEncontrado->anchoEmpaque,&pProductoEncontrado->valorFobUSD,&pProductoEncontrado->idPosicionArancelaria);

						if (resultadoObtencionDeDatosPorConsola == 0)
						{
							char idParaBuscarPosAran[CHARACTERS_LEN];
							snprintf(idParaBuscarPosAran,sizeof(idParaBuscarPosAran),"%d",pProductoEncontrado->idPosicionArancelaria);

							PosicionArancelaria* pPosArancelariaEncontrada;
							pPosArancelariaEncontrada = dict_get(listapArancelarias,idParaBuscarPosAran);

							if (pPosArancelariaEncontrada != NULL)
							{
								//Calculo y seteo campo de volumen.
								float volumenCalculadoCmCubico;
								calcular_volumenDeEmpaqueCENTIMETROS (pProductoEncontrado->altoEmpaque,pProductoEncontrado->largoEmpaque,pProductoEncontrado->anchoEmpaque,&volumenCalculadoCmCubico);
								producto_setVolumenEmpaque(pProductoEncontrado, volumenCalculadoCmCubico);


								//--ACA EMPIEZA LA SECCION DE CALCULO PARA LOS VALORES FINALES (CAMPOS DEL PRODUCTO)---//

								//Obtengo los valores maritimos del archivo. (Los mismos que los que estan en el main).
								float precioPorMtCubico;
								float metrosCubicosContainer;

								transMaritimo_getAllParams(pValoresTransMaritimo,&metrosCubicosContainer,&precioPorMtCubico);

								//Calculo el precio final maritimo.
								float precioFinalMaritimoDelProducto;
								calcularTransMaritimo_precioFinalTotal (pProductoEncontrado,pPosArancelariaEncontrada,precioPorMtCubico,metrosCubicosContainer,&precioFinalMaritimoDelProducto);


								//Obtengo los valores aereos del archivo. (Los mismos que los que estan en el main).
								float constanteVolumetrica;
								float precioPorKg;

								transAereo_getAllParams(pValoresTransAereo,&constanteVolumetrica,&precioPorKg);

								float precioFinalAereoDelProducto;
								calcularTransAereo_precioFinalTotal (pProductoEncontrado,pPosArancelariaEncontrada,constanteVolumetrica,precioPorKg,&precioFinalAereoDelProducto);


								//Setteo ambos valores valores, el precio maritimo calculado y el precio aereo calculado.
								int resultadoSetterPrecioFinalMar;
								int resultadoSetterPrecioFinalAire;
								resultadoSetterPrecioFinalMar = producto_setPrecioTransporteByMar(pProductoEncontrado,precioFinalMaritimoDelProducto);
								resultadoSetterPrecioFinalAire = producto_setPrecioTransporteByAir(pProductoEncontrado,precioFinalAereoDelProducto);

								//printProducto(pNewProducto);

								//Si los valores fueron seteados correctamente.
								if (resultadoSetterPrecioFinalMar == 0 && resultadoSetterPrecioFinalAire == 0)
								{
									//Guardo cambios en archivo de productos para efectuar la modificacion.
									save_productos ("ListaProductos.csv",listaProductos);
									printf ("\nLa modificacion ha sido satisfactoria. Se guardaron y re-calcularon los nuevos valores.\n");
								}
								else
								{
									printf ("\nError en el resultado de los calculos correspondientes a los datos del producto. La modificacion fue cancelada.\n");
									retorno = -7;
								}
							}
							else
							{
								printf ("\nError, no se pudo encontrar una posicion arancelaria que coincida con el id ingresado. La modificacion fue cancelada.\n");
								retorno = -6;
							}
						}
						else
						{
							printf ("Error en la obtencion de los nuevos datos.");
						}
					}
					else if (ordenConfirmacion == 0)
					{
						printf ("\nLa modificacion producto fue cancelada.\n");
						retorno = -5;
					}
					else
					{
						printf ("\nLa modificacion del producto fue cancelada debido a que la confirmacion no salio bien.\n");
						retorno = -4;
					}
				}
				else
				{
					printf ("\nNo se pudo encontrar un producto con esa id.\n");
					retorno = -3;
				}

			}
			else
			{
				printf ("\nError en la obtencion del id del producto a modificar.\n");
				retorno = -2;
			}
		}


		return retorno;
	}

	int controller_listarProductos (Dictionary* pListaProductos)
	{
		int retorno = -1;

		if (pListaProductos != NULL)
		{
			retorno = -2;

			LinkedList* llProductos;

			llProductos = dict_getValues(pListaProductos);

			controller_ListProduct(llProductos);

			ll_deleteLinkedList(llProductos);

		}

		return retorno;
	}

	/////////////////////////////////////////////////

	int controller_newValuesTransporteByMar (char* path, TransporteMaritimo* pValoresActuales)
	{
		int retorno = -1;

		if (path != NULL && pValoresActuales != NULL)
		{
			retorno = -2;

			//Muestro los valores actuales
			printf ("\nLos valores actuales de precio por metro cubico y metros cubicos del container son los siguientes:\n");
			print_transporteMaritimo(pValoresActuales);

			//Pido confirmacion
			int ordenConfirmacion;
			ordenConfirmacion = utn_obtener_orden_si_no ("\n\nPara confirmar su modificacion ingrese SI o NO\n","\nError, ingrese SI o NO.\n",3);

			if (ordenConfirmacion == 1)
			{
				int resultadoObtencionPrecioMetroCubico;
				int resultadoObtencionMetrosCubicos;

				//Pido nuevos valores
				float precioPorMetroCubico;
				resultadoObtencionPrecioMetroCubico = utn_getNumeroFlotante(&precioPorMetroCubico,"\nIngrese el nuevo valor del precio por metro cubico del container.\n","\nError en el ingreso del nuevo valor.\n",0,99999999,3);

				float metrosCubicosContainer;
				resultadoObtencionMetrosCubicos = utn_getNumeroFlotante(&metrosCubicosContainer,"\nIngrese el nuevo valor de los metros cubicos del container.\n","\nError en el ingreso del nuevo valor.\n",0,99999999,3);

				//Si obtuve nuevos datos razonables valido seteando los valores a la entidad.
				if (resultadoObtencionPrecioMetroCubico == 0 && resultadoObtencionMetrosCubicos == 0)
				{
					int resultadoValidacionValores;
					resultadoValidacionValores = transMaritimo_setAllParams(pValoresActuales,precioPorMetroCubico,metrosCubicosContainer);

					if (resultadoValidacionValores == 0)
					{
						//Si salio bien el setteo guardo en el archivo los nuevos valores.
						save_valuesTransporteMaritimo (path,pValoresActuales);

						printf ("\nLos valores fueron actualizados correctamente.\n");
						retorno = 0;
					}
					else
					{
						retorno = -6;
						printf ("\nLos valores fueron validados y no son correctos.\n");
					}


				}
				else
				{
					printf ("\nLa obtencion de los nuevos valores no salio bien. La modificacion fue cancelada.\n");
					retorno = -5;
				}
			}
			else if (ordenConfirmacion == 0)
			{
				printf ("\nLa modificacion de los valores maritimos fue cancelada.\n");
				retorno = -3;
			}
			else
			{
				printf ("\nLa modificacion de los valores maritimos fue cancelada debido a que la confirmacion no salio bien.\n");
				retorno = -4;
			}

		}


		return retorno;
	}

	int controller_newValuesTransporteByAir (char* path, TransporteAereo* pValoresActuales)
	{
		int retorno = -1;

		if (path != NULL && pValoresActuales != NULL)
		{
			retorno = -2;

			//Muestro los valores actuales
			printf ("\nLos valores actuales de constante volumetrica y precio por kg del articulo son los siguientes:\n");
			print_transporteAereo(pValoresActuales);

			//Pido confirmacion
			int ordenConfirmacion;
			ordenConfirmacion = utn_obtener_orden_si_no ("\n\nPara confirmar su modificacion ingrese SI o NO\n","\nError, ingrese SI o NO.\n",3);

			if (ordenConfirmacion == 1)
			{
				int resultadoObtencionConstanteVolumetrica;
				int resultadoObtencionPrecioPorKG;

				//Pido nuevos valores
				float constanteVolumetrica;
				resultadoObtencionConstanteVolumetrica = utn_getNumeroFlotante(&constanteVolumetrica,"\nIngrese el nuevo valor de la constante volumetrica.\n","\nError en el ingreso del nuevo valor.\n",0,99999999,3);

				float precioPorKG;
				resultadoObtencionPrecioPorKG = utn_getNumeroFlotante(&precioPorKG,"\nIngrese el nuevo valor del precio por kg.\n","\nError en el ingreso del nuevo valor.\n",0,99999999,3);

				//Si obtuve nuevos datos razonables valido seteando los valores a la entidad.
				if (resultadoObtencionConstanteVolumetrica == 0 && resultadoObtencionPrecioPorKG == 0)
				{
					int resultadoValidacionValores;
					resultadoValidacionValores = transAereo_setAllParams(pValoresActuales,constanteVolumetrica,precioPorKG);

					if (resultadoValidacionValores == 0)
					{
						//Si salio bien el setteo guardo en el archivo los nuevos valores.
						save_valuesTransporteAereo (path,pValoresActuales);

						printf ("\nLos valores fueron actualizados correctamente.\n");
						retorno = 0;
					}
					else
					{
						retorno = -6;
						printf ("\nLos valores fueron validados y no son correctos.\n");
					}


				}
				else
				{
					printf ("\nLa obtencion de los nuevos valores no salio bien. La modificacion fue cancelada.\n");
					retorno = -5;
				}
			}
			else if (ordenConfirmacion == 0)
			{
				printf ("\nLa modificacion de los valores aereos fue cancelada.\n");
				retorno = -3;
			}
			else
			{
				printf ("\nLa modificacion de los valores aereos fue cancelada debido a que la confirmacion no salio bien.\n");
				retorno = -4;
			}

		}


		return retorno;
	}


	/////////////////////////////////////////////////

	int controller_addPosicionArancelaria (Dictionary* pListaPosicionesArancelarias, int* pValorIDMaximopArancelaria)
	{
		int retorno = -1;

		if (pListaPosicionesArancelarias != NULL && pValorIDMaximopArancelaria != NULL)
		{

			//Pido memoria para una nueva posicion arancelaria.
			PosicionArancelaria* pNewPosicionArancelaria;
			pNewPosicionArancelaria = pArancelaria_new();

			if (pListaPosicionesArancelarias != NULL && pNewPosicionArancelaria != NULL)
			{
				retorno = -2;

				//Obtengo campos de la posicion arancelaria
				int resultadoObtencionDatosPorConsola;
				resultadoObtencionDatosPorConsola = pArancelaria_getAllFieldFromConsoleValidated (pNewPosicionArancelaria);

				//Si la obtencion salio bien y definitivamente me ingresaron algo valido seteo los campos
				if (resultadoObtencionDatosPorConsola == 0)
				{
					//Me creo un nuevo valor de id.
					*pValorIDMaximopArancelaria = *pValorIDMaximopArancelaria + 1;

					//Setteo el nuevo valor ID.
					pArancelaria_setId(pNewPosicionArancelaria,*pValorIDMaximopArancelaria);

					//Me guardo el valor del ID pero en caracter para despues guardarlo en el diccionario.
					char auxKeyIDProducto[CHARACTERS_LEN];
					snprintf(auxKeyIDProducto,sizeof(auxKeyIDProducto),"%d",pNewPosicionArancelaria->idPosicionArancelaria);

					//Inserto la nueva pArancelaria en el diccionario.
					dict_insert(pListaPosicionesArancelarias,auxKeyIDProducto,pNewPosicionArancelaria);

					//Guardo el nuevo producto en el archivo de productos. (RECORRO LA LL Y GUARDO DESDE 0 TODOS LAS POSICIONES ARANCELARIAS).
					save_pArancelaria ("ListaPosicionesArancelarias.csv",pListaPosicionesArancelarias);

					printf ("\nEl alta ha sido satisfactoria.\n");

				}
				else
				{
					//Borro la memoria pedida si salio mal el pedido de datos basicos.
					retorno = -4;

					pArancelaria_delete (pNewPosicionArancelaria);
					printf ("\nLa posicion arancelaria no ha sido dado de alta debido a errores en la obtencion de sus datos.\n");
				}
			}
			else
			{
				retorno = -3;
				printf ("\nNo hay mas lugar en memoria para dar de alta un nuevo empleado.\n");
			}
		}

		return retorno;
	}

	int controller_deletePosicionArancelaria (Dictionary* plistaProductos, Dictionary* listaPosicionesArancelarias)
	{
		int retorno = -1;

		if (plistaProductos != NULL && listaPosicionesArancelarias != NULL)
		{
			retorno = -2;

			//Pido id
			int idparaBuscar;
			int resultadoObtencionIDAborrar;
			resultadoObtencionIDAborrar = utn_getNumero(&idparaBuscar,"\nIngrese el ID del tipo de licencia que desea borrar.\n","\nError en el ingreso del id a borrar.\n", 1,9999999,3);

			if (resultadoObtencionIDAborrar == 0)
			{
				//Lo convierto a char para buscarlo como key
				char idParaBuscarChar[CHARACTERS_LEN];
				snprintf(idParaBuscarChar,sizeof(idParaBuscarChar),"%d",idparaBuscar);

				//Busco la key con esa id
				PosicionArancelaria* pArancelariaEncontrada;
				pArancelariaEncontrada = dict_get(listaPosicionesArancelarias,idParaBuscarChar);

				if (pArancelariaEncontrada != NULL)
				{
					//Imprimo al usuario la pArancelaria
					printf ("\nLa posicion arancelaria que se dara de baja es la siguiente:\n");
					print_posicionArancelaria (pArancelariaEncontrada);

					//Pido confirmacion
					int ordenConfirmacion;
					ordenConfirmacion = utn_obtener_orden_si_no ("\n¿Desea confirmar la eliminacion? Ingrese SI o NO.\n","\nError, ingrese SI o NO.\n",3);

					if (ordenConfirmacion == 1)
					{

						//Cuando me confirman ese id busco en la lista de productos si existe algun producto que utilice el id.
						LinkedList* productos_ll;
						Producto* productoEncontrado;

						productos_ll = dict_getValues(plistaProductos);
						productoEncontrado = producto_buscarPorIdPosArancelaria (productos_ll,idparaBuscar);

						if (productoEncontrado != NULL)
						{
							printf ("\nLa baja de la posicion arancelaria no puede ser posible si hay uno o mas productos existentes usandola. Antes debe eliminarlos o modificar el id de la posicion arancelaria.\n");
							retorno = -5;
						}
						else if (productoEncontrado == NULL) //No se encontro un producto existente con esa posArancelaria
						{
							//Remuevo la pArancelaria del dict.
							dict_remove(listaPosicionesArancelarias,idParaBuscarChar);

							//Guardo cambios en archivo.
							save_pArancelaria ("ListaPosicionesArancelarias.csv",listaPosicionesArancelarias);
							printf ("\nLa baja ha sido satisfactoria.\n");
						}

						//Borro la linkedlist que la uso unicamente para buscar si existe un producto con esa posicion Arancelaria, independientemente de como salga la busqueda.
						ll_deleteLinkedList(productos_ll);

					}
					else if (ordenConfirmacion == 0)
					{
						printf ("\nLa baja de la posicion arancelaria fue cancelada.\n");
						retorno = -3;
					}
					else
					{
						printf ("\nLa baja de la posicion arancelaria fue cancelada debido a que la confirmacion no salio bien.\n");
						retorno = -4;
					}
				}
				else
				{
					printf ("\nNo se pudo encontrar una posicion arancelaria con esa id.\n");
					retorno = -3;
				}
			}
		}

		return retorno;
	}

	int controller_modificatePosicionArancelaria (Dictionary* plistaProductos, Dictionary* listaPosicionesArancelarias)
	{
		int retorno = -1;

		if (plistaProductos != NULL && listaPosicionesArancelarias != NULL)
		{
			retorno = -2;

			//Pido id
			int idparaBuscar;
			int resultadoObtencionIDAModificar;
			resultadoObtencionIDAModificar = utn_getNumero(&idparaBuscar,"\nIngrese el ID del tipo de licencia que desea modificar.\n","\nError en el ingreso del id a modificar.\n", 1,9999999,3);

			if (resultadoObtencionIDAModificar == 0)
			{
				retorno = -3;

				//Lo convierto a char para buscarlo como key
				char idParaBuscarChar[CHARACTERS_LEN];
				snprintf(idParaBuscarChar,sizeof(idParaBuscarChar),"%d",idparaBuscar);

				//Busco la key con esa id
				PosicionArancelaria* pArancelariaEncontrada;
				pArancelariaEncontrada = dict_get(listaPosicionesArancelarias,idParaBuscarChar);

				if (pArancelariaEncontrada != NULL)
				{
					retorno = -4;

					//Imprimo al usuario la pArancelaria
					printf ("\nLa posicion arancelaria que se modificara a continuacion es la siguiente:\n");
					print_posicionArancelaria (pArancelariaEncontrada);

					//Pido confirmacion
					int ordenConfirmacion;
					ordenConfirmacion = utn_obtener_orden_si_no ("\n¿Desea confirmar la modificacion de esta posicion arancelaria? Ingrese SI o NO.\n","\nError, ingrese SI o NO.\n",3);

					if (ordenConfirmacion == 1)
					{
						retorno = -5;

						//Cuando me confirman ese id busco en la lista de productos si existe algun producto que utilice el id.
						LinkedList* productos_ll;
						Producto* productoEncontrado;

						productos_ll = dict_getValues(plistaProductos);
						productoEncontrado = producto_buscarPorIdPosArancelaria (productos_ll,idparaBuscar);

						if (productoEncontrado != NULL)
						{
							printf ("\nLa modificacion de la posicion arancelaria no puede ser posible si hay uno o mas productos existentes usandola. Antes debe eliminarlos o modificar el id de la posicion arancelaria.\n");
							retorno = -5;
						}
						else if (productoEncontrado == NULL) //No se encontro un producto existente con esa posArancelaria
						{

							//Pido nuevos datos de esta posicion arancelaria.
							printf ("\nA continuacion se le pediran los nuevos datos pertenecientes a esta posicion arancelaria.\n");
							int resultadoObtencionDatosPorConsola;
							resultadoObtencionDatosPorConsola = pArancelaria_getAllFieldFromConsoleValidated (pArancelariaEncontrada);

							//Si la obtencion de los nuevos datos salio bien y definitivamente me ingresaron algo valido
							if (resultadoObtencionDatosPorConsola == 0)
							{
								//No hago mas nada con el diccionario porque los datos ya fueron pisados por los setters.

								//Guardo cambios en archivo.
								save_pArancelaria ("ListaPosicionesArancelarias.csv",listaPosicionesArancelarias);
								printf ("\nLa modificacion ha sido satisfactoria.\n");
								retorno = 0;
							}
							else
							{
								retorno = -6;
								printf ("\nError en la obtencion de los nuevos datos de la posicion arancelaria. La modificacion fue cancelada.\n");
							}

						}

						//Borro la linkedlist que la uso unicamente para verificar si existe un producto con esa posicion Arancelaria, independientemente de como salga la busqueda.
						ll_deleteLinkedList(productos_ll);

					}
					else if (ordenConfirmacion == 0)
					{
						printf ("\nLa baja de la posicion arancelaria fue cancelada.\n");
						retorno = -4;
					}
					else
					{
						printf ("\nLa baja de la posicion arancelaria fue cancelada debido a que la confirmacion no salio bien.\n");
						retorno = -5;
					}
				}
				else
				{
					printf ("\nNo se pudo encontrar una posicion arancelaria con esa id.\n");
					retorno = -3;
				}
			}


		}

		return retorno;
	}


	int controller_listarPosicionesArancelarias (Dictionary* pListaPArancelarias)
	{
		int retorno = -1;

		if (pListaPArancelarias != NULL)
		{
			retorno = -2;

			LinkedList* llPArancelarias;

			llPArancelarias = dict_getValues(pListaPArancelarias);

			controller_ListPArancelaria(llPArancelarias);

		}

		return retorno;
	}

	int controller_finalActions (Dictionary* listaProductos, Dictionary* listaPArancelarias)
	{
		int retorno = -1;

		if (listaProductos != NULL && listaPArancelarias != NULL)
		{
			retorno = 0;

			//Borro los dos diccionarios y me despido.
			dict_deleteDictionary(listaProductos);
			dict_deleteDictionary(listaPArancelarias);
			printMensajeDespedida();
		}


		return retorno;
	}



