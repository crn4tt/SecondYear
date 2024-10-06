#include <cstddef>
#include <cstring>
#include <cstdint>
#include <limits>

template<typename T>
class ArrayHandler {
private:
    T* _array;
    size_t _size;
    size_t _count;
    T _min;
    T _max;

public:
    ArrayHandler(size_t initial_size = 1000000)
        : _size(initial_size), _count(0), _min(std::numeric_limits<T>::max()), _max(std::numeric_limits<T>::min()) {
        _array = new T[_size];
    }

    void AppendElem(T elem) {
        _array[_count++] = elem;
        _min = (elem < _min) ? elem : _min;
        _max = (elem > _max) ? elem : _max;
    }

    T GetMax() const {
        return _max;
    }

    T GetMin() const {
        return _min;
    }

    bool IsContains(T __restrict* elem) const {
        const T __restrict* end = _array + _count;
        const T __restrict* ptr = _array;


        while (ptr + 16 <= end) {
            if (*ptr == elem || *(ptr + 1) == elem || *(ptr + 2) == elem || *(ptr + 3) == elem ||
                *(ptr + 4) == elem || *(ptr + 5) == elem || *(ptr + 6) == elem || *(ptr + 7) == elem ||
                *(ptr + 8) == elem || *(ptr + 9) == elem || *(ptr + 10) == elem || *(ptr + 11) == elem ||
                *(ptr + 12) == elem || *(ptr + 13) == elem || *(ptr + 14) == elem || *(ptr + 15) == elem) {
                return true;
            }
            ptr += 16;
        }

        while (ptr < end) {
            if (*ptr == elem) {
                return true;
            }
            ++ptr;
        }

        return false;
    }

    ~ArrayHandler() {
        delete[] _array;
    }
};
