#include <xc.h>
#include "LDR.h"

void captura_ADC(void) {
    ADCON0bits.GO = 1; // Inicia la conversión ADC
    while (ADCON0bits.GO == 1); // Espera a que termine la conversión
}

int convierte_a_porcentaje(unsigned char luz) {
    int porcentaje = (luz * 100) / 254; // Convierte la luz en porcentaje
    return porcentaje;
}
