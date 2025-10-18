#include<stdio.h>
int main()
{
    int n,a,i,rev=0;
    printf("Input a number \n");
    scanf("%d",&n);
    i=n;
    while(i>0){
        a=i%10;
        rev=rev*10+a;
        i/=10;
    }
    printf("The reversed digit is %d",rev);
    return 0;
}    
