// Characters and Text 
// It occupies 1 byte in memory

#include<iostream>

int main()
{
    char character1 {'a' };
    char character2 {'b'};
    char character3 {'c'};

    std::cout << "Character 1 : " << character1 << std::endl;
    std::cout << "Character 2 :"  << character2 << std::endl;
    std::cout << "Character 3 :"  << character3 << std::endl;

    std::cout << std::endl;

    char value =65;
    std::cout << "Value :" << value << std::endl;
    std::cout << "Value int " << static_cast<int>(value) << std::endl;
 return 0;
}