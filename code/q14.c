#include<stdio.h>
int main()
{
   int a,u,t;
   printf("Enter a number\n");
   scanf("%d",&a);
   u=a%10;
   t=(a/10)%10;
   printf("unit digit is %d and tens digit is %d \n ",u,t); 
    return 0;
}