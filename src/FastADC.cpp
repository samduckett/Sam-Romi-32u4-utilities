#include "FastADC.h"

const uint8_t FastADC::muxTable[FAST_ADC_NUM_CHANNELS] = {7, 6, 5, 4, 1, 0};

uint16_t FastADC::results[FAST_ADC_NUM_CHANNELS] = {0};
uint8_t FastADC::currentIndex = 0;

// NOTE: ISR(ADC_vect) must be defined in the project that uses this library.
// In the chassis project it is defined in chassis.cpp.