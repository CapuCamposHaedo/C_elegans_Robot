 #ifndef VERTEBRA_H
#define	VERTEBRA_H

#include <xc.h> 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"

#define NUMERO_ESCLAVOS 2 //Cantidad de modulos de accion
#define PWM_REG 15 // Direccion de memoria de PWM

/**
 * \brief Handler de la interrupci�n del TMR1
 *
 * \param[in] Ninguno
 *
 * \return Vac�o
 */
void TMR1_Master_InterruptHandler(void);

/**
 * \brief Obtiene el estado del flag del handler de interrupci�n de TMR1
 *
 * \param[in] Ninguno
 *
 * \return Estado del flag
 */
uint8_t Get_Master_TMR1_flag(void);

/**
 * \brief Resetea el estado del flag del handler de interrupci�n de TMR1
 *
 * \param[in] Ninguno
 *
 * \return Vac�o
 */
void Clear_Master_TMR1_flag(void);

/**
 * \brief Setea el valor del duty cycle que le envia al esclavo seleccionado
 *
 * \param[in] slave- Esclavo seleccionado;ciclo- valor que se le envia al esclavo correspondiente a un duty cycle
 *
 * \return Vac�o
 */
void SetServo(i2c_address_t slave, uint8_t ciclo);

/**
 * \brief Secuencia de movimientos preestablecidos mostrando el rango de rotacion de un m�dulo seleccionado
 *
 * \param[in] esclavo- esclavo seleccionado para rotar
 *
 * \return Vac�o
 */
void Rotar_Slave(uint8_t esclavo);

/**
 * \brief Secuencia de movimientos preestablecidos para todos los m�dulos de acci�n
 *
 * \param[in] Ninguno
 *
 * \return Vac�o
 */
void Rotar_All_Slaves(void);
#endif // VERTEBRA_H

