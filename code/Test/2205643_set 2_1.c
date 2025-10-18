#include<stdio.h>
int main()
{
    int i;
    float a[5]={3.25,4.16,7.33,6.79,5.34};
    float *max=a,*min=a,*p=a;
    for(i=0;i<5;i++){
        if(*(p+i)>*max) max=p+i;
        if(*(p+i)<*min) min=p+i;
    }
    float temp=*max;
        *max=*min;
        *min=temp;
    for(i=0;i<5;i++){
        printf("%f",a[i]);
    }    
    return 0;
}