#ifndef FC28_H
#define FC28_H

#include <stdint.h>

// Prototipos de funciones
void FC28_init(void);
uint16_t FC28_readADC(void);
int FC28_getMoisturePercentage(uint16_t adc_val);

#endif /* FC28_H */
