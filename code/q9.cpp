#include<iostream>
 
int main()
{
    int value_1 { 10};
    int value_2 { -300};
    
    std::cout << " Value 1:" << value_1 << std::endl;
    std::cout << " Value 2:" << value_2 << std::endl;
    
    std::cout << " sizeof(Value 1):" << sizeof(value_1) << std::endl;

    unsigned int value_3 {4};
    std::cout << "Value 3 :" << value_3  << std::endl;
    std::cout << "sizeof(value 3) :" << sizeof( value_3) << "Bytes" << std::endl;

    //unsigned int value_4{ -6} // will give compiler error in unsigned int we will have to use only +ve value.

 return 0;
}