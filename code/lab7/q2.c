#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void Enqueue(int x){
    struct Node newnode = (struct Node)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void Traversal(){
    struct Node* temp = front;
    if(front==NULL&&rear==NULL){
        printf("Queue is empty");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void Dequeue(){
    struct Node *temp=front;
    if(front==NULL&&rear==NULL){
        printf("Queue is Empty");
    }
    else{
        if(front==rear){
            printf(temp->data);
            front=rear=NULL;
            free(temp);
        }
        else{
            front=front->next;
            printf(temp->data);
            free(temp);
        }
    }
}

void Peek(){
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front element: %d\n", front->data);
    }
}

void IsEmpty(){
    if (front == NULL && rear == NULL) {
        printf("Yes, the queue is empty.\n");
    }
    else{
        printf("No, there are elements in the queue.\n");
    }
}

int main(){
    int ch;
    printf("\nMENU\n 1.Insert\n 2.Delete\n 3.PEEK\n 4.DISPLAY\n 5.ISEMPTY\n 6.EXIT\n ");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                int x;
                int choice;
                while(1){
                    printf("Enter element : ");
                    scanf("%d",&x);
                    Enqueue(x);
                    printf("Do you want to continue?(0/1) ");
                    scanf("%d", &choice);
                    if(choice==0){
                        break;
                    }
                }
                break;
            }
            case 2:{
                int n,i;
                printf("Enter no. times to delete elements: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    Dequeue();
                }
                break;
            }
            case 3:{
                Peek();
                break;
            }
            case 4:{
                Traversal();
                break;
            }
            case 5:{
                IsEmpty();
                break;
            }
            case 6:{
                return 0;
            }
        }
    }
}