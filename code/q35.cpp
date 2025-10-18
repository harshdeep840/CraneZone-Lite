#include<iostream>
using namespace std;
int main()
{
    int number[ ] { 1,2,3,4,5,6,7,8,9,0};
    // Reads beyond bonds : will read garbage or crash your program
    cout << " number[12] :" << number[12] << endl;
    number[12999] =1000;
    cout << "number[12999] : " << number[12999] << endl;

    std::cout << " program ending....... " << endl;
 return 0;
}