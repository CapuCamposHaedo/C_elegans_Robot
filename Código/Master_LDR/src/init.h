#ifndef MCC_H
#define	MCC_H
#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "interrupt_manager.h"
#include "i2c_master.h"
#include "tmr1.h"



/**
 * \brief Inicializa el dispositivo a los estados predeterminados configurados.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void SYSTEM_Initialize(void);

/**
 * \brief Inicializa el oscilador con los valores predeterminados configurados
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void OSCILLATOR_Initialize(void);

/**
 * \brief Inicializa el m�dulo WDT con los valores predeterminados configurados.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void WDT_Initialize(void);

#endif	/* INIT_H */
