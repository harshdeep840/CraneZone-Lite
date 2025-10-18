
/*
#include<iostream>
using namespace std;
int main()
{
    char message [ 5 ]{ 'h','e','l','l','o'};

    cout << " message : " ;
    for ( auto c : message){
        cout << c;
    }
    cout << endl;
    // change char in our array
     message[1] = 'a';
     std::cout << " message ";
     for( auto c : message){
        std::cout << c;
     }
     std::cout << std::endl;
     
 return 0;
}
*/
#include<iostream>
using namespace std;
int main()
{
    char message [ 6 ] { 'H','e','l','l','o','\0'};
    cout << " Message : " << message << endl;
 return 0;
}

// if a char is null terminated ,Then it's called as C-string


