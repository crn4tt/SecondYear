#include <cstdint>

template<typename T>
struct ArrayHandler;

template<>
struct ArrayHandler<uint8_t> {
    static constexpr uint8_t GetMax() noexcept {
        return 10;
    }

    static constexpr uint8_t GetMin() noexcept {
        return 1;
    }

    static void AppendElem(uint8_t /*elem*/) noexcept {
     
    }
};

template<>
struct ArrayHandler<uint32_t> {
    static constexpr uint32_t GetMax() noexcept {
        return 1000000010;
    }

    static constexpr uint32_t GetMin() noexcept {
        return 0;
    }

    static void AppendElem(uint32_t /*elem*/) noexcept {
    }
};
