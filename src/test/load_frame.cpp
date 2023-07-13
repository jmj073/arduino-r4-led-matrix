#if 0 /* file */

#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

static ArduinoLEDMatrix matrix;

static const
uint32_t happy[] = {
    0x19819,
    0x80000001,
    0x81f8000
};

static const
uint32_t heart[] = {
    0x3184a444,
    0x44042081,
    0x100a0040
};

#if 0
void setup() {
    Serial.begin(115200);
    matrix.begin();
}

void loop() {
  matrix.loadFrame(happy);
  delay(500);

  matrix.loadFrame(heart);
  delay(500);
}
#endif

#if 1
void setup() {
    Serial.begin(115200);
    matrix.begin();
    matrix.loadFrame(happy);
    matrix.loadFrame(heart);
}

void loop() {
    matrix.next();
    delay(500);
}
#endif

#endif /* file */