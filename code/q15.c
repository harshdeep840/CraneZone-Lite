#include<stdio.h>
int main()
{
    float a,b,c;
    printf("Enter 3 sides of the triangle (a,b,c):\n");
    scanf("%f,%f,%f",&a,&b,&c);
    if(a+b>c && b+c>a && a+c>b){
        printf("The triangle is possible \n");
        if(a==b && b==c){
            printf("The type of triangle is equilateral\n");
        }else if(((a==b) && (b!=c))|| ((b==c) && (b!=c)) || ((a==c) && (a!=b))){
            printf("The type of triangle is isoceles \n");
        }else{
            printf("The type of the triangle is scalene \n");
        } } else{
            printf("No the triangle is not possible\n");

        }
        return 0;
    }
    


    
    
    
    
