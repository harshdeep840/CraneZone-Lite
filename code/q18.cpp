//Compound operators
#include<iostream>

int main()
{
    int value {45};
    std::cout << "The value is : " << value << std::endl;

    value+=5;
    std::cout << "The value (after + 5) is : " << value << std::endl;

    value-=5;
    std::cout << " The value (after -5) is : " << value << std::endl;

    value*=4;
    std::cout << "The value (after * 4) is :" << value << std::endl;

    value/=5;
    std::cout << "The value (after / 5 ) is : " << value << std::endl;

     
 return 0;
}