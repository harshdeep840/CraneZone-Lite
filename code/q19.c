#include<stdio.h>
int main()
{
    char a;
    printf("Input a character \n");
    scanf("%c",&a);
    if((a>=65 && a<=90)|| (a>=97 && a<=122)){
        printf(" It is an alphabet \n");
        if(a>=65 && a<=90){
            a=a+32;
            printf("Its opposite case is %c\n",a);
        }else{
            a=a-32;
            printf("Its opposite case is %c \n",a);
        }
        }else {
            printf("It is not an alphabet\n",a);}

    return 0;
}