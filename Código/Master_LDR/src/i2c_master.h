#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define NUMERO_ESCLAVOS 2

typedef enum {
    I2C_NOERR, // El mensaje fue enviado.
    I2C_BUSY,  // El mensaje no fue enviado, bus ocupado.
    I2C_FAIL   // El mensaje no fue enviado, fallo del bus.
} i2c_error_t;

typedef enum
{
    I2C_STOP=1,
    I2C_RESTART_READ,
    I2C_RESTART_WRITE,
    I2C_CONTINUE,
    I2C_RESET_LINK
} i2c_operations_t;
typedef enum
{
    SENO,
    COSENO,
    QUIETO            
}estado_movimiento_t;
estado_movimiento_t estado_mov_viejo = SENO, estado_mov_nuevo = SENO;

uint8_t ciclo;

typedef uint8_t i2c_address_t;
typedef i2c_operations_t (*i2c_callback_t)(void *funPtr);

// respuestas de callback
i2c_operations_t I2C_CallbackReturnStop(void *funPtr);
i2c_operations_t I2C_CallbackReturnReset(void *funPtr);

/**
 * \brief Inicializa interfaz I2C 
 *
 * \return vac�o
 */
void I2C_Initialize(void);

/**
 * \brief Abre la comunicaci�n I2C 
 *
 * \param[in] address El address del esclavo con el cual se quiere comunicar
 *
 * \return Estado de inicializaci�n.
 * \retval I2C_NOERR Apertura de la comunicaci�n exitosa
 * \retval I2C_BUSY  Apertura fallo porque la interfaz est� ocupada
 * \retval I2C_FAIL  Apertura fallo con error
 */
i2c_error_t I2C_Open(i2c_address_t address);

/**
 * \brief Cierra interfaz de I2C
 * 
 * \param[in] Ninguno
 *
 * \return Estado de la operaci�n de cierre
 * \retval I2C_NOERR Apertura de la comunicaci�n exitosa
 * \retval I2C_BUSY  Apertura fallo porque la interfaz est� ocupada
 * \retval I2C_FAIL  Apertura fallo con error
 */
i2c_error_t I2C_Close(void);

/**
 * \brief Empienza una operaci�n en una interfaz abierta de I2C
 *
 * \param[in] read Setear a true para lectura , false para escritura
 *
 * \return Estado de operaci�n
 * \retval I2C_NOERR Apertura de la comunicaci�n exitosa
 * \retval I2C_BUSY  Apertura fallo porque la interfaz est� ocupada
 * \retval I2C_FAIL  Apertura fallo con error
 */
i2c_error_t I2C_MasterOperation(bool read);

/**
 * \brief Identico a I2C_MasterOperation(false);
 */
i2c_error_t I2C_MasterWrite(void);

/**
 * \brief Setea el buffer de datos para usar y n�mero de bytes para transferir
 *
 * \param[in] buffer Puntero al buffer de datos para leer o escribir datos
 * \param[in] bufferSize N�mero de bytes para leer o escribir al esclavo
 *
 * \return Vac�o
 */
void I2C_SetBuffer(void *buffer, size_t bufferSize);

// Funciones de eventos de Callback.

/**
 * \brief Setea que se llame al callback cuando todos los datos han sido transferidos.
 *
 * \param[in] cb Puntero a la funcion callback
 * \param[in] ptr  Puntero a los par�metros de la funcion de callback
 *
 * \return Vac�o
 */
void I2C_SetDataCompleteCallback(i2c_callback_t cb, void *ptr);

/**
 * \brief Setea que llame al callback cuando la direcci�n transmitida fue Nack'ed.
 *
 * \param[in] cb Puntero a la funcion callback
 * \param[in] ptr  Puntero a los par�metros de la funcion de callback
 *
 * \return Vac�o
 */
void I2C_SetAddressNackCallback(i2c_callback_t cb, void *ptr);

/**
 * \brief Handler de la interrumpci�n de I2C.
 *        Este es un puntero a la funci�n que ser� llamada cuando haya una interrupci�n de I2C.
 * 
 * \param[in] Ninguno
 *
 * \return Vac�o
 */
void (*MSSP_InterruptHandler)(void);

/**
 * \brief Setea el handler de la interrupci�n de I2C.
 * Este API setea la funci�n que ser� llamada cuando haya una interrupci�n de I2C.
 * 
 * \param[in] Ninguno
 *
 * \return Vac�o
 */
void I2C_SetInterruptHandler(void (* InterruptHandler)(void));

#endif //I2C_MASTER_H