/**
 * Autor: Julio Campos Haedo
 * Universisdad: Universidad Nacional de Rio Negro
 * 
 * Prototipo de m�dulo de comunicaci�n.
 * Encargado de la poner a prueba el rango de rotaci�n de los m�dulos de acci�n
 * con movimientos preestablecidos.
 * Banco de prueba de las oscilaciones del robot.
 */

#include "init.h"
#include "vertebra.h"

void main(void)
{
    // Inicializaci�n del dispositivo
    SYSTEM_Initialize();
    
    //Habilitaci�n de interrupciones globales
    INTERRUPT_GlobalInterruptEnable();

    // Habilitaci�n de interrupciones de perif�ricos
    INTERRUPT_PeripheralInterruptEnable();
    
    //Loop principal- Espera el evennto de Timer 1 para girar los servomotores
    while (1)
    {
         if (Get_Master_TMR1_flag())
        {
             Rotar_All_Slaves();
             Clear_Master_TMR1_flag();
        }
    }
}
