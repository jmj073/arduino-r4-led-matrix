#pragma once

#include <cstdint>
#include <cstddef>

namespace ledmat {

class Frame {
private:
    struct IJ { size_t i, j; };

public:
    Frame() : arr{} { }

    uint32_t* data() { return arr; }
    const uint32_t* data() const { return arr; }

    void set(size_t r, size_t c, bool value = true);
    void reset(size_t r, size_t c) {
        set(r, c, false);
    }
    bool test(size_t r, size_t c) const;

    void clear() {
        for (auto& a: arr) a = 0;
    }
    void fill() {
        for (auto& a: arr) a = 0xFFFFFFFFUL;
    }

private:
    static IJ rc2ij(size_t r, size_t c);

private:
    uint32_t arr[3];
};


} /* ledmat */