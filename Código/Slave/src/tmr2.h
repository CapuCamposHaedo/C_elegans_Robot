#ifndef TMR2_H
#define TMR2_H

#include <stdint.h>
#include <stdbool.h>


/**
 * \brief Routina que inicializa el TMR2.
 *        Debe llamarse antes que cualquier otra rutina de TMR2.
 *        Solo debe llamarse una vez durante la inicializaci�n del sistema.
 *
 * \param[in] Ninguno
 *
 * \return Vac�o

 */
void TMR2_Initialize(void);


#endif // TMR2_H

