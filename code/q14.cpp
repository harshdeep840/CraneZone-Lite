//Assignments
#include<iostream>

int main()
{
    int var1 {12}; // Declare 
    std::cout << "Var1 :" << var1 << std::endl;

    var1= 55; // Assign
    std::cout << "Var1:" << var1 << std::endl;

    std::cout << std::endl;
    std::cout << "------------------" << std::endl;

    double var2 {40.55}; // declare
    std::cout << "Var2 : " << var2 << std::endl;

    var2 = 41.55; // Assign
    std::cout << "var2 : " << var2 << std::endl;
    
    std::cout << std::endl;
    std::cout << "----------------" << std::endl;

    bool state{ false}; // Declare
    std::cout << std::boolalpha;
    std::cout << "State : " << state << std::endl;
    
    state = true; // assign
    std::cout << "State : " << state << std::endl;

    std::cout << "---------------" << std::endl;

    auto var3 { 2333u};
    std::cout << "Var3 : " << var3 << std::endl;

    var3 = { 22 }; // assign negative number is danger 
    std::cout << "var3 : " << var3 << std::endl;

     return 0;
}