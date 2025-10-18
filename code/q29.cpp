// rectangular pattern with row 3 and coloumn 6
#include<iostream>
using namespace std;
int main()
{
    int row,coloumn;
    for(row=1;row<=3;row++){
        for(coloumn =1; coloumn <= 6; coloumn++){
            cout << " * ";
        }
        cout << endl;
    }
 return 0;
}