/* 
#include<iostream>
using namespace std;
int main()
{
    // Declaration of an array
    int score [10]; // junk data

    // Read Data 
    cout << " score [0] :" << score[0] << endl;

 return 0;
}
*/
 //writing out data 
/*
#include<iostream>
using namespace std;
int main()
{
int score [ 10 ] { 1,2,3,4,5};
for( int i =0;i<10;i++){
    cout << " score [ " << i << "] : " << score [i] << endl;
}


 return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
    int score [10];
    for ( int i=0;i<10;i++){
        score[i] = i*10;
    }
        for( int i = 0;i<10;i++){
            cout << " score [ " << i << "] : " << score [i ]<< endl;
        }
 return 0;
}
*/
/* 
#include<iostream>
using namespace std;
int main()
{
    int families [ 5 ] { 1,2,3};
    for ( int i =0; i<5;i++){
        cout << " families [ " << i << " ] : " << families [ i] << endl;
    }
    
 return 0;
}
*/
#include<iostream>
using namespace std;
int main()
{
    int  scores [ ] { 1,2,3,4,5,6,9};
    int sum {0};
    for( int element : scores ){
        sum+=element;

    }
    std::cout << " score sum : " << sum << std::endl;

 return 0;
}