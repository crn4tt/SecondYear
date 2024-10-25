#include <cstdint>

template<typename T>
struct ArrayHandler;

template<>
struct ArrayHandler<uint8_t> {
    static constexpr uint8_t Max = 10;
    static constexpr uint8_t Min = 1;

    static void AppendElem(uint8_t ) noexcept {
    }
};

template<>
struct ArrayHandler<uint32_t> {
    static constexpr uint32_t Max = 1000000010;
    static constexpr uint32_t Min = 0;

    static void AppendElem(uint32_t ) noexcept {
    }
};
