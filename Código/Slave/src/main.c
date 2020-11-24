/**
 * Autor: Julio Campos Haedo
 * Universisdad: Universidad Nacional de Rio Negro
 * 
 * Prototipo de m�dulo de acci�n
 * Encargado de la lectura de sus sensores cada un intervalo de tiempo seteado por TMR1
 * Encargado del movimiento de sus servomotores.
 */

#include "init.h"
#include "vertebra_slave.h"

void main(void)
{
    // Inicializaz el dispositivo
    SYSTEM_Initialize();

    //Habilitaci�n de interrupciones globales
    INTERRUPT_GlobalInterruptEnable();

    // Habilitaci�n de interrupciones de perif�ricos
    INTERRUPT_PeripheralInterruptEnable();

    I2C_Open(); 
    //Loop principal- Espera eventos para lectura de sensores (Timer1) y manejo de I2C
    while (1)
    {
        if (Get_TMR1_flag())
        {
          Read_Ldr();
          Clear_TMR1_flag();
        }
        if (Get_I2C_reg_flag())
        {
            I2C_Read_Write(Get_I2C_reg());
            Clear_I2C_reg_flag();
            
        }

    }
}
