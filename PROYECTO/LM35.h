#ifndef LM35_H
#define LM35_H

#include <xc.h>
#include <stdint.h>

// Definiciones
#define ADC_REF_VOLTAGE 1.024 // Cambiar si usas VDD como referencia
#define NUM_MUESTRAS 64       // Número de muestras para el promedio

// Prototipos de funciones
void LM35_init(void);             // Inicializa el ADC para el LM35
uint16_t LM35_readADC(void);      // Lee el valor promedio del ADC
float LM35_getTemperature(void);  // Convierte el valor ADC a temperatura

#endif /* LM35_H */
