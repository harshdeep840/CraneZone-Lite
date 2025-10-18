#include<stdio.h>
int main()
{
    char a;
    printf("Input an alphabet for weekdays \n");
    scanf("%c",&a);
    switch((a>=97 && a<=122)||(a>=65 && a<=90)){
        case 1:
        switch (a>=97 && a<=122)
        {
            case 1:
            a=a-32;
        }
            switch (a){
                case 'S':
                    printf("Sun");
                    break;
                case 'M':
                    printf("Mon");
                    break;
                case 'T':
                    printf("Tue");
                    break;
                case 'W':
                    printf("Wed");
                    break;
                case 'H':
                    printf("Thurs");
                    break;
                case 'F':
                    printf("Fri");
                    break;
                case 'P':
                    printf("Sat");
                    break;
            }
        }
    return 0;
}