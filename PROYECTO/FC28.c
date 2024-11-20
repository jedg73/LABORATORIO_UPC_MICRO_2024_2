#include <xc.h>
#include "FC28.h"

// Definir valores de calibración
#define WET_VALUE 657   // ADC para 100% de humedad (totalmente sumergido)
#define DRY_VALUE 4094  // ADC para 0% de humedad (al aire)



void configuro_adc_fc28(void) {
    ADCON0bits.ADFM = 1;   // Justificación a la derecha
    ADCON0bits.CS = 1;     // Fuente de reloj interno (ADCRC)
    ADPCH = 0x02;          // Canal RA2 (AN2)
    ADCON2 = 0x00;         // Sin promedio
    ADCON0bits.ADON = 1;   // Habilitar ADC
}
void FC28_init(void) {
    // Configuración del ADC para el sensor FC-28
    TRISAbits.TRISA2 = 1;   // Configurar RA2 como entrada
    ANSELAbits.ANSELA2 = 1; // Habilitar RA2 como entrada analógica
    ADCON0bits.ADFM = 1;    // Justificación a la derecha
    ADCON0bits.CS = 1;      // Fuente de reloj interno (ADCRC)
    ADPCH = 0x02;           // Seleccionar canal AN2 (RA2)
    ADCON0bits.ADON = 1;    // Habilitar ADC
}

uint16_t FC28_readADC(void) {
    ADCON0bits.GO = 1;             // Iniciar conversión ADC
    while (ADCON0bits.GO);         // Esperar a que la conversión termine
    return (ADRESH << 8) | ADRESL; // Combinar los registros ADRESH y ADRESL
}

int FC28_getMoisturePercentage(uint16_t adc_val) {
    if (adc_val >= DRY_VALUE) {
        return 0; // 0% de humedad
    } else if (adc_val <= WET_VALUE) {
        return 100; // 100% de humedad
    } else {
        return (1.0 - (float)(adc_val - WET_VALUE) / (DRY_VALUE - WET_VALUE)) * 100.0;
    }
}
