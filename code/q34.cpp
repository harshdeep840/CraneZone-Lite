#include<iostream>
using namespace std;
int main()
{
    char message1 [ ] {'H','E','l','l','o','\0'};
    cout << " message1 : " << message1 << endl;

    char message2 [ 6 ] {'H','E','l','l','o'};
    cout << "Sizeof(message2) :  " << sizeof(message2) << endl;
    cout << "message2 : " << message2 << " \n";

    char message3 [ ] { " Hello world "};
    cout << " message3 : " << message3 << " \n";
    cout << " sizeof(message3) : " << sizeof(message3) << " \n";

 return 0;
}