#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

void Create_DLinkedList(){
    head=NULL;
    struct Node *temp;
    int n;
    printf("Enter the number of nodes needed: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct Node newnode=(struct Node)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==0){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
}

void traversal_Dlinkedlist(struct Node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

void search_Dlinkedlist(struct Node *head, int value){
    int i =0;
    int j = 0;
    while(head!=NULL){
        if(head->data==value){
            printf("\nElement found at %d",i+1);
            j++;
        }
        i++;
        head=head->next;
    }
    if (j == 0) {printf("\nNo element Found");}
}

struct Node * insert_index_Dlinkedlist(struct Node *head, int data, int dex){
    struct Node ptr=(struct Node)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=dex-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node *delete_value_Dlinkedlist(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}

struct Node * reverse_Dlinkedlist(struct Node *head){
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct Node * delete_EvenNodes(struct Node *head){
    int i=1;
    struct Node *p = head;
    while(p!=NULL){
        struct Node *q=p->next;
        if(i%2!=0){
            struct Node *temp=q;
            p->next=q->next;
            q=q->next;
            free(temp);
            p=p->next;
            q=q->next;
        }
        
    }
    head=head->next;
    return head;
}

int main(){
    Create_DLinkedList();
    traversal_Dlinkedlist(head);
    int choose;
    printf("\nMenu:\n Choose one of these:\n 1.SEARCH ELEMENT\n 2.INSERT AT POSITION\n 3.DELETE AN ELEMENT\n 4.DISPLAY IN REVERSE\n 5.DISPLAY IN FORWARD\n 6.EXIT\n");
    scanf("%d",&choose);
    switch(choose){
        case 1:{
            int val1;
            printf("Enter the value: ");
            scanf("%d",&val1);
            search_Dlinkedlist(head, val1);
            break;
        }
        case 2:{
            int data2;
            int dex2;
            printf("Enter the value: ");
            scanf("%d",&data2);
            printf("Enter the index: ");
            scanf("%d",&dex2);
            head = insert_index_Dlinkedlist(head, data2, dex2);
            traversal_Dlinkedlist(head);
            break;
        }
        case 3:{
            int value3;
            printf("Enter the value: ");
            scanf("%d",&value3);
            head = delete_value_Dlinkedlist(head, value3);
            traversal_Dlinkedlist(head);
            break;
        }
        case 4:{
            head = reverse_Dlinkedlist(head);
            traversal_Dlinkedlist(head);
            break;
        }
        case 5:{
            traversal_Dlinkedlist(head);
            break;
        }
        case 6:{
            break;
        }
        case 7:{
            head = delete_EvenNodes(head);
            traversal_Dlinkedlist(head);

        }
        default:{
            printf("Enter valid choice");
        }
    }
    return 0;
}