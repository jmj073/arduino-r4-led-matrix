#pragma once

#include "led_matrix.h"

class Dot {
public:
    Dot(int row, int col, int drow = 1, int dcol = 1)
        : pos{ row, col }, delta{ drow, dcol } { }

    void move() {
        dot_bounce_if_hit();
        pos += delta;
    }

    ledmat::Pos getPos() const {
        return pos;
    }
    int getRow() const {
        return pos.r;
    }
    int getCol() const {
        return pos.c;
    }

private:
    void dot_bounce_if_hit() {
        auto next_pos = pos + delta;

        if (next_pos.c < 0) delta.c = 1;
        else if (next_pos.c >= ledmat::MATRIX_COL) delta.c = -1;

        if (next_pos.r < 0) delta.r = 1;
        else if (next_pos.r >= ledmat::MATRIX_ROW) delta.r = -1;
    }

private:
    ledmat::Pos pos;
    ledmat::Pos delta;
};