#include<stdio.h>
int main()
{
    char a;
    printf("Input a character \n");
    scanf("%c",&a);
    if((a>=65 && a<=90)||(a>=97 && a<=122)){
        printf("%c is an alphabet \n",a);
    if(( a>=65 && a<=90)){
        printf("It is an uppercase \n");
    }else{
        printf("It is lowercase \n");
    }}
 else if((a>=48 && a<=57)){
    printf("%c is a number\n");
}else {
    printf( "%c is a symbol\n");
}
    return 0;
}    
