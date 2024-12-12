#include "StringField.h"
#include <iostream>

int main() {
    StringField sf(16);

    sf.FromString("GigaChad");

    std::cout << "StringField: " << sf << std::endl;

    sf.InsertChar(1, 'a');
    std::cout << "After modification: " << sf.ToString() << std::endl;

    sf.RemoveChar(7);
    std::cout << "After removal: " << sf.ToString() << std::endl;

    return 0;
}
