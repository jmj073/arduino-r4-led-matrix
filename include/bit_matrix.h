#pragma once

// TODO

#include <cstddef>

#define staconcon static constexpr const // (●'◡'●)


template <std::size_t R, std::size_t C, typename T = unsigned long>
class BitMatrix {
public: // type declaration
    using data_type = T;

public: // constant definition
    staconcon std::size_t ROW = R;
    staconcon std::size_t COLUMN = C;
    staconcon std::size_t data_size = (R * C + (sizeof(T) * 8) - 1) / (sizeof(T) * 8);

public:
    constexpr BitMatrix() noexcept;

public: // element access
    constexpr bool test(std::size_t row, std::size_t col) const;

private:
    T arr[data_size];

};

template <std::size_t R, std::size_t C, typename T>
constexpr BitMatrix<R, C, T>::BitMatrix() noexcept
    : arr{}
{ }

template <std::size_t R, std::size_t C, typename T>
constexpr bool BitMatrix<R, C, T>::test(std::size_t row, std::size_t col) const {

}