#include "StringField.h"

HashedStringField::HashedStringField(size_t bitSize) 
    : BitField(bitSize) {}

void HashedStringField::InsertString(const std::string& str) {
    size_t hashValue = _hasher(str);
    size_t bitIndex = hashValue % GetLength();

    SetBit(bitIndex);
    _hashToString[hashValue] = str;
}

void HashedStringField::RemoveString(const std::string& str) {
    size_t hashValue = _hasher(str);
    size_t bitIndex = hashValue % GetLength();

    ClrBit(bitIndex);
    _hashToString.erase(hashValue);
}

bool HashedStringField::ContainsString(const std::string& str) const {
    size_t hashValue = _hasher(str);
    size_t bitIndex = hashValue % GetLength();

    return GetBit(bitIndex);
}

std::string HashedStringField::GetString(size_t hash) const {
    auto it = _hashToString.find(hash);
    if (it != _hashToString.end()) {
        return it->second;
    }
    throw std::invalid_argument("Hash not found in HashedStringField");
}

std::ostream& operator<<(std::ostream& os, const HashedStringField& hsf) {
    for (const auto& [hash, str] : hsf._hashToString) {
        os << str << " ";
    }
    return os;
}
