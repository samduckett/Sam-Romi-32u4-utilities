#pragma once
/** The constant \a pi.	*/
#define M_PI		3.14159265358979323846	/* pi */

/**
 * Normalize an angle to the range [-pi, pi].
 */
float NormalizeAngle(float &angle);

/**
 * Clamp a value between a minimum and maximum.
 */
float clamp(float &value, float minVal, float maxVal);

/**
 * Clamp a value between another value.
 */
float clamp(float &value, float val);

unsigned char SetBit(unsigned char byte, unsigned char bit);

unsigned char ClearBit(unsigned char byte, unsigned char bit);

/**
 * Shifts the high byte 8 into the higher bits and ors the lower bits creating a single 16 bit int
 *
 * @param highbyte The byte to place in the high 8 bits
 * @param lowbyte The byte to place in the low 8 bits
 * @return A 16-bit unsigned integer with highbyte in the upper half
 *         and lowbyte in the lower half.
 */
unsigned int Concatenate(unsigned char highbyte, unsigned char lowbyte);