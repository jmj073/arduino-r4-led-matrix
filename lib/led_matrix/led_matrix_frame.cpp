#include "led_matrix_frame.h"

using namespace ledmat;

inline
auto Frame::rc2ij(size_t r, size_t c) -> IJ {
    size_t pos = r * 12 + c;
    size_t i = pos >> 5;
    size_t j = 0x1F - (pos & 0x1F);
    return { i, j };
}

void Frame::set(size_t r, size_t c, bool value) {
    auto [i, j] = rc2ij(r, c);
    uint32_t mask = (uint32_t)1 << j;
    arr[i] = (arr[i] & ~mask) | ((uint32_t)value << j);
}

bool Frame::test(size_t r, size_t c) const {
    auto [i, j] = rc2ij(r, c);
    return (arr[i] >> j) & 1;
}