#include <iostream>
#include <string>

int main(){
    //printing data
    std::cout << " Hello C++" << std::endl;

    int age{31};
    std::cout << " Age :" << age << std::endl;

    std::cerr << " Error message : Something is wrong " << std::endl;
    std::clog << " Log message : Something happened " << std::endl;

    // 
    int age1;
    std::string name;
    std::cout << " Please type your name and age :" << std::endl;

    std::cin >> name;
    std::cin >> age1;

    std::cout << "Hello " << name << " you are " << age1 << " years old" << std::endl;
    return 0;