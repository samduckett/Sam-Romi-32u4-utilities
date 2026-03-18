#pragma once

/**
 * Normalize an angle to the range [-pi, pi].
 */
float NormalizeAngle(float angle);

/**
 * Clamp a value between a minimum and maximum.
 */
float clamp(float value, float minVal, float maxVal);

/**
 * Clamp a value between another value.
 */
float clamp(float value, float minVal);