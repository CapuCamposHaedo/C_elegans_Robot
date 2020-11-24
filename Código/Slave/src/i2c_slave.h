#ifndef I2C_SLAVE_H
#define I2C_SLAVE_H

#include <stdbool.h>
#include <stdint.h>

//Handler de la interrupci�n I2C
typedef void (*i2cInterruptHandler)(void);

/**
 * \brief Inicializa la interfaz I2C.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void I2C_Initialize(void);



/**
 * \brief Abre la comunicaci�n I2C. Habilita el m�dlo si est� deshabilitado.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void I2C_Open(void);

/**
 * \brief Cierra la comunicaci�n I2C. Deshabilita el m�dlo si est� habilitado.
 *        Deshabilita el reconocimiento del address.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void I2C_Close(void);

/**
 * \brief Lee los datos de la comunicaci�n I2C.
 *
 * \param[in] Ninguno
 *
 * \return Datos obtenidos

 */
uint8_t I2C_Read(void);

/**
 * \brief Escribe los datos a trav�s de la comunicaci�n I2C.
 *
 * \param[in] data- Datos que se quieren escribir
 *
 * \return Vac�o

 */
void I2C_Write(uint8_t data);

/**
 * \brief Revisa si el pedido del Master fue de escritura o lectura
 *
 * \param[in] Ninguno
 *
 * \return 1-Master pide leer
 *         0-Master pide escribir

 */
bool I2C_IsRead(void);

/**
 * \brief Habilita la comunicaci�n inicializando el hardware
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void I2C_Enable(void);

/**
 * \brief Env�a se�al de Ack al Master.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void I2C_SendAck(void);

/**
 * \brief Env�a se�al de Nack al Master.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void I2C_SendNack(void);

/**
 * \brief La funci�n llamada por el Handler del Irq del I2C.
 *
 * \param[in] handler
 *
 * \return Vac�o

 */
void I2C_SlaveSetIsrHandler(i2cInterruptHandler handler);
void I2C_SlaveSetAddrIntHandler(i2cInterruptHandler handler);
void I2C_SlaveSetReadIntHandler(i2cInterruptHandler handler);
void I2C_SlaveSetWriteIntHandler(i2cInterruptHandler handler);
void I2C_SlaveSetBusColIntHandler(i2cInterruptHandler handler);
void I2C_SlaveSetWrColIntHandler(i2cInterruptHandler handler);

void (*MSSP_InterruptHandler)(void);
void (*I2C_SlaveRdInterruptHandler)(void);
void (*I2C_SlaveWrInterruptHandler)(void);
void (*I2C_SlaveAddrInterruptHandler)(void);
void (*I2C_SlaveBusColInterruptHandler)(void);
void (*I2C_SlaveWrColInterruptHandler)(void);

void Data_to_master(uint8_t i2c_wr_data);
uint8_t Get_Data_to_master(void);

#endif /* I2C_SLAVE_H */