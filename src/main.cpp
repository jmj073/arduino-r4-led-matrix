#if 1 /* file */

#include <Arduino.h>
#include <cstdlib>
#include "led_matrix.h"
#include "dot.h"

using namespace ledmat;

static void play();

static ledmat::MyLEDMatrix matrix;
static Dot dots[3] {
    Dot(4, 0, 1, 1),
    Dot(3, 7, -1, -1),
    Dot(7, 9, 1, -1),
};

void setup() {
    Serial.begin(115200);
    matrix.begin();
}

void loop() {
    play();
    delay(50);
}

static
void next_frame() {
    for (auto& dot: dots) {
        matrix.reset(dot.getPos());
        dot.move();
        matrix.set(dot.getPos());
    }
}

static
void play() {
    next_frame();
    matrix.update();
}

#endif /* file */