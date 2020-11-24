/**
 * Autor: Julio Campos Haedo
 * Universisdad: Universidad Nacional de Rio Negro
 * 
 * Prototipo de m�dulo de comunicaci�n.
 * Encargado de la lectura de los sensores de los m�dulos de acci�n.
 * Luego de la lectura de los sensores, le env�a a cada esclavo un valor correspondiente
 * a la posici�n que deben tomar los servomotores.
 */

#include "init.h"
#include "vertebra_master_ldr.h"


void main(void)
{
    // Inicializaci�n del dispositivo
    SYSTEM_Initialize();

    //Habilitaci�n de interrupciones globales
    INTERRUPT_GlobalInterruptEnable();

    // Habilitaci�n de interrupciones de perif�ricos
    INTERRUPT_PeripheralInterruptEnable();
    
    //Loop principal- Espera el evento de Timer1 para leer los registros de sensores de los modulos de accion.
    while (1)
    {
        if (Get_Master_TMR1_flag())
        {
             Read_All_Slave_Sensors();
             Clear_Master_TMR1_flag();
        } 
    }
}
