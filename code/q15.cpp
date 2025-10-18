// Operation on data
// basic operations
#include<iostream>

int main()
{
    // Addition
    int number_1 { 12};
    int number_2 { 13};

    int add {number_1 + number_2 };
    std::cout << " Add : " << add << std::endl;

    // substraction

    int substract {number_1 - number_2 };
    std::cout << " Substract : " << substract << std::endl;
     // multiplication

     int multiply {number_1 * number_2  };
     std::cout << "Multiply : " << multiply << std::endl;

     // Divide 
      int divide {number_1 / number_2 };
      std::cout << "Divide : " << divide << std::endl;

      //modulus

      int modulus { number_1 % number_2};
      std::cout << "Modulus : " << modulus << std::endl;

     int result = 31%10;
     std::cout << "Result : " << result << std::endl;
      
 return 0;
}