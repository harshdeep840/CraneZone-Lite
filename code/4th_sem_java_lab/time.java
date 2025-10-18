class time
{
    int h,min;

    time(int p,int q) 
    {
        h=p;
        min=q;
    }

    time addtime(time t)
    {
        int tot_min = h*60 + min + t.h*60 + t.min;
        int new_h = tot_min/60;
        int new_min = tot_min%60;
        return new time(new_h,new_min);
    }

    void display()
    {
        System.out.println(h+" hours "+min+" minutes");
    }
}

class compute_time
{
    public static void main(String[] args)
    {
        time t1=new time(2,30);
        time t2=new time(1,45);
        
        time timesum=t1.addtime(t2);
        
        System.out.print("Sum of ");
        t1.display();
        System.out.print("and ");
        t2.display();
        System.out.print("is ");
        timesum.display();
    }
}