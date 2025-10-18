#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void create_circularlinkedlist(struct Node * head){
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    struct Node p=(struct Node)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d",&head->data);
    head->next=NULL;
    p=head;
    for(i=1;i<=n-1;i++){
        p->next=(struct Node *)malloc(sizeof(struct Node));
        p=p->next;
        printf("Enter the value: ");
        scanf("%d",&p->data);
        p->next=NULL;
        if(i==n-1){
            p->next=head;
        }
    }
}

void traversal_circularlinkedlist(struct Node *head){
    struct Node *ptr = head;
    while(ptr->next!=head){
        printf("%d  ", ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}

int main(){
    struct Node head= (struct Node)malloc(sizeof(struct Node));
    create_circularlinkedlist(head);
    traversal_circularlinkedlist(head);
}