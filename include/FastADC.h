#pragma once

#include <Arduino.h>
#include <avr/interrupt.h>

#define FAST_ADC_NUM_CHANNELS 6

class FastADC
{
private:
    static const uint8_t muxTable[FAST_ADC_NUM_CHANNELS];

    static uint16_t results[FAST_ADC_NUM_CHANNELS];
    static uint8_t currentIndex;

    static void StartConversion(uint8_t index)
    {
        ADMUX = (1 << REFS0) | (muxTable[index] & 0x0F);
        ADCSRA |= (1 << ADSC);
    }

public:
    static void Begin()
    {
        cli();
        
        ADCSRB = 0;

        // Enable ADC, enable interrupt, set prescaler to /128 (125 kHz @ 16 MHz)
        ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

        currentIndex = 0;
        StartConversion(0);

        sei();
    }

    static uint16_t Get(uint8_t arduinoPin)
    {
        uint8_t index = arduinoPin - A0;
        if (index >= FAST_ADC_NUM_CHANNELS) return 0;

        // results[] is 16-bit; reads are not atomic on an 8-bit CPU, so disable
        // interrupts while we grab the snapshot to prevent a torn read.
        cli();
        uint16_t val = results[index];
        sei();
        return val;
    }

    static void HandleISR()
    {
        uint8_t i = currentIndex;
        
        uint8_t low  = ADCL;  // must read low first
        uint8_t high = ADCH;  // then high
        results[i] = (high << 8) | low;

        currentIndex++;
        if (currentIndex >= FAST_ADC_NUM_CHANNELS)
            currentIndex = 0;

        StartConversion(currentIndex);
    }
};