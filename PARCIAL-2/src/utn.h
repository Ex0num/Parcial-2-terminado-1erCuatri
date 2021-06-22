/*
 * utn.h
 *
 *  Created on: Apr 6, 2020
 *      Author: Mauro
 */

#ifndef UTN_H_
#define UTN_H_

//------------F I R M A S   D E   B I B L I O T E C A    U T N -------------------------------------------------
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int esNombre(char* cadena,int longitud);
int esFlotante(char* cadena);
int esNumerica(char* cadena, int limite);
int esSueldoValido (char* arraySueldoValido, int longitudArraySueldoValido);
int esHoraTrabajadaValida (char* arrayHorasTrabajadas, int longitudArrayHorasTrabajadas);
int esIdValidoInt (int id);
int esSueldoValidoInt (int sueldo);
int esHoraTrabajadaValidaInt (int horasTrabajadas);
//------------------------------------------------------------------------------------------------------------


//------------VALIDACIONES ESPECIFICAS DE LOS CAMPOS DE PRODUCTO. (VALIDACIONES DE CADENA Y DE INT)----------
int esNombreValido (char* pCadenaAVerificar, int longitudCadenaAVerificar);
int esPesoValido (float peso);
int esDescripcion(char* cadena,int longitud);
int esCodigoAlfaNumerico(char* cadena,int longitud);
int esIdValido (char* arrayId, int longitudArrayId);
int esLargoEmpaqueValido (float largoEmpaque);
int esAltoEmpaqueValido (float altoEmpaque);
int esAnchoEmpaqueValido (float anchoEmpaque);
int esVolumenEmpaqueValido (float volumenEmpaque);
int esValorFobUSDValido (float valorFobUSD);
int esPrecioValido (float precioRecibido);
int esTipoLicenciaValido (int tipoLicencia);

//------------VALIDACIONES ESPECIFICAS DE LOS CAMPOS DE POSCION ARANCELARIA (VALIDACIONES DE CADENA Y DE INT)----------
int esPorcentajeValido (float porcentaje);
int esNomenclatura(char* cadena,int longitud);
int esTipoLicenciaValido (int tipoLicencia);
int esPorcentajeValidoTxt(char* cadena,int longitud);
int esTipoLicenciaValidoTxt(char* cadena,int longitud);

//------------VALIDACIONES ESPECIFICAS DE LOS CAMPOS DE TRANSPORTE MARITIMO. (VALIDACIONES DE CADENA Y DE INT)----------
int esMetrosCubicosContainer(float mtsCubicos);
int esMetrosCubicosContainerTxt(char* cadena,int longitud);
int esPrecioPorMtCubico (float precioporMtCubicos);
int esPrecioPorMtCubicoTxt(char* cadena,int longitud);

//------------VALIDACIONES ESPECIFICAS DE LOS CAMPOS DE TRANSPORTE AEREO. (VALIDACIONES DE CADENA Y DE INT)----------------
int esConstanteVolumetrica (float constanteVolumetrica);
int esConstanteVolumetricaTxt(char* cadena,int longitud);
int esPrecioPorKg (float precioPorKG);
int esPrecioPorKgTxt (char* precioPorkG);

//---------------FUNCIONES EXTRAS-------------
int utn_obtener_orden_si_no (char* mensajePedido, char* mensajeError, int reintentos);
void printMenuProductos (void);
void printMenuPosicionesArancelarias (void);
void printMensajeDespedida (void);
//-------------------------------------------


//---------------FUNCIONES DE CALCULOS-------------
int calcular_volumenDeEmpaqueCENTIMETROS (float alto, float largo, float ancho, float* volumen);
int calcular_volumenDeEmpaqueMETROS (float alto, float largo, float ancho, float* pResultado);
int calcular_precioTransporteByMar (float volumenMtsCubicos, float precioPorMetroCubico, float* pResultado);
//---
int calcular_resultado1PrecioAereoCONSTANTEVOL (float volumenCM, float constanteVolumetrica, float precioPorKG, float* pPrecioResultado1);
int calcular_resultado2PrecioPORKG (float pesoKg, float precioPorKG, float* pPrecioResultado2);


#endif /* UTN_H_ */
