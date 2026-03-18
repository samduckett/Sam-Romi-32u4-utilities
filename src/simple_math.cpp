#include "simple_math.h"
#include <Arduino.h>

float NormalizeAngle(float angle)
{
    while (angle > M_PI) angle -= 2 * M_PI;
    while (angle < -M_PI) angle += 2 * M_PI;
    return angle;
}

float clamp(float value, float minVal, float maxVal)
{
    if (value > maxVal) return maxVal;
    if (value < minVal) return minVal;
    return value;
}

float clamp(float value, float minVal)
{
    return clamp(value, minVal, minVal);
}

unsigned char SetBit(unsigned char byte, unsigned char bit)
{
  return byte | (1 << bit);
}

unsigned char ClearBit(unsigned char byte, unsigned char bit)
{
  return byte & ~(1 << bit);
}

unsigned int Concatenate(unsigned char highbyte, unsigned char lowbyte)
{
  return (highbyte << 8) | lowbyte;
}