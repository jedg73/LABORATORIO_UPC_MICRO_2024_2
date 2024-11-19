#include "LM35.h"

void LM35_init(void) {
    // Configuración del ADC
    TRISAbits.TRISA0 = 1;  // RA0 como entrada
    ANSELAbits.ANSELA0 = 1; // RA0 como analógico
    ADCON0bits.ADFM = 1;     // Justificación a la derecha
    ADCON0bits.CS = 1;       // Fuente de reloj interno (ADCRC)
    ADPCH = 0x00;            // Canal AN0
    ADCON0bits.ADON = 1;     // Habilitar ADC
    ADCON2 = 0x62;           // CRS=6, modo AVG
    ADRPT = NUM_MUESTRAS;    // Repeticiones para promedio
}

uint16_t LM35_readADC(void) {
    uint32_t acumulado = 0;
    for (int i = 0; i < NUM_MUESTRAS; i++) {
        ADCON0bits.GO = 1; // Iniciar conversión
        while (ADCON0bits.GO == 1); // Esperar a que termine
        acumulado += (ADRESH << 8) | ADRESL; // Combinar ADRESH y ADRESL
    }
    return acumulado / NUM_MUESTRAS; // Promedio
}

float LM35_getTemperature(void) {
    uint16_t adc_valor = LM35_readADC(); // Leer ADC con promedio
    float voltaje = (float)adc_valor * (ADC_REF_VOLTAGE / 1024.0); // Convertir ADC -> Voltaje
    return voltaje * 100.0; // Voltaje -> Temperatura (°C)
}
