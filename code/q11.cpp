// Booleans- it stores true and false
// it occupies 1 bytes


#include<iostream>

int main()
{
    bool red_light {true};
    bool green_light {false};

    if(red_light ){
        std::cout << " Stop!" << std::endl;
    }else{
        std::cout <<"Go through!" << std::endl;
    } 

    if(green_light ) {
        std::cout << " The light is green" << std::endl;
    }else{
        std::cout << "The light is not green" << std::endl;
    }

    //Size of boolean 

    std::cout << " Sizeof bool:" << sizeof(bool) << std::endl;

    /* printing out bool
        1 --> true
        0 --> false

    
    */
    std::cout << std::endl;
    std::cout << " Red light :" << red_light << std::endl;
    std::cout << " Green light :" << green_light << std::endl;
    
    std::cout << std::boolalpha; // (boolaplha) is used to display true or false
    std::cout << std::endl;
    std::cout << " Red light :" << red_light << std::endl;
    std::cout << " Green light :" << green_light << std::endl;



    
 return 0;
}