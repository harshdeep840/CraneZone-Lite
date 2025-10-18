#include<stdio.h>
int main()
{
    int a=10;
    printf("Input a number");
    scanf("%d",&a);
    if(a%3==0 || a%5==0){
        printf("yes,%d is divisible by either 3 or 5 ",a);
    } else {
        printf("No,%d is not divisible by either 3 or 5 ",a);
    }

    return 0;
}