#include<stdio.h>
int main()
{
    int a;
    printf("input a number :\n");
    scanf("%d",&a);
    if(a>0) printf("%d is positive \n",a);
    if(a<0) printf ("%d is negative \n",a);
    if(a==0) printf("%d is zero /n",a);
    return 0;
}