#pragma once
#include "BitField.h"
#include <string>
#include <functional>
#include <unordered_map>

class HashedStringField : public BitField {
private:
    std::unordered_map<size_t, std::string> _hashToString;
    std::hash<std::string> _hasher;

public:
    HashedStringField(size_t bitSize);

    void InsertString(const std::string& str);
    void RemoveString(const std::string& str);
    bool ContainsString(const std::string& str) const;
    std::string GetString(size_t hash) const;

    friend std::ostream& operator<<(std::ostream& os, const HashedStringField& hsf);
};
