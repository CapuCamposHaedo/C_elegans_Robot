
#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H


/**
 * \brief Esta macro habilita las interrupciones globales
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)

/**
 * \brief Esta macro deshabilita las interrupciones globales
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)

/**
 * \brief Esta macro habilita las interrupciones de los perif�ricos
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)

/**
 * \brief Esta macro deshabilita las interrupciones de los perif�ricos
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)


#endif  // INTERRUPT_MANAGER_H
