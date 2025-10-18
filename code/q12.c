#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter 3 numbers (a,b,c) \n");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a>b && a>c)
    printf("%d is the largest numnber \n",a);
    if(b>a && b>c)
    printf("%d is the largest number \n",b);
    if(c>a && c>b)
    printf("%d is the largest number \n",c);
    return 0;
}