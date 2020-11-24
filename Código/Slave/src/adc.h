#ifndef ADC_H
#define ADC_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


//Tama�o del resultado de ujna conversi�n A/D
typedef uint16_t adc_result_t;

//Definici�n del canal ADC

typedef enum
{
    LDR_Left =  0x3,
    LDR_Right =  0x6,
    channel_Temp =  0x1D,
    channel_DAC =  0x1E,
    channel_FVR =  0x1F
} adc_channel_t;

/**
 * \brief Inicializa el ADC.
 *        Esta rutina debe llamarse antes de cualquier otra rutina del ADC
 *        A esta rutina se la deber�a llamar una sola vez durante la inicializaci�n del sistema
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void ADC_Initialize(void);

/**
 * \brief Esta rutina devuelve el valor de la conversi�n A/D del canal seleccionado.
 *
 * \param[in] channel- Canal donde se desea realizar la conversi�n A/D.
 *
 * \return Valor de la conversi�n.

 */
adc_result_t ADC_GetConversion(adc_channel_t channel);

#endif	//ADC_H
