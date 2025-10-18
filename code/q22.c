#include<stdio.h>
int main()
{
    int i,n;
    printf("Input a number \n");
    scanf("%d",&n);
    for(i=1;i<=10;i++){
        printf("%d \n",i*n);
    }
    return 0;
}