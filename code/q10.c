#include<stdio.h>
int main()
{
    int a;
    printf("Input a number");
    scanf("%d",&a);
    if(a%3==0 && a%6==0){
        printf("%d is divisible by 3 and 5 /n",a);
} else {
    printf("%d is not divisible by 3 and 5 /n",a);

}
    return 0;
}