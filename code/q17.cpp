//prefix and postfix + and -
#include<iostream>

int main()
{
    int value { 5 };

    // increment by 1
    value = value + 1;
    std::cout << " The Value is : " << value << std::endl;

    // decrement by 1
    value = value - 1;
    std::cout << " The value is : " << value << std::endl;

    std::cout << " ===== postfix increment and decrement ======== " << std::endl;

    value = 5;
    std::cout << " The value is (incrementing) : " << value++ << std::endl;
    std::cout << " The value is : " << value << std::endl;

    // decrementing

    value = 5;
    std::cout << " The value is ( Decrementing ) : " << value-- << std::endl;
    std::cout << " The value is : " << value << std::endl;


    std::cout << " ==== Prefix Increment and Decrement " << std::endl;

    value = 5;
    
    ++value;
    std::cout << "The Value is (prefix++) : " << value :: std::endl;

    value = 5;
    std::cout << "The value is (Prefix++ in place) : " << ++value << std::endl;





 return 0;
}