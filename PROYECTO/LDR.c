#include <xc.h>
#include "LDR.h"


void configuro_adc_ldr(void) {
    ADCON0bits.ADFM = 0;   // Justificación a la izquierda
    ADCON0bits.CS = 1;     // Fuente de reloj interno (ADCRC)
    ADPCH = 0x01;          // Canal RA1 (AN1)
    ADCON2 = 0x62;         // CRS = 6 (modo promedio)
    ADRPT = 64;            // Número de repeticiones
    ADCON0bits.ADON = 1;   // Habilitar ADC
}
void captura_ADC(void) {
    ADCON0bits.GO = 1; // Inicia la conversión ADC
    while (ADCON0bits.GO == 1); // Espera a que termine la conversión
}

int convierte_a_porcentaje(unsigned char luz) {
    int porcentaje = (luz * 100) / 254; // Convierte la luz en porcentaje
    return porcentaje;
}
