import java.util.Scanner;

class demo1{
    float area(int x,int y){
        return 0.5f*x*y;
    }
    float area(float x){
        return 3.14f*x*x;
    }
    int area(int x){
        return x*x;
    }
}
public class q6  {
    public static void main(String [] args){
        Scanner ob = new Scanner(System.in);
        System.out.println("enter dimension radius base height side ");
        demo1 ob1= new demo1();
        float a=ob.nextFloat();
        int b=ob.nextInt();
        int c=ob.nextInt();
        int g=ob.nextInt();
        float d= ob1.area(b,c);
        float e= ob1.area(a);
        float f= ob1.area(g);
        System.out.println("Area of triangle is  "+d);
        System.out.println("Area of circle is  "+e);
        System.out.println("Area of square is  "+f);

    }
}