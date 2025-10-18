#include<iostream>
#include <cmath>

int main()
{
    double weight {7.7};
    //floor
    std::cout << " Weight rounded to floor is : " << std::floor(weight) << std::endl;
    //ceil
    std::cout << "Weight rounded to ceil is : " << std::ceil(weight) << std::endl;

    //abs
    double saving {-5000};
     
     std::cout << "Abs value of weight is : " << std::abs(weight) << std::endl;
     std::cout << "Abs value of saving is : " << std::abs(saving) << std::endl;
     
     double exponential = std::exp(10);
     std::cout << "The exponential of 10 is :" << exponential << std::endl;

     //pow 
     std::cout << "3 ^ 4 is :" << std::pow(3,4) << std::endl;

    // round off
    std::cout << "2.66666 rounded to :" << std::round(2.66666) << std::endl;
     
     
     


 return 0;
}