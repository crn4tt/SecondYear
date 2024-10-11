#include <cstdint>
#include <limits>
#include <cstdlib>

template<typename T>
class ArrayHandler {
private:
    T _array[1000000]; 
    size_t _count;
    T _min;
    T _max;

public:
    ArrayHandler()
        : _count(0), _min(std::numeric_limits<T>::max()), _max(std::numeric_limits<T>::min()) {}

    inline void AppendElem(T elem) {
        _array[_count++] = elem;

        _min = (elem < _min) ? elem : _min;
        _max = (elem > _max) ? elem : _max;
    }

    inline T GetMax() const {
        return _max;
    }

    inline T GetMin() const {
        return _min;
    }

    bool IsContains(const T* elem) const {
        const T* end = _array + _count;
        const T* ptr = _array;

        while (ptr < end) {
            if (*ptr == *elem) {
                return true;
            }
            ++ptr;
        }
        return false;
    }
};
