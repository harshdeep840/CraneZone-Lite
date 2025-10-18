#include <iostream>

int main(){

int dog_count {10};
int cat_count {15};

int domesticated_animals { dog_count + cat_count }; 

     std::cout << "Dog count :" << dog_count << std::endl;
     std::cout << "Cat count :" << cat_count << std::endl;
     std::cout << "Domesticated animals count :" << domesticated_animals << std::endl;
     
     std::cout << " Sizeof int :" << sizeof (int) << std::endl;
     std::cout << " Sizeof dog count :" << sizeof dog_count << std::endl;
     std::cout << "sizeof cat count :" << sizeof cat_count << std::endl;
     std::cout << " sizeof domesticated animals :" << sizeof domesticated_animals << std::endl;
    return 0;
}