#include<stdio.h>
int main()
{
    char a;
    printf("Enter a character: ");
    scanf("%c",&a);
    if(a>=65 && a<=90) {
        a=a-32; 
        printf("In lower case: %c",a);
    } else {
        a=a+32; 
        printf("In upper case: %c",a);
    }
    return 0;
}