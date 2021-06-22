


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "utn.h"
	#include "Producto.h"
	#include "Dictionary.h"

	/*
	 * \brief Pide memoria necesaria para el sizeof de un producto.
	 * \return Employee* Retorna la direccion de memoria devuelta por el malloc.
	 */
	Producto* producto_new (void)
	{
		return (Producto*) malloc (sizeof(Producto));
	}


	/*
	 * \brief Hace un free de la direccion de memoria recibida por parametro.
	 * \param this Producto* Direccion de memoria recibida de tipo producto.
	 */
	void producto_delete(Producto* this)
	{
		if (this != NULL)
		{
			free (this);
			this = NULL;
		}
	}


	/*
	 * \brief Crea espacio para un nuevo producto con los campos recibidos por parametros.
	 * \param nombre char* nombre recibido.
	 * \param descripcion char* descripcion recibida.
	 * \param codigoAlfanumerico char* codigo alfanumerico recibido.
	 * \param idProducto int id del producto recibido.
	 * \param largoEmpaque float valor del largo del empaque recibido.
	 * \param altoEmpaque float valor del alto del empaque recibido.
	 * \param anchoEmpaque float valor del ancho del empaque recibido.
	 * \param volumenEmpaque float valor del volumen del empaque recibido recibido.
	 * \param valorFobUSD float valor del fob del producto en USD.
	 * \return Producto* Retorna la direccion de memoria del producto creado.
	 */
	Producto* producto_newParametros (char* nombre, float pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, int idProducto, float largoEmpaque, float altoEmpaque, float anchoEmpaque, float volumenEmpaque, float valorFobUSD, float precioTransporteByMar, float precioTransporteByAir, float idPosicionArancelaria)
	{
		Producto* pNewProducto = NULL;

		if (nombre != NULL && pesoKg > 0 && paisOrigen != NULL && descripcion != NULL && codigoAlfaNumerico != NULL && idProducto > 0 && largoEmpaque > 0 && altoEmpaque > 0 && anchoEmpaque > 0 && volumenEmpaque > 0 && valorFobUSD > 0 && precioTransporteByMar > 0 && precioTransporteByAir && idPosicionArancelaria > 0)
		{
			pNewProducto = producto_new();

			//Si se obtuvo la memoria requerida
			if (pNewProducto != NULL)
			{
				int resultadoSetAll;
				resultadoSetAll = producto_setAllParams(pNewProducto,nombre,pesoKg,paisOrigen,descripcion,codigoAlfaNumerico,idProducto,largoEmpaque,altoEmpaque,anchoEmpaque,volumenEmpaque,valorFobUSD,precioTransporteByMar,precioTransporteByAir,idPosicionArancelaria);

				if (resultadoSetAll != 0)
				{
					producto_delete(pNewProducto);
					pNewProducto = NULL;
				}
			}
			else
			{
				printf ("\nNo hay mas lugar para otro producto.\n");
			}
		}

		return pNewProducto;
	}


	//--------------------------------SETTER Y GETTERS-------------------------------

	int producto_setAllParams(Producto* this, char* nombre, float pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, int idProducto, float largoEmpaque, float altoEmpaque, float anchoEmpaque, float volumenEmpaque, float valorFobUSD, float precioTransporteByMar, float precioTransporteByAir, int idPosicionArancelaria)
	{
		int retorno = -1;

		//Valido parametros
		if (nombre != NULL && pesoKg > 0 && paisOrigen != NULL &&descripcion != NULL && codigoAlfaNumerico != NULL && idProducto > 0 && largoEmpaque > 0 && altoEmpaque > 0 && anchoEmpaque > 0 && volumenEmpaque > 0 && valorFobUSD > 0 && precioTransporteByMar > 0 && precioTransporteByAir && idPosicionArancelaria > 0)
			{
				int resultadoSetterNombre;
				int resultadoSetterPesoKg;
				int resultadoSetterPaisOrigen;
				int resultadoSetterDescripcion;
				int resultadoSetterCodigoAlfaNumerico;
				int resultadoSetterIdProducto;
				int resultadoSetterLargoEmpaque;
				int resultadoSetterAltoEmpaque;
				int resultadoSetterAnchoEmpaque;
				int resultadoSetterVolumenEmpaque;
				int resultadoSetterValorFob;
				int resultadoSetterPrecioTransporteByMar;
				int resultadoSetterPrecioTransporteByAir;
				int resultadoSetterIdPosicionArancelaria;

				//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
				resultadoSetterNombre = producto_setNombre(this,nombre);
				resultadoSetterPesoKg = producto_setPeso (this,pesoKg);
				resultadoSetterPaisOrigen = producto_setPaisOrigen(this,paisOrigen);
				resultadoSetterDescripcion = producto_setDescripcion(this,descripcion);
				resultadoSetterCodigoAlfaNumerico = producto_setCodigoAlfaNumerico(this,codigoAlfaNumerico);
				resultadoSetterIdProducto = producto_setId(this,idProducto);
				resultadoSetterLargoEmpaque = producto_setLargoEmpaque(this,largoEmpaque);
				resultadoSetterAltoEmpaque = producto_setAltoEmpaque(this, altoEmpaque);
				resultadoSetterAnchoEmpaque = producto_setAnchoEmpaque(this, anchoEmpaque);
				resultadoSetterVolumenEmpaque = producto_setVolumenEmpaque(this,volumenEmpaque);
				resultadoSetterValorFob = producto_setValorFobUSD (this,valorFobUSD);
				resultadoSetterPrecioTransporteByMar = producto_setPrecioTransporteByMar(this,precioTransporteByMar);
				resultadoSetterPrecioTransporteByAir = producto_setPrecioTransporteByAir(this,precioTransporteByAir);
				resultadoSetterIdPosicionArancelaria = producto_setIdPosicionArancelaria(this,idPosicionArancelaria);

				//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
				if (resultadoSetterNombre == 0 && resultadoSetterPesoKg == 0 && resultadoSetterPaisOrigen == 0 && resultadoSetterDescripcion == 0 && resultadoSetterCodigoAlfaNumerico == 0 && resultadoSetterIdProducto == 0 && resultadoSetterLargoEmpaque == 0 && resultadoSetterAltoEmpaque == 0 && resultadoSetterAnchoEmpaque == 0 && resultadoSetterVolumenEmpaque == 0 && resultadoSetterValorFob == 0 && resultadoSetterPrecioTransporteByMar == 0 && resultadoSetterPrecioTransporteByAir == 0 && resultadoSetterIdPosicionArancelaria == 0)
				{
					retorno = 0;
				}
				else
				{
					retorno = -2;
					printf ("\n(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)\n",resultadoSetterNombre,resultadoSetterPesoKg,resultadoSetterPaisOrigen,resultadoSetterDescripcion,resultadoSetterCodigoAlfaNumerico,resultadoSetterIdProducto,resultadoSetterLargoEmpaque,resultadoSetterAltoEmpaque,resultadoSetterAnchoEmpaque,resultadoSetterVolumenEmpaque,resultadoSetterValorFob,resultadoSetterPrecioTransporteByMar,resultadoSetterPrecioTransporteByAir,resultadoSetterIdPosicionArancelaria);
				}
		}

		return retorno;
	}

	int producto_setAllParamsTxt(Producto* this, char* nombre, char* pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, char* idProducto, char* largoEmpaque, char* altoEmpaque, char* anchoEmpaque, char* volumenEmpaque, char* valorFobUSD, char* precioTransporteByMar, char* precioTransporteByAir, char* idPosicionArancelaria)

		{
			int retorno = -1;

			//Valido parametros
			if (nombre != NULL && pesoKg != NULL && paisOrigen != NULL &&descripcion != NULL && codigoAlfaNumerico != NULL && idProducto != NULL && largoEmpaque != NULL && altoEmpaque != NULL && anchoEmpaque != NULL && volumenEmpaque != NULL && valorFobUSD != NULL && precioTransporteByMar != NULL && precioTransporteByAir && idPosicionArancelaria != NULL)
				{
					int resultadoSetterNombreTxt;
					int resultadoSetterPesoKgTxt;
					int resultadoSetterPaisOrigenTxt;
					int resultadoSetterDescripcionTxt;
					int resultadoSetterCodigoAlfaNumericoTxt;
					int resultadoSetterIdProductoTxt;
					int resultadoSetterLargoEmpaqueTxt;
					int resultadoSetterAltoEmpaqueTxt;
					int resultadoSetterAnchoEmpaqueTxt;
					int resultadoSetterVolumenEmpaqueTxt;
					int resultadoSetterValorFobTxt;
					int resultadoSetterPrecioTransporteByMarTxt;
					int resultadoSetterPrecioTransporteByAirTxt;
					int resultadoSetterIdPosicionArancelariaTxt;

					//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
					resultadoSetterNombreTxt = producto_setNombre(this,nombre);
					resultadoSetterPesoKgTxt = producto_setPesoTxt (this,pesoKg);
					resultadoSetterPaisOrigenTxt = producto_setPaisOrigen(this,paisOrigen);
					resultadoSetterDescripcionTxt = producto_setDescripcion(this,descripcion);
					resultadoSetterCodigoAlfaNumericoTxt = producto_setCodigoAlfaNumerico(this,codigoAlfaNumerico);
					resultadoSetterIdProductoTxt = producto_setIdTxt(this,idProducto);
					resultadoSetterLargoEmpaqueTxt = producto_setLargoEmpaqueTxt(this,largoEmpaque);
					resultadoSetterAltoEmpaqueTxt = producto_setAltoEmpaqueTxt(this, altoEmpaque);
					resultadoSetterAnchoEmpaqueTxt = producto_setAnchoEmpaqueTxt(this, anchoEmpaque);
					resultadoSetterVolumenEmpaqueTxt = producto_setVolumenEmpaqueTxt(this,volumenEmpaque);
					resultadoSetterValorFobTxt = producto_setValorFobUSDTxt (this,valorFobUSD);
					resultadoSetterPrecioTransporteByMarTxt = producto_setPrecioTransporteByMarTxt(this,precioTransporteByMar);
					resultadoSetterPrecioTransporteByAirTxt = producto_setPrecioTransporteByAirTxt(this,precioTransporteByAir);
					resultadoSetterIdPosicionArancelariaTxt = producto_setIdPosicionArancelariaTxt(this,idPosicionArancelaria);

					//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
					if (resultadoSetterNombreTxt == 0 && resultadoSetterPesoKgTxt == 0 && resultadoSetterPaisOrigenTxt == 0 && resultadoSetterDescripcionTxt == 0 && resultadoSetterCodigoAlfaNumericoTxt == 0 && resultadoSetterIdProductoTxt == 0 && resultadoSetterLargoEmpaqueTxt == 0 && resultadoSetterAltoEmpaqueTxt == 0 && resultadoSetterAnchoEmpaqueTxt == 0 && resultadoSetterVolumenEmpaqueTxt == 0 && resultadoSetterValorFobTxt == 0 && resultadoSetterPrecioTransporteByMarTxt == 0 && resultadoSetterPrecioTransporteByAirTxt == 0 && resultadoSetterIdPosicionArancelariaTxt == 0)
					{
						retorno = 0;
					}
					else
					{
						//printf ("\n(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)(%d)\n",resultadoSetterNombreTxt,resultadoSetterPesoKgTxt,resultadoSetterPaisOrigenTxt,resultadoSetterDescripcionTxt,resultadoSetterCodigoAlfaNumericoTxt,resultadoSetterIdProductoTxt,resultadoSetterLargoEmpaqueTxt,resultadoSetterAltoEmpaqueTxt,resultadoSetterAnchoEmpaqueTxt,resultadoSetterVolumenEmpaqueTxt,resultadoSetterValorFobTxt,resultadoSetterPrecioTransporteByMarTxt,resultadoSetterPrecioTransporteByAirTxt,resultadoSetterIdPosicionArancelariaTxt);
						retorno = -2;
					}
			}

			return retorno;
		}

	int producto_getAllParams(Producto* this, char* nombre, float* pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, int* idProducto, float* largoEmpaque, float* altoEmpaque, float* anchoEmpaque, float* volumenEmpaque, float* valorFobUSD, float* precioTransporteByMar, float* precioTransporteByAir, int* idPosicionArancelaria)
	{
		int retorno = -1;

		//Valido parametros
		if (nombre != NULL && pesoKg > 0 && paisOrigen != NULL &&descripcion != NULL && codigoAlfaNumerico != NULL && idProducto > 0 && largoEmpaque > 0 && altoEmpaque > 0 && anchoEmpaque > 0 && volumenEmpaque > 0 && valorFobUSD > 0 && precioTransporteByMar > 0 && precioTransporteByAir && idPosicionArancelaria > 0)
		{
			int resultadoGetterNombre;
			int resultadoGetterPesoKg;
			int resultadoGetterPaisOrigen;
			int resultadoGetterDescripcion;
			int resultadoGetterCodigoAlfaNumerico;
			int resultadoGetterIdProducto;
			int resultadoGetterLargoEmpaque;
			int resultadoGetterAltoEmpaque;
			int resultadoGetterAnchoEmpaque;
			int resultadoGetterVolumenEmpaque;
			int resultadoGetterValorFob;
			int resultadoGetterPrecioTransporteByMar;
			int resultadoGetterPrecioTransporteByAir;
			int resultadoGetterIdPosicionArancelaria;

			//Copiamos todos los valores recibidos en parametros a la direccion obtenida (con setter asi se valida).
			resultadoGetterNombre = producto_getNombre(this,nombre);
			resultadoGetterPesoKg = producto_getPeso (this,pesoKg);
			resultadoGetterPaisOrigen = producto_getPaisOrigen(this,paisOrigen);
			resultadoGetterDescripcion = producto_getDescripcion(this,descripcion);
			resultadoGetterCodigoAlfaNumerico = producto_getCodigoAlfaNumerico(this,codigoAlfaNumerico);
			resultadoGetterIdProducto = producto_getId(this,idProducto);
			resultadoGetterLargoEmpaque = producto_getLargoEmpaque(this,largoEmpaque);
			resultadoGetterAltoEmpaque = producto_getAltoEmpaque(this, altoEmpaque);
			resultadoGetterAnchoEmpaque = producto_getAnchoEmpaque(this, anchoEmpaque);
			resultadoGetterVolumenEmpaque = producto_getVolumenEmpaque(this,volumenEmpaque);
			resultadoGetterValorFob = producto_getValorFobUSD (this,valorFobUSD);
			resultadoGetterPrecioTransporteByMar = producto_getPrecioTransporteByMar(this,precioTransporteByMar);
			resultadoGetterPrecioTransporteByAir = producto_getPrecioTransporteByAir(this,precioTransporteByAir);
			resultadoGetterIdPosicionArancelaria = producto_getIdPosicionArancelaria(this,idPosicionArancelaria);

			//printProducto(this);

			//Si sale bien devuelvo 0 ya que el producto quedo seteado. Sino devuelvo -2 para indicar error.
			if (resultadoGetterNombre == 0 && resultadoGetterPesoKg == 0 && resultadoGetterPaisOrigen == 0 && resultadoGetterDescripcion == 0 && resultadoGetterCodigoAlfaNumerico == 0 && resultadoGetterIdProducto == 0 && resultadoGetterLargoEmpaque == 0 && resultadoGetterAltoEmpaque == 0 && resultadoGetterAnchoEmpaque == 0 && resultadoGetterVolumenEmpaque == 0 && resultadoGetterValorFob == 0 && resultadoGetterPrecioTransporteByMar == 0 && resultadoGetterPrecioTransporteByAir == 0 && resultadoGetterIdPosicionArancelaria == 0)
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


	/*
	 * \brief Obtiene (desde consola) todos los campos (que puede ingresar el usuario) de un producto y los valida.
	 * \param pNombreValidado char* Puntero a donde se va a guardar el nombre obtenido y validado.
	 * \param pHorasTrabajadasValidadas int* Puntero al donde se va a guardar las horas trabajadas obtenidas y validadas.
	 * \param pSueldoValidado int* Puntero a donde se va a guardar el sueldo obtenido y validado.
	 * \return int Retorna 0 si la obtencion, validacion y el setteo a los punteros de los campos salio bien.
	 **/
	int getAllFieldsFromConsoleValidatedProduct (Producto* this, char* nombre, float* peso, char* descripcion, char* paisOrigen, char* codigoAlfaNumerico, float* largoEmpaque, float* altoEmpaque, float* anchoEmpaque, float* precioFob, int* idPosicionArancelaria)
	{
		int retorno = -1;

		if (nombre != NULL && peso != NULL && descripcion != NULL && codigoAlfaNumerico != NULL && largoEmpaque != NULL && altoEmpaque != NULL && anchoEmpaque != NULL && precioFob != NULL)
		{
			retorno = -2;

			int resultadoObtencionNombre;
			int resultadoObtencionPeso;
			int resultadoObtencionDescripcion;
			int resultadoObtencionpaisOrigen;
			int resultadoObtencionCodigoAlfanumerico;
			int resultadoObtencionLargoEmpaque;
			int resultadoObtencionAltoEmpaque;
			int resultadoObtencionAnchoEmpaque;
			int resultadoObtencionFob;
			int resultadoObtencionIdPosicionArancelaria;

			//Creo un producto auxiliar para al final traspasar los datos al de puntero de parametros.
			Producto auxProducto;

			//Pido los campos obtenibles y guardo como salieron. (Para obtener algo razonable).
			resultadoObtencionNombre = utn_getNombre(auxProducto.nombre,NOMBRE_LEN,"\nIngrese el nombre del producto.\n","\nError en el ingreso del nombre.\n", 3);
			resultadoObtencionPeso = utn_getNumeroFlotante(&auxProducto.pesokg,"\nIngrese el peso del empaque (KG)\n","\nError en el ingreso del peso.\n", 0,100000, 3);
			resultadoObtencionDescripcion = utn_getDescripcion(auxProducto.descripcion,DESC_LEN,"\nIngrese descripcion del producto.\n","\nError en el ingreso de la descripcion\n", 3);
			resultadoObtencionpaisOrigen = utn_getNombre(auxProducto.paisOrigen,PAIS_LEN,"\nIngrese el nombre del pais de origen del producto.\n","\nError en el ingreso del pais.\n", 3);
			resultadoObtencionCodigoAlfanumerico = utn_getDescripcion(auxProducto.codigoAlfanumerico,CODIGOALF_LEN,"\nIngrese codigo alfanumerico del producto.\n","\nError en el ingreso del codigo alfanumerico.\n", 3);
			resultadoObtencionLargoEmpaque = utn_getNumeroFlotante(&auxProducto.largoEmpaque,"\nIngrese el largo del empaque\n","\nError en el ingreso de la medida.\n", 0,100000, 3);
			resultadoObtencionAltoEmpaque = utn_getNumeroFlotante(&auxProducto.altoEmpaque,"\nIngrese el alto del empaque\n","\nError en el ingreso de la medida.\n", 0,100000, 3);
			resultadoObtencionAnchoEmpaque = utn_getNumeroFlotante(&auxProducto.anchoEmpaque,"\nIngrese el ancho del empaque\n","\nError en el ingreso de la medida.\n", 0,100000, 3);
			resultadoObtencionFob = utn_getNumeroFlotante(&auxProducto.valorFobUSD,"\nIngrese el valor fob del producto\n","\nError en el ingreso del precio.\n", 0,100000, 3);
			resultadoObtencionIdPosicionArancelaria = utn_getNumero(&auxProducto.idPosicionArancelaria,"\nIngrese el id de la posicion arancelaria\n","\nError en el ingreso de la id\n",0,9999999, 3);

			//Si recibi algo medianamente coherente, puedo empezar la validacion real de cada campo para setearlo en el puntero a producto de parametros.
			if (resultadoObtencionNombre == 0 && resultadoObtencionPeso == 0 && resultadoObtencionDescripcion == 0 && resultadoObtencionpaisOrigen == 0 && resultadoObtencionCodigoAlfanumerico == 0 && resultadoObtencionLargoEmpaque == 0 && resultadoObtencionAltoEmpaque == 0 && resultadoObtencionAnchoEmpaque == 0 && resultadoObtencionFob == 0 && resultadoObtencionIdPosicionArancelaria == 0)
			{
				retorno = -3;

					int resultadoSetterNombre;
					int resultadoSetterPeso;
					int resultadoSetterDescripcion;
					int resultadoSetterPaisOrigen;
					int resultadoSetterCodigoAlfanumerico;
					int resultadoSetterLargoEmpaque;
					int resultadoSetterAltoEmpaque;
					int resultadoSetterAnchoEmpaque;
					int resultadoSetterFob;
					int resultadoSetterPosicionArancelaria;

					resultadoSetterNombre = producto_setNombre(this,auxProducto.nombre);
					resultadoSetterPeso = producto_setPeso(this,auxProducto.pesokg);
					resultadoSetterDescripcion = producto_setDescripcion(this,auxProducto.descripcion);
					resultadoSetterPaisOrigen = producto_setPaisOrigen(this,auxProducto.paisOrigen);
					resultadoSetterCodigoAlfanumerico = producto_setCodigoAlfaNumerico(this,auxProducto.codigoAlfanumerico);
					resultadoSetterLargoEmpaque = producto_setLargoEmpaque(this,auxProducto.largoEmpaque);
					resultadoSetterAltoEmpaque = producto_setAltoEmpaque(this,auxProducto.altoEmpaque);
					resultadoSetterAnchoEmpaque = producto_setAnchoEmpaque(this,auxProducto.anchoEmpaque);
					resultadoSetterFob = producto_setValorFobUSD(this,auxProducto.valorFobUSD);
					resultadoSetterPosicionArancelaria = producto_setIdPosicionArancelaria(this,auxProducto.idPosicionArancelaria);

					if (resultadoSetterNombre == 0 && resultadoSetterPeso == 0 && resultadoSetterDescripcion == 0 && resultadoSetterPaisOrigen == 0 && resultadoSetterCodigoAlfanumerico == 0 && resultadoSetterLargoEmpaque == 0 && resultadoSetterAltoEmpaque == 0 && resultadoSetterAnchoEmpaque == 0 && resultadoSetterFob == 0 && resultadoSetterPosicionArancelaria == 0)
					{
						//SI SALIO BIEN EL SETEO YA TENGO EN EL PUNTERO A PARAMETRO DEL PRODUCTO LOS DATOS OBTENIDOS Y VALIDADOS.
						retorno = 0;
					}
					else
					{

					}
				}

			}

		return retorno;
	}


	/*
	 * \brief Recibe un nombre, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Producto* Puntero recibido al producto donde se settea.
	 * \param nombre char* Nombre recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setNombre(Producto* this, char* nombre)
	{
		int retorno = -1;

		if (this != NULL && nombre != NULL)
		{
			retorno = -2;

			int validacionNombre;
			validacionNombre = esNombreValido(nombre, NOMBRE_LEN);

			if (validacionNombre == 0 )
			{
				strncpy (this->nombre, nombre, NOMBRE_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}


	int producto_getNombre(Producto* this, char* nombre)
	{
		int retorno = -1;

		if (this != NULL && nombre != NULL)
		{
			retorno = -2;

			int validacionNombre;
			validacionNombre = esNombreValido(this->nombre, NOMBRE_LEN);

			if (validacionNombre == 0)
			{
				strncpy (nombre,this->nombre,NOMBRE_LEN);
				retorno = 0;
			}


		}
		return retorno;
	}


	int producto_setPeso (Producto* this, float peso)
	{
		int retorno = -1;

		if (this != NULL && peso > 0)
		{
			retorno = -2;
			int validacionPeso;
			validacionPeso = esPesoValido (peso);

			if (validacionPeso == 0)
			{
				this->pesokg = peso;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_setPesoTxt (Producto* this, char* pesoTxt)
	{
		int retorno = -1;

		if (this != NULL && pesoTxt != NULL)
		{
			retorno = -2;

			int validacionPesoTxt;
			validacionPesoTxt = esFlotante(pesoTxt);

			if (validacionPesoTxt == 0)
			{
				float pesoFloat = atof (pesoTxt);

				this->pesokg = pesoFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getPeso (Producto* this, float* peso)
	{
		int retorno = -1;

		if (this != NULL && peso > 0)
		{
			retorno = -2;

			int validacionPeso;
			validacionPeso = esPesoValido (this->pesokg);

			if (validacionPeso == 0)
			{
				*peso = this->pesokg;
				retorno = 0;
			}
		}

		return retorno;
	}


	/*
	 * \brief Recibe un nombre, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Producto* Puntero recibido al producto donde se settea.
	 * \param nombre char* Nombre recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setDescripcion(Producto* this, char* descripcion)
	{
		int retorno = -1;

		if (this != NULL && descripcion != NULL)
		{
			retorno = -2;
			int validacionDescripcion;
			validacionDescripcion = esDescripcion(descripcion,DESC_LEN);

			if (validacionDescripcion == 0)
			{
				strncpy (this->descripcion, descripcion, DESC_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}


	int producto_getDescripcion(Producto* this, char* descripcion)
	{
		int retorno = -1;

		if (this != NULL && descripcion != NULL)
		{
			retorno = -2;

			int validacionDescripcion;
			validacionDescripcion = esDescripcion(this->descripcion,DESC_LEN);

			if (validacionDescripcion == 0)
			{
				strncpy (descripcion,this->descripcion,DESC_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}

	/*
	 * \brief Recibe un nombre, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Producto* Puntero recibido al producto donde se settea.
	 * \param nombre char* Nombre recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setCodigoAlfaNumerico(Producto* this, char* codigoAlfaNumerico)
	{
		int retorno = -1;

		if (this != NULL && codigoAlfaNumerico != NULL)
		{
			retorno = -2;

			int validacionCodigoAlfaNumerico;
			validacionCodigoAlfaNumerico = esCodigoAlfaNumerico(codigoAlfaNumerico,CODIGOALF_LEN);

			if (validacionCodigoAlfaNumerico == 0)
			{
				strncpy (this->codigoAlfanumerico, codigoAlfaNumerico, CODIGOALF_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_getCodigoAlfaNumerico(Producto* this, char* codigoAlfaNumerico)
	{
		int retorno = -1;

		if (this != NULL && codigoAlfaNumerico != NULL)
		{
			retorno = -2;

			int validacionCodigoAlfaNumerico;
			validacionCodigoAlfaNumerico = esCodigoAlfaNumerico(this->codigoAlfanumerico,CODIGOALF_LEN);

			if (validacionCodigoAlfaNumerico == 0)
			{
				strncpy (codigoAlfaNumerico,this->codigoAlfanumerico,CODIGOALF_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}


	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setId(Producto* this, int id)
	{
		int retorno = -1;

		if (this != NULL && id > 0)
		{
			retorno = -2;

			int validacionId;
			validacionId = esIdValidoInt (id);

			if (validacionId == 0)
			{
				this->idProducto = id;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setIdTxt(Producto* this, char* id)
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

				this->idProducto = idNumerico;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_getId(Producto* this, int* id)
	{
		int retorno = -1;

		if (this != NULL && id > 0)
		{
			retorno = -2;

			int validacionId;
			validacionId = esIdValidoInt (this->idProducto);

			if (validacionId == 0)
			{
				*id = this->idProducto;
				retorno = 0;
			}
		}
		return retorno;
	}


	/*
	 * \brief Recibe un id como texto, lo verifica y si es valido lo convierte y lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id char* Puntero al Id recibido para validar y setear.
	 * \return int Retorna 0 si la validacion y el setteo salio bien.
	 */


	int employee_getIdTxt(Producto* this, char* id, int longitud)
		{
			int retorno = -1;

			if (this != NULL && id != NULL)
			{
				retorno = -2;

				int validacionId;
				validacionId = esIdValidoInt (this->idProducto);

				if (validacionId == 0)
				{
					int idNumerico;
					idNumerico = this->idProducto;

					snprintf(id,longitud,"%d",idNumerico);
					retorno = 0;
				}
			}
			return retorno;
		}

	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setLargoEmpaque(Producto* this, float largoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && largoEmpaque > 0)
		{
			retorno = -2;

			int validacionLargoEmpaque;
			validacionLargoEmpaque = esLargoEmpaqueValido (largoEmpaque);

			if (validacionLargoEmpaque == 0)
			{
				this->largoEmpaque = largoEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setLargoEmpaqueTxt (Producto* this, char* largoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && largoEmpaque != NULL)
		{
			retorno = -2;

			int validacionlargoEmpaqueTxt;
			validacionlargoEmpaqueTxt = esFlotante(largoEmpaque);

			if (validacionlargoEmpaqueTxt == 0)
			{
				float largoEmpaqueFloat = atof (largoEmpaque);

				this->largoEmpaque = largoEmpaqueFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getLargoEmpaque(Producto* this, float* largoEmpaque)
		{
			int retorno = -1;

			if (this != NULL && largoEmpaque > 0)
			{
				retorno = -2;

				int validacionLargoEmpaque;
				validacionLargoEmpaque = esLargoEmpaqueValido (this->largoEmpaque);

				if (validacionLargoEmpaque == 0)
				{
					*largoEmpaque = this->largoEmpaque;
					retorno = 0;
				}
			}
			return retorno;
		}


	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setAltoEmpaque(Producto* this, float altoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && altoEmpaque > 0)
		{
			retorno = -2;

			int validacionAltoEmpaque;
			validacionAltoEmpaque = esAltoEmpaqueValido(altoEmpaque);

			if (validacionAltoEmpaque == 0)
			{
				this->altoEmpaque = altoEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setAltoEmpaqueTxt (Producto* this, char* altoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && altoEmpaque != NULL)
		{
			retorno = -2;

			int validacionAltoEmpaqueTxt;
			validacionAltoEmpaqueTxt = esFlotante(altoEmpaque);

			if (validacionAltoEmpaqueTxt == 0)
			{
				float altoEmpaqueFloat = atof (altoEmpaque);

				this->altoEmpaque = altoEmpaqueFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getAltoEmpaque(Producto* this, float* altoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && altoEmpaque > 0)
		{
			retorno = -2;

			int validacionAltoEmpaque;
			validacionAltoEmpaque = esAltoEmpaqueValido(this->altoEmpaque);

			if (validacionAltoEmpaque == 0)
			{
				*altoEmpaque = this->altoEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}

	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setAnchoEmpaque(Producto* this, float anchoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && anchoEmpaque > 0)
		{
			retorno = -2;

			int validacionAnchoEmpaque;
			validacionAnchoEmpaque = esAnchoEmpaqueValido(anchoEmpaque);

			if (validacionAnchoEmpaque == 0)
			{
				this->anchoEmpaque = anchoEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setAnchoEmpaqueTxt (Producto* this, char* anchoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && anchoEmpaque != NULL)
		{
			retorno = -2;

			int validacionAnchoEmpaqueTxt;
			validacionAnchoEmpaqueTxt = esFlotante(anchoEmpaque);

			if (validacionAnchoEmpaqueTxt == 0)
			{
				float anchoEmpaqueFloat = atof (anchoEmpaque);

				this->anchoEmpaque = anchoEmpaqueFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getAnchoEmpaque(Producto* this, float* anchoEmpaque)
	{
		int retorno = -1;

		if (this != NULL && anchoEmpaque > 0)
		{
			retorno = -2;

			int validacionAnchoEmpaque;
			validacionAnchoEmpaque = esAnchoEmpaqueValido(this->anchoEmpaque);

			if (validacionAnchoEmpaque == 0)
			{
				*anchoEmpaque = this->anchoEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}

	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setVolumenEmpaque(Producto* this, float volumenEmpaque)
	{
		int retorno = -1;

		if (this != NULL && volumenEmpaque > 0)
		{
			retorno = -2;

			int validacionVolumenEmpaque;
			validacionVolumenEmpaque = esVolumenEmpaqueValido(volumenEmpaque);

			if (validacionVolumenEmpaque == 0)
			{
				this->volumenEmpaque = volumenEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setVolumenEmpaqueTxt (Producto* this, char* volumenEmpaque)
	{
		int retorno = -1;

		if (this != NULL && volumenEmpaque != NULL)
		{
			retorno = -2;

			int validacionVolumenEmpaqueTxt;
			validacionVolumenEmpaqueTxt = esFlotante(volumenEmpaque);

			if (validacionVolumenEmpaqueTxt == 0)
			{
				float volumenEmpaqueFloat = atof (volumenEmpaque);

				this->volumenEmpaque = volumenEmpaqueFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getVolumenEmpaque(Producto* this, float* volumenEmpaque)
	{
		int retorno = -1;

		if (this != NULL && volumenEmpaque > 0)
		{
			retorno = -2;

			int validacionVolumenEmpaque;
			validacionVolumenEmpaque = esVolumenEmpaqueValido(this->volumenEmpaque);

			if (validacionVolumenEmpaque == 0)
			{
				*volumenEmpaque = this->volumenEmpaque;
				retorno = 0;
			}
		}
		return retorno;
	}


	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setValorFobUSD(Producto* this, float valorFobUSD)
	{
		int retorno = -1;

		if (this != NULL && valorFobUSD > 0)
		{
			retorno = -2;

			int validacionValorFobUSD;
			validacionValorFobUSD = esValorFobUSDValido(valorFobUSD);

			if (validacionValorFobUSD == 0)
			{
				this->valorFobUSD = valorFobUSD;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setValorFobUSDTxt (Producto* this, char* valorFob)
	{
		int retorno = -1;

		if (this != NULL && valorFob != NULL)
		{
			retorno = -2;

			int validacionValorFobTxt;
			validacionValorFobTxt = esFlotante(valorFob);

			if (validacionValorFobTxt == 0)
			{
				float valorFobFloat = atof (valorFob);

				this->valorFobUSD = valorFobFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getValorFobUSD(Producto* this, float* valorFobUSD)
	{
		int retorno = -1;

		if (this != NULL && valorFobUSD > 0)
		{
			retorno = -2;

			int validacionValorFobUSD;
			validacionValorFobUSD = esValorFobUSDValido(this->valorFobUSD);

			if (validacionValorFobUSD == 0)
			{
				*valorFobUSD = this->valorFobUSD;
				retorno = 0;
			}
		}
		return retorno;
	}

	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setPrecioTransporteByMar(Producto* this, float precioTransporteByMar)
	{
		int retorno = -1;

		if (this != NULL && precioTransporteByMar > 0)
		{
			retorno = -2;

			int validacionPrecioTransporteByMar;
			validacionPrecioTransporteByMar = esPrecioValido(precioTransporteByMar);

			if (validacionPrecioTransporteByMar == 0)
			{
				this->precioTransporteByMarUSD = precioTransporteByMar;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setPrecioTransporteByMarTxt (Producto* this, char* precioTransporteByMar)
	{
		int retorno = -1;

		if (this != NULL && precioTransporteByMar != NULL)
		{
			retorno = -2;

			int validacionprecioTransporteByMarTxt;
			validacionprecioTransporteByMarTxt = esFlotante(precioTransporteByMar);

			if (validacionprecioTransporteByMarTxt == 0)
			{
				float valorprecioTransporteByMarFloat = atof (precioTransporteByMar);

				this->precioTransporteByMarUSD = valorprecioTransporteByMarFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getPrecioTransporteByMar(Producto* this, float* precioTransporteByMar)
	{
		int retorno = -1;

		if (this != NULL && precioTransporteByMar > 0)
		{
			retorno = -2;

			int validacionPrecioTransporteByMar;
			validacionPrecioTransporteByMar = esPrecioValido(this->precioTransporteByMarUSD);

			if (validacionPrecioTransporteByMar == 0)
			{
				*precioTransporteByMar = this->precioTransporteByMarUSD;
				retorno = 0;
			}
		}
		return retorno;
	}

	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setPrecioTransporteByAir(Producto* this, float precioTransporteByAir)
	{
		int retorno = -1;

		if (this != NULL && precioTransporteByAir > 0)
		{
			retorno = -2;

			int validacionPrecioTransporteByAir;
			validacionPrecioTransporteByAir = esPrecioValido(precioTransporteByAir);

			if (validacionPrecioTransporteByAir == 0)
			{
				this->precioTransporteByAirUSD = precioTransporteByAir;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setPrecioTransporteByAirTxt (Producto* this, char* precioTransporteByAir)
	{
		int retorno = -1;

		if (this != NULL && precioTransporteByAir != NULL)
		{
			retorno = -2;

			int validacionprecioTransporteByAirTxt;
			validacionprecioTransporteByAirTxt = esFlotante(precioTransporteByAir);

			if (validacionprecioTransporteByAirTxt == 0)
			{
				float valorprecioTransporteByAirFloat = atof (precioTransporteByAir);

				this->precioTransporteByAirUSD = valorprecioTransporteByAirFloat;
				retorno = 0;
			}

		}

		return retorno;
	}

	int producto_getPrecioTransporteByAir(Producto* this, float* precioTransporteByAir)
	{
		int retorno = -1;

		if (this != NULL && precioTransporteByAir > 0)
		{
			retorno = -2;

			int validacionPrecioTransporteByAir;
			validacionPrecioTransporteByAir = esPrecioValido(this->precioTransporteByAirUSD);

			if (validacionPrecioTransporteByAir == 0)
			{
				*precioTransporteByAir = this->precioTransporteByAirUSD;
				retorno = 0;
			}
		}
		return retorno;
	}

	/*
	 * \brief Recibe un id, lo verifica y si es valido lo setea en el puntero recibido.
	 * \param this Employee* Puntero recibido al empleado donde se settea.
	 * \param id int Id recibido para validar y setear.
	 * \return int Retorna 0 si el setteo salio bien.
	 */
	int producto_setIdPosicionArancelaria(Producto* this, int idPosicionArancelaria)
	{
		int retorno = -1;

		if (this != NULL && idPosicionArancelaria > 0)
		{
			retorno = -2;

			int validacionIdPosicionArancelaria;
			validacionIdPosicionArancelaria = esIdValidoInt (idPosicionArancelaria);

			if (validacionIdPosicionArancelaria == 0)
			{
				this->idPosicionArancelaria = idPosicionArancelaria;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setIdPosicionArancelariaTxt(Producto* this, char* id)
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

	int producto_getIdPosicionArancelaria(Producto* this, int* idPosicionArancelaria)
	{
		int retorno = -1;

		if (this != NULL && idPosicionArancelaria > 0)
		{
			retorno = -2;

			int validacionIdPosicionArancelaria;
			validacionIdPosicionArancelaria = esIdValidoInt (this->idPosicionArancelaria);

			if (validacionIdPosicionArancelaria == 0)
			{
				*idPosicionArancelaria = this->idPosicionArancelaria;
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_setPaisOrigen(Producto* this, char* paisOrigen)
	{
		int retorno = -1;

		if (this != NULL && paisOrigen != NULL)
		{
			retorno = -2;

			int validacionPaisOrigen;
			validacionPaisOrigen = esNombreValido (paisOrigen,PAIS_LEN);

			if (validacionPaisOrigen == 0)
			{
				strncpy (this->paisOrigen,paisOrigen,PAIS_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}

	int producto_getPaisOrigen(Producto* this, char* paisOrigen)
	{
		int retorno = -1;

		if (this != NULL && paisOrigen != NULL)
		{
			retorno = -2;

			int validacionPaisOrigen;
			validacionPaisOrigen = esNombreValido (this->paisOrigen,PAIS_LEN);

			if (validacionPaisOrigen == 0)
			{
				strncpy (paisOrigen,this->paisOrigen,PAIS_LEN);
				retorno = 0;
			}
		}
		return retorno;
	}


////////////////////////////////////////////////////////////////////////////////////////


	int printProducto (Producto* this)
	{
		int retorno = -1;

		if (this != NULL)
		{
			//LAMAR A ESTE PRINT SI SE QUIERE HACER UN PRINT DENTRO DE UN FOR.
			//printf ("| Nombre | Descripcion | Codigo AlfaNumerico | Id-Producto | Largo Empaque | Alto Empaque | Ancho Empaque | Volumen Empaque | Valor Fob (USD) | Precio del transporte por mar | Precio del transporte por aire | ID-Posicion arancelaria |");

			printf ("(%s),(%f),(%s),(%s),(%s),(%d),(%f),(%f),(%f),(%f),(%f),(%f),(%f),(%d) \n \n",this->nombre,this->pesokg,this->descripcion,this->paisOrigen,this->codigoAlfanumerico,this->idProducto,this->largoEmpaque,this->altoEmpaque,this->anchoEmpaque,this->volumenEmpaque,this->valorFobUSD,this->precioTransporteByMarUSD,this->precioTransporteByAirUSD,this->idPosicionArancelaria);
		}

		return retorno;

	}

	Producto* producto_buscarPorIdPosArancelaria (LinkedList* producto_ll, int idPosArancelariaFind)
	{
		Producto* retorno = NULL;

		if (producto_ll != NULL && idPosArancelariaFind > 0)
		{

			Producto* productoGetteado = NULL;

			for (int i = 0 ; i < ll_len(producto_ll) ; i++)
			{
				productoGetteado = ll_get (producto_ll, i);

				if (productoGetteado != NULL && productoGetteado->idPosicionArancelaria == idPosArancelariaFind)
				{
					retorno = productoGetteado;
					break;
				}
			}

		}

		return retorno;
	}

	Producto* producto_buscarPorIdProducto (LinkedList* producto_ll, int idProductoToFind)
	{
		Producto* retorno = NULL;

		if (producto_ll != NULL && idProductoToFind > 0)
		{

			Producto* productoGetteado = NULL;

			for (int i = 0 ; i < ll_len(producto_ll) ; i++)
			{
				productoGetteado = ll_get (producto_ll, i);

				if (productoGetteado != NULL && productoGetteado->idProducto == idProductoToFind)
				{
					retorno = productoGetteado;
					break;
				}
			}

		}

		return retorno;
	}

	int save_productos (char* path, Dictionary* this)
	{
		int retorno = -1;

		if (path != NULL && this != NULL)
		{
			retorno = -2;

			LinkedList* listapProductos;
			listapProductos = dict_getValues(this);


			FILE* filePuntero;
			filePuntero = fopen (path,"w");

			if (filePuntero != NULL)
			{
				retorno = 0;

				Producto aux;

				int resultadoObtencionValidacion;
				Producto* pProductoll;

				for (int i = 0 ; i < ll_len(listapProductos) ; i++)
				{

					pProductoll = ll_get(listapProductos, i);

					if (pProductoll != NULL)
					{

						//Guardo en aux los campos de pProductoll;
						resultadoObtencionValidacion = producto_getAllParams(pProductoll, aux.nombre, &aux.pesokg, aux.paisOrigen, aux.descripcion, aux.codigoAlfanumerico, &aux.idProducto, &aux.largoEmpaque, &aux.altoEmpaque, &aux.anchoEmpaque, &aux.volumenEmpaque, &aux.valorFobUSD, &aux.precioTransporteByMarUSD, &aux.precioTransporteByAirUSD, &aux.idPosicionArancelaria);

						if (resultadoObtencionValidacion == 0)
						{

							fprintf (filePuntero,"%s,%f,%s,%s,%s,%d,%f,%f,%f,%f,%f,%f,%f,%d\n",aux.nombre,aux.pesokg,aux.descripcion,aux.paisOrigen,aux.codigoAlfanumerico,aux.idProducto,aux.largoEmpaque,aux.altoEmpaque,aux.anchoEmpaque,aux.volumenEmpaque,aux.valorFobUSD,aux.precioTransporteByMarUSD,aux.precioTransporteByAirUSD,aux.idPosicionArancelaria);
						}
						else
						{
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

			//Borro la lista de productos que uso para escribir el archivo, independientemente de como salga la escritura.
			ll_deleteLinkedList(listapProductos);

		}

		return retorno;
	}



	int load_productos (char* path, Dictionary* pListaProductos)
	{
		int retorno = -1;
		int idMax;

		if (path != NULL && pListaProductos != NULL)
		{
			retorno = -2;

			FILE* pFile;
			pFile = fopen (path,"r");

			if (pFile != NULL)
			{

				idMax = parser_ProductoFromText(pFile, pListaProductos);
				//printf ("RESULTADO PARSER: %d",resultadoParser);

				fclose(pFile);

				retorno = idMax;

				/*
				if (resultadoParser == 0)
				{
					retorno = 0;
				}
				*/
			}
			else
			{
				printf ("\nError en la carga de productos.\n");
			}

		}


		return retorno;
	}

	int parser_ProductoFromText(FILE* pFile , Dictionary* pListaProductos)
		{
			int retorno = -1;

			if (pFile != NULL && pListaProductos != NULL)
			{
				retorno = -2;

				int resultadoFscanf;
				int resultadoSetAllByTxt;
				int contadorProductosLoadeados = 0;
				ProductoTxt productoTxt;
				Producto* pNewProducto;

				int idAux;
				int idMax;

				do
				{
					resultadoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n,",productoTxt.nombre,productoTxt.pesokg,productoTxt.descripcion,productoTxt.paisOrigen,productoTxt.codigoAlfanumerico,productoTxt.idProducto,productoTxt.largoEmpaque,productoTxt.altoEmpaque,productoTxt.anchoEmpaque,productoTxt.volumenEmpaque,productoTxt.valorFobUSD,productoTxt.precioTransporteByMarUSD,productoTxt.precioTransporteByAirUSD,productoTxt.idPosicionArancelaria);

					if (resultadoFscanf == 14)
					{

						pNewProducto = producto_new();
						resultadoSetAllByTxt = producto_setAllParamsTxt(pNewProducto,productoTxt.nombre,productoTxt.pesokg,productoTxt.paisOrigen,productoTxt.descripcion,productoTxt.codigoAlfanumerico,productoTxt.idProducto,productoTxt.largoEmpaque,productoTxt.altoEmpaque,productoTxt.anchoEmpaque,productoTxt.volumenEmpaque,productoTxt.valorFobUSD,productoTxt.precioTransporteByMarUSD,productoTxt.precioTransporteByAirUSD,productoTxt.idPosicionArancelaria);

						if (pNewProducto != NULL && resultadoSetAllByTxt == 0)
						{
							idAux = atoi(productoTxt.idProducto);

							if(contadorProductosLoadeados == 0 || idAux > idMax)
							{
								idMax = idAux;
							}

							//printProducto (pNewProducto);
							dict_insert (pListaProductos,productoTxt.idProducto,pNewProducto);
							contadorProductosLoadeados++;
						}
						else if (resultadoSetAllByTxt != 0 && pNewProducto != NULL)
						{
							//Si el setteo sale mal borro el producto new que hice.
							producto_delete(pNewProducto);
							pNewProducto = NULL;
						}

					}


				}while(feof(pFile) == 0);

				if (contadorProductosLoadeados > 0)
				{
					retorno = idMax;
					//printf ("PRODUCTOS LODEADOS: %d IDMAX: %d",contadorProductosLoadeados,idMax);
				}
			}


			return retorno;

		}



	/* FUNCION CRITERIO OJO
	 *
	 * \brief Recibe 2 punteros que son casteados a punteros a Empleados. Obtiene el id de ambos empleados y los compara. (El retorno varia segun el resultado de la comparacion)
	 * \param item1 void* Puntero recibido que se convertira a pEmpleado.
	 * \param item2 void* Segundo puntero recibido que se convertira a pEmpleado.
	 * \return int Retorna 1 si el primer puntero empleado tiene un id mayor que el 2do puntero. Si el id es menor retorna -1.
	 *
	int employeeFuncionCriterio (void* item1 ,void* item2)
	{
		int retorno = 0;

		if (item1 != NULL && item2 != NULL)
		{
			//Convierto los punteros void a employee
			Employee* empleado1 = (Employee*) item1;
			Employee* empleado2 = (Employee*) item2;

			int employee1Id;
			int employee2Id;

			//Obtengo los valores Id de cada uno
			employee_getId (empleado1, &employee1Id);
			employee_getId (empleado2, &employee2Id);

			if (employee1Id > employee2Id)
			{
				retorno = 1;
			}
			else
			{
				retorno = -1;
			}
		}

		return retorno;
	}

*/
