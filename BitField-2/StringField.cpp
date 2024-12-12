#include "StringField.h"
#include <stdexcept>

StringField::StringField(size_t maxLength) 
    : BitField(maxLength * 8) {}

StringField::StringField(const StringField& other) 
    : BitField(other) {}

void StringField::InsertChar(size_t index, char c) {
    if (index * 8 >= GetLength()) {
        throw std::out_of_range("Index out of range for BitField size");
    }

    for (int i = 0; i < 8; ++i) {
        if ((c >> i) & 1) {
            SetBit(index * 8 + i);
        } else {
            ClrBit(index * 8 + i);
        }
    }
}

void StringField::RemoveChar(size_t index) {
    if (index * 8 >= GetLength()) {
        throw std::out_of_range("Index out of range for BitField size");
    }

    for (int i = 0; i < 8; ++i) {
        ClrBit(index * 8 + i);
    }
}

char StringField::GetChar(size_t index) const {
    if (index * 8 >= GetLength()) {
        throw std::out_of_range("Index out of range for BitField size");
    }

    char c = 0;
    for (int i = 0; i < 8; ++i) {
        if (GetBit(index * 8 + i)) {
            c |= (1 << i);
        }
    }
    return c;
}

std::string StringField::ToString() const {
    std::string result;
    size_t length = GetLength() / 8;
    for (size_t i = 0; i < length; ++i) {
        char c = GetChar(i);
        if (c == '\0') break;
        result += c;
    }
    return result;
}

void StringField::FromString(const std::string& str) {
    if (str.size() * 8 > GetLength()) {
        throw std::out_of_range("String is too large for BitField size");
    }

    for (size_t i = 0; i < str.size(); ++i) {
        InsertChar(i, str[i]);
    }

    InsertChar(str.size(), '\0');
}

StringField& StringField::operator=(const StringField& other) {
    if (this != &other) {
        BitField::operator=(other);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const StringField& sf) {
    os << sf.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, StringField& sf) {
    std::string input;
    is >> input;
    sf.FromString(input);
    return is;
}
