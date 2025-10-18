// Precedence and associativity
// Precedence --> which operation to do first
// associativity --> which direction or which order
#include<iostream>

int main()
{
    int a { 1};
    int b{ 12};
    int c {2};
    int d{31};
    int e { 21};
    int f {11};
    int g {33};

    int result = a+b*c -d/e -f +g;
    std::cout << "Result : " << result << std::endl;
    result = a/b*c+d - e  + f;
    std::cout << "Result : " << result << std::endl;
    
 return 0;
}