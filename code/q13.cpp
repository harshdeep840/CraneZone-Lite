// Auto --> It let the compiler deduce the type

#include<iostream>

int main()
{
    auto var1 { 12};
    auto var2 { 13.0};
    auto var3 {14.0f };
    auto var4 {15.0l };
    auto var5 {'x'};
    auto var6 {123u}; // unsigned k liye u suffix use kiya jaata hai
    auto var7 {123ul }; // unsigned long
    auto var8 {123ll}; //long long

    std::cout << "Sizeof Var 1: " << sizeof(var1)  << "bytes" << std::endl;
    std::cout << "Sizeof Var 2: " << sizeof(var2) << "bytes"<< std::endl;
    std::cout << "Sizeof Var 3: " << sizeof(var3) << "bytes" << std::endl;
    std::cout << "Sizeof Var 4: " << sizeof(var4) << "bytes" <<std::endl;
    std::cout << "Sizeof Var 6: " << sizeof(var6) << "bytes"<<std::endl;
    std::cout << "Sizeof Var 7: " << sizeof(var7) << "bytes" << std::endl;
    std::cout << "Sizeof Var 8: " << sizeof(var8) << "bytes" << std::endl;
    std::cout << "Sizeof Var 5: " << sizeof(var5) << "bytes" << std::endl;

 return 0;
}