#include<stdio.h>
int main()
{
    int a,n,i,rev=0;
    printf("Enter a number \n");
    scanf("%d",&n);
    i=n;
    while(i>0){
        a=i%10;
        rev=rev*10+a;
        i/=10;
    }
    printf("The reversed digit is %d",rev);
    if(rev==n){
        printf("It is palindrome \n");
    }else{
        printf("It is not palindrome \n");
    }
    
    return 0;
}