#include "simple_math.h"

float NormalizeAngle(float &angle)
{
  while (angle > M_PI) angle -= 2 * M_PI;
  while (angle < -M_PI) angle += 2 * M_PI;
  return angle;
}

float clamp(float &value, float minVal, float maxVal)
{
  if (value > maxVal) value = maxVal;
  if (value < minVal) value = minVal;

  return value;
}

float clamp(float &value, float val)
{
  return clamp(value, -val, val);
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