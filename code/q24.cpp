#include<iostream>

int main()
{
    int number1 = 12;
    int number2 = 21;
    bool result = (number1 < number2);
    std::cout << std::boolalpha << "Result" << result << std::endl;

    std::cout << std::endl;

            if(result == true) {
                std::cout << "The number1 is smaller than number2" << std::endl;
            }else{
                std::cout << "The number1 is not smaller than number2" << std::endl;
            } 
 return 0;
}