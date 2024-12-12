#pragma once
#include "BitField.h"
#include <string>

class StringField : public BitField {
public:
    StringField(size_t maxLength);
    StringField(const StringField& other);

    void InsertChar(size_t index, char c);       
    void RemoveChar(size_t index);               
    char GetChar(size_t index) const;            
    std::string ToString() const;                
    void FromString(const std::string& str);     

    StringField& operator=(const StringField& other);
    friend std::ostream& operator<<(std::ostream& os, const StringField& sf);
    friend std::istream& operator>>(std::istream& is, StringField& sf);
};
