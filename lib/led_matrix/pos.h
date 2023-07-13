#pragma once

namespace ledmat {

struct Pos {
    int r, c;

    Pos& operator+=(const Pos& rhs) {
        r += rhs.r;
        c += rhs.c;
        return *this;
    }
    Pos& operator-=(const Pos& rhs) {
        r -= rhs.r;
        c -= rhs.c;
        return *this;
    }
    Pos operator+(const Pos& rhs) const {
        auto tmp = *this;
        tmp += rhs;
        return tmp;
    }
    Pos operator-(const Pos& rhs) const {
        auto tmp = *this;
        tmp -= rhs;
        return tmp;
    }
};

} /* ledmat */