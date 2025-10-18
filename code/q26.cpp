// Ternary operator
#include<iostream>

int main()
{
    int a = 20;
    int b = 10;
    int max {};

    std::cout << std::endl;
    std::cout << "Using normal if else statement " << std::endl;


   /* if(a > b){
        max = a;
    }else{
        max = b;
    }
   */
     // using ternary operator

     max = (a>b)?a:b;
     std::cout << " Max : " << max << std::endl;

 return 0;
}