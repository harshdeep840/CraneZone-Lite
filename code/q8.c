#include<stdio.h>
int main()
{
    int r1,r2,p1,p2,r,p;
    r1=7;
    p1=60;
    r2=8;
    p2=50;
    r=r1+r2+(p1+p2)/100;
    p=(p1+p2)%100;
    printf("The addition of the two prices is%d rupees and %d paisa",r,p);
    return 0;
}