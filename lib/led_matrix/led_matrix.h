#pragma once

#include <Arduino_LED_Matrix.h>
#include "led_matrix_frame.h"
#include "pos.h"

namespace ledmat {

    static constexpr const size_t MATRIX_ROW = 8;
    static constexpr const size_t MATRIX_COL = 12;

class MyLEDMatrix {
public:
    MyLEDMatrix(): mat() { }

    void begin() {
        mat.begin();
    }

    void update() {
        mat.loadFrame(frame.data());
    }

public:
    void set(size_t r, size_t c, bool value = true) {
        frame.set(r, c, value);
    }
    void set(const Pos& pos, bool value = true) {
        set(pos.r, pos.c, value);
    }

    void reset(size_t r, size_t c) {
        set(r, c, false);
    }
    void reset(const Pos& pos) {
        set(pos, false);
    }

    bool get(size_t r, size_t c) const {
        return frame.test(r, c);
    }

    void clear() { frame.clear(); }
    void fill() { frame.fill(); }

private:

private:
    ArduinoLEDMatrix mat;
    Frame frame{};
};

} /* ledmat */