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
 * \brief Esta macro habilita las interrupciones de los perif�ricos
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)



#endif  // INTERRUPT_MANAGER_H
/**
 End of File
*/
