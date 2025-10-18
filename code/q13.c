#include<stdio.h>
int main()
{
    int a,b;
    printf("Input two numbers \n");
    scanf("%d %d", &a,&b);
    a>b? printf("%d is greater \n",a):b>a? printf("%d is greater \n",b): printf("Both are equal \n");

    return 0;
}