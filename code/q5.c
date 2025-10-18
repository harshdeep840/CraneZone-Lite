#include<stdio.h>
int main()
{
    float r,a,c;
    r=10;
    const float PI= 3.14;
    a=PI*r*r;
    c= 2* PI*r;
    printf("The area is %f sq unit and the circumfernce is %f units\n",a,c);
    return 0;
}