#include<stdio.h>
int main()
{
    float a,b,c,d,e,f,tot,avg,per;
    char grade;
    printf("Input the marks of 5 subjects \n");
    scanf("%f,%f,%f,%f,%f",&a,&b,&c,&d,&e);
    tot=(a+b+c+d+e+f);
    avg=tot/(float)5;
    per=tot/((float)500)*100;
    if(per<50){
        grade='F';
    }else if(per>=50 && per<60){
        grade='C';
    }else if (per>=60 && per<70){
        grade ='B';
    }else if (per >=70 && per<80){
        grade ='A';
    }else if(per>=80 && per<90){
        grade ='E';
    }else if(per >=90 && per<=100){
        grade ='o';
    }else{
        grade'o';
    }
    printf(" Total Marks: %f \n average marks:%f \n percentage: %f%%\n grade:%c",tot,avg,per,grade);
    return 0;
}            


    