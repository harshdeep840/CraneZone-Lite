#include<iostream>
using namespace std;
int main()
{
    int num;
    cout << " enter a number : " << endl;
    cin >> num;
    int sum=0;
    
    int i =1;
    while(i<=num){
        sum+=i;
        i++;
    }
    cout << " The sum is " << sum << endl;
 return 0;
}