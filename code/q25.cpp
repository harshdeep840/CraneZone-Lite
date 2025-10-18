// switch case
#include<iostream>

int main()
{
    const int pen {10};
    const int eraser {20};
    const int marker {34};
    const int circle {40};

    int tool {eraser};
    switch (tool)
   {
    case pen :{
        std::cout << "Active tool is pen " << std::endl;
    }
    break;

     case marker :{
        std::cout << "Active tool is marker " << std::endl;
    }
    break;

    default : {
        std::cout << "No match found" << std::endl;
    }
    break;
   
    
   } 

 return 0;
}
