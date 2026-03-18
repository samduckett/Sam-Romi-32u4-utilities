#include "TeleplotUtils.h"

#include <Arduino.h>

void TeleplotPrint(const char* var, float value)
{
    Serial.print('>');
    Serial.print(var);
    Serial.print(':');
    Serial.print(value);
    Serial.print('\n');
}

void TeleplotPrintXY(const char* topic, float x, float y)
{
    Serial.print("\n>");
    Serial.print(topic);
    Serial.print(':');
    Serial.print(x, 5);
    Serial.print(':');
    Serial.print(y, 5);
    Serial.println("|xy");
}
