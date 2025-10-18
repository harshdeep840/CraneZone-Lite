// Relational operators : comparing stuffs
#include<iostream>

int main()
{ 
    int number1 {23};
    int number2 {24};

    std::cout << "Number 1 is :" << number1 << std::endl;
    std::cout << "Number 2 is :" << number2 << std::endl;

    std::cout << std::endl;

    std::cout << "Comapring variables " << std::endl;
    std::cout << std::boolalpha;

    std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
    std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number2 : " << (number1 <= number2) << std::endl;
    std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
    std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;
    
    
    
    
    

    


 return 0;
}