#include "StringField.h"
#include <iostream>

int main() {
    HashedStringField hsf(64);

    hsf.InsertString("Hello");
    hsf.InsertString("World");

    std::cout << "Contains 'Hello': " << hsf.ContainsString("Hello") << std::endl;
    std::cout << "Contains 'Test': " << hsf.ContainsString("Test") << std::endl;

    std::cout << "All strings: " << hsf << std::endl;

    hsf.RemoveString("World");
    std::cout << "After removal: " << hsf << std::endl;

    return 0;
}
