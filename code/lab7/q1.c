 #include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void Enqueue(int data){
    if(rear==N-1){
        printf("Queue Overflow Condition\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else{
        rear++;
        queue[rear]=data;
    }
}

void Dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue Underflow Condition\n");
    }
    else if(front == rear){
        printf("%d ",queue[front]);
        front=rear=-1;
    }
    else{
        printf("%d ",queue[front]);
        front++;
    }
}

void Display(){
    int i;
    if(front==-1 && rear==-1){
        printf("\nQueue is Empty\n");
    }
    else{
        i=front;
        while(i<=rear){
            printf("%d ",queue[i]);
            i++;
        }
    }
}

void Peek(){
    if(front==-1 && rear==-1){
        printf("Queue is Empty\n");
    }
    else{
        printf("%d",queue[front]);
    }
}

int main(){
    int x,n;
    printf("Enter no. of elements in queue: ");
    scanf("%d",&n);
    printf("\nMENU\n 1.INSERT\n 2.DELETE\n 3.PEEK\n 4.DISPLAY\n 5.EXIT\n Enter the choice: ");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&x);
        switch(x){
            case 1:{
                int i,data;
                for(i=0;i<n;i++){
                    printf("Enter element %d : ",i+1);
                    scanf("%d",&data);
                    Enqueue(data);
                }
                break;
            }
            case 2:{
                int i,t;
                printf("Enter the number of times to Delete element: ");
                scanf("%d",&t);
                for(i=0;i<t;i++){
                    Dequeue();
                }
                break;
            }
            case 3:{
                Peek();
                break;
            }
            case 4:{
                Display();
                break;
            }
            case 5:{
                return 0;
            }
        }
    }
}
