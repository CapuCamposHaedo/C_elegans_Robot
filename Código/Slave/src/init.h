#ifndef INIT_H
#define	INIT_H
#include <xc.h>
#include "device_config.h"
#include "pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "interrupt_manager.h"
#include "i2c_slave.h"
#include "pwm1.h"
#include "pwm2.h"
#include "tmr1.h"
#include "tmr2.h"
#include "adc.h"
#include "vertebra_slave.h"


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

#endif	/* MCC_H */
