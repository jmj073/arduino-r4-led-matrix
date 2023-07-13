#if 0

#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

static ArduinoLEDMatrix matrix;

static const
uint32_t happy[] = {
    0x19819,
    0x80000001,
    0x81f8000
};

void setup() {
    Serial.begin(115200);
    matrix.begin();
    matrix.loadFrame(happy);
}

void loop() {
    for (size_t i = 0; i < 10; ++i) {
        matrix.on(i);
        delay(1000);
    }
}

#endif