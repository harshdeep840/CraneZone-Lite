#include<iostream>
// precision of Float is 7 and double is 15 
// for float and long double we have to put a suffix f and L and we dont require any suffix for double

int main()
{

    float number1 { 1.12345678901234567890f};
    double number2 { 1.12345678901234567890};
    long double number3 {1.12345678901234567890L };

    std::cout << "Sizeof float : " << sizeof(float) << std::endl;
    std::cout << " Size of double :" << sizeof(double) << std::endl;
    std::cout << " Size of long double :" << sizeof(long double) << std::endl;

    // FLoat problems : The precision is usually too limited 
    // For a lot of applications
    float number4 { 192400023.0f}; // error narrowing conversion
    std::cout << " Number 4: " << number4 << std::endl;

    std::cout <<"-----------------------------" << std::endl;

    double number5 {123456789};
    double number6 {1.92400023e8}; // e8 ka mtlb multiply with  10 exp 8
    double number7 {1.924e8};
    double number8 {0.0000000000000003498};
    double number9 {3.498e-11 }; // e-11 ka mtlb multiplying with 10 exp(-11)

    std::cout << "Number 5 :" << number5 << std::endl;
    std::cout << "Number 6 :" << number6 << std::endl;
    std::cout << "Number 7 :" << number7 << std::endl;
    std::cout << "Number 8 :" << number8 << std::endl;
    std::cout << "Number 9 :" << number9 << std::endl;

 return 0;
}