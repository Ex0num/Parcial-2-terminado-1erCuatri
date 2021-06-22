
	#ifndef employee_H_INCLUDED
	#define employee_H_INCLUDED

	//HACER GETTERS-HACER EL GETBYCONSOLE-STRUCT POS ARANCELARIA-GETTERS SETTER-

	#include "Dictionary.h"

	//-----DEFINES-------------------

	#define NOMBRE_LEN 32
	#define DESC_LEN 64
	#define CODIGOALF_LEN 32
	#define CHARACTERS_LEN 32
	#define PAIS_LEN 32

	//----ESTRUCTURA PRODUCTO---------

	typedef struct pProducto
	{
		//DATOS
		char nombre[NOMBRE_LEN];
		float pesokg;
		char descripcion[DESC_LEN];
		char paisOrigen[PAIS_LEN];
		char codigoAlfanumerico[CODIGOALF_LEN];
		int idProducto;

		//MEDIDAS EMPAQUE
		float largoEmpaque;
		float altoEmpaque;
		float anchoEmpaque;
		float volumenEmpaque;

		//VALORES Y AGREGADOS
		float valorFobUSD;
		float precioTransporteByMarUSD;
		float precioTransporteByAirUSD;
		int idPosicionArancelaria;

	}Producto;

	//----ESTRUCTURA PRODUCTO TXT---------

	typedef struct pProductoTxt
	{
		//DATOS
		char nombre[NOMBRE_LEN];
		char pesokg[CHARACTERS_LEN];
		char descripcion[DESC_LEN];
		char paisOrigen[PAIS_LEN];
		char codigoAlfanumerico[CODIGOALF_LEN];
		char idProducto[CHARACTERS_LEN];

		//MEDIDAS EMPAQUE
		char largoEmpaque[CHARACTERS_LEN];
		char altoEmpaque[CHARACTERS_LEN];
		char anchoEmpaque[CHARACTERS_LEN];
		char volumenEmpaque[CHARACTERS_LEN];

		//VALORES Y AGREGADOS
		char valorFobUSD[CHARACTERS_LEN];
		char precioTransporteByMarUSD[CHARACTERS_LEN];
		char precioTransporteByAirUSD[CHARACTERS_LEN];
		char idPosicionArancelaria[CHARACTERS_LEN];

	}ProductoTxt;



	//==========  F U N C I O N E S   P R O D U C T O  ==========
	Producto* producto_new();
	Producto* producto_newParametros (char* nombre, float pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, int idProducto, float largoEmpaque, float altoEmpaque, float anchoEmpaque, float volumenEmpaque, float valorFobUSD, float precioTransporteByMar, float precioTransporteByAir, float idPosicionArancelaria);
	void producto_delete(Producto* this);

	//============================================  S E T T E R   Y   G E T T E R S ============================================//

	//----------SETTER Y GETTER GENERAL--------------------------------------------------
	int producto_setAllParams(Producto* this, char* nombre, float pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, int idProducto, float largoEmpaque, float altoEmpaque, float anchoEmpaque, float volumenEmpaque, float valorFobUSD, float precioTransporteByMar, float precioTransporteByAir, int idPosicionArancelaria);
	int producto_setAllParamsTxt(Producto* this, char* nombre, char* pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, char* idProducto, char* largoEmpaque, char* altoEmpaque, char* anchoEmpaque, char* volumenEmpaque, char* valorFobUSD, char* precioTransporteByMar, char* precioTransporteByAir, char* idPosicionArancelaria);
	int producto_getAllParams(Producto* this, char* nombre, float* pesoKg, char* paisOrigen, char* descripcion, char* codigoAlfaNumerico, int* idProducto, float* largoEmpaque, float* altoEmpaque, float* anchoEmpaque, float* volumenEmpaque, float* valorFobUSD, float* precioTransporteByMar, float* precioTransporteByAir, int* idPosicionArancelaria);

	//----------GETTER GENERAL POR CONSOLA--------------------------------------------------
	int getAllFieldsFromConsoleValidatedProduct (Producto* this, char* nombre, float* peso, char* descripcion, char* paisOrigen, char* codigoAlfaNumerico, float* largoEmpaque, float* altoEmpaque, float* anchoEmpaque, float* precioFob, int* idPosicionArancelaria);

	//----------NOMBRE----------------------------------------------------------
	int producto_setNombre(Producto* this, char* nombre);
	int producto_getNombre(Producto* this,char* nombre);

	//----------PESO------------------------------------------------------------
	int producto_setPeso (Producto* this, float peso);
	int producto_setPesoTxt (Producto* this, char* pesoTxt);
	int producto_getPeso (Producto* this, float* peso);

	//----------DESCRIPCION-----------------------------------------------------
	int producto_setDescripcion(Producto* this, char* descripcion);
	int producto_getDescripcion(Producto* this, char* descripcion);

	//----------PAIS ORIGEN-------------------------------------
	int producto_setPaisOrigen(Producto* this, char* paisOrigen);
	int producto_getPaisOrigen(Producto* this, char* paisOrigen);

	//----------CODIGO ALFANUMERICO---------------------------------------------
	int producto_setCodigoAlfaNumerico(Producto* this, char* codigoAlfaNumerico);
	int producto_getCodigoAlfaNumerico(Producto* this, char* codigoAlfaNumerico);

	//----------ID PRODUCTO---------------------------------------------------------
	int producto_setId(Producto* this, int id);
	int producto_setIdTxt(Producto* this, char* id);
	int producto_getId(Producto* this, int* id);
	//int employee_getIdTxt(Producto* this, char* id, int longitud);

	//----------LARGO EMPAQUE---------------------------------------------------------
	int producto_setLargoEmpaque(Producto* this, float largoEmpaque);
	int producto_setLargoEmpaqueTxt (Producto* this, char* largoEmpaque);
	int producto_getLargoEmpaque(Producto* this, float* largoEmpaque);

	//----------ALTO EMPAQUE---------------------------------------------------------
	int producto_setAltoEmpaque(Producto* this, float altoEmpaque);
	int producto_setAltoEmpaqueTxt (Producto* this, char* altoEmpaque);
	int producto_getAltoEmpaque(Producto* this, float* altoEmpaque);

	//----------ANCHO EMPAQUE--------------------------------------------------------
	int producto_setAnchoEmpaque(Producto* this, float anchoEmpaque);
	int producto_setAnchoEmpaqueTxt (Producto* this, char* anchoEmpaque);
	int producto_getAnchoEmpaque(Producto* this, float* anchoEmpaque);

	//----------VOLUMEN EMPAQUE------------------------------------------------------
	int producto_setVolumenEmpaque(Producto* this, float volumenEmpaque);
	int producto_setVolumenEmpaqueTxt (Producto* this, char* volumenEmpaque);;
	int producto_getVolumenEmpaque(Producto* this, float* volumenEmpaque);

	//----------VALOR FOB EMPAQUE-----------------------------------------------------
	int producto_setValorFobUSD(Producto* this, float valorFobUSD);
	int producto_setValorFobUSDTxt (Producto* this, char* valorFob);
	int producto_getValorFobUSD(Producto* this, float* valorFobUSD);

	//----------PRECIO TRANSPORTE POR MAR (USD)----------------------------------------
	int producto_setPrecioTransporteByMar(Producto* this, float precioTransporteByMar);
	int producto_setPrecioTransporteByMarTxt (Producto* this, char* precioTransporteByMar);
	int producto_getPrecioTransporteByMar(Producto* this, float* precioTransporteByMar);

	//----------PRECIO TRANSPORTE POR AIRE (USD)---------------------------------------
	int producto_setPrecioTransporteByAir(Producto* this, float precioTransporteByAir);
	int producto_setPrecioTransporteByAirTxt (Producto* this, char* precioTransporteByAir);
	int producto_getPrecioTransporteByAir(Producto* this, float* precioTransporteByAir);

	//----------ID POSICION ARANCELARIA------------------------------------------------
	int producto_setIdPosicionArancelaria(Producto* this, int idPosicionArancelaria);
	int producto_setIdPosicionArancelariaTxt(Producto* this, char* id);
	int producto_getIdPosicionArancelaria(Producto* this, int* idPosicionArancelaria);

	//----------FUNCIONES EXTRA (PRINT - SAVER Y LOADER)---------------------------------------------------------------
	int printProducto (Producto* this);
	int save_productos (char* path, Dictionary* this);
	int load_productos (char* path, Dictionary* pListaProductos);
	int parser_ProductoFromText(FILE* pFile , Dictionary* pListaProductos);
	Producto* producto_buscarPorIdPosArancelaria (LinkedList* producto_ll, int idPosArancelariaFind);
	Producto* producto_buscarPorIdProducto (LinkedList* producto_ll, int idProductoToFind);
	//int employeeFuncionCriterio (void* item1 ,void* item2);

	#endif // employee_H_INCLUDED
