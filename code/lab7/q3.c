#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void create_linkedlist(struct Node *head){
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
    }
}

void traversal_linkedlist(struct Node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

struct Node * inserting_start_position(struct Node *head, int data){
    struct Node p=(struct Node)malloc(sizeof(struct Node));
    p->next=head;
    p->data=data;
    return p;
}

struct Node * insert_in_btw(struct Node*head, int data, int dex){
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

struct Node * insert_at_end(struct Node *head, int data){
    struct Node ptr=(struct Node)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node * delete_first(struct Node *head){
    struct Node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

struct Node * delete_at_index(struct Node*head, int dex){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<dex-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node * delete_last(struct Node*head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node * delete_value(struct Node*head, int value){
    struct Node *p=head;
    struct Node *q=head->next;
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

void search_linkedlist(struct Node *head, int value){
    struct Node * temp = head;
    int i =1;
    int j = 0;
    while(temp!=NULL){
        if(temp->data==value){
            printf("\nElement found at %d",i);
            j++;
        }
        i++;
        temp=temp->next;
    }
    if (j == 0) {printf("\nNo element Found");}
}

void sorting_linkedlist(struct Node *head){
    struct Node *ptr; 
    struct Node *cp;
    int temp; 
    ptr=head;
    while(ptr->next!=NULL){
        cp=ptr->next;
        while(cp!=NULL){
            if(ptr->data>cp->data){
                temp=ptr->data;
                ptr->data=cp->data;
                cp->data=temp;
            }
            cp=cp->next;
        }
        ptr=ptr->next;
    }
}

struct Node * reverse_linkedlist(struct Node *head){
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

void printingevennode(struct Node *head){
    struct Node *temp = head;
    int count=0;
    while(temp != NULL){
        if(count%2==0){
            printf("%d ",temp->data);
        }
        temp = temp->next;
        count++;
    }
}

int main(){
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    printf("Creating a linked list: \n");
    create_linkedlist(head);
    printf("Traversal of linked list: ");
    traversal_linkedlist(head);
    int choice;
    printf("\nMENU:\n 1.INSERT AT FRIST\n 2.INSERT AT INDEX\n 3.INSERT AT END\n 4.DELETE AT FIRST\n 5.DELETE AT INDEX\n 6.DELETE AT LAST\n 7.DELETE AT VALUE\n 8.SEARCH ELEMENT\n 9.SORT LINKED LIST\n 10.REVERSE LIST\n 11.PRINTING EVEN NODES\n Enter your choice:");
    scanf("%d", &choice);
    switch(choice){
        case 1:{
            int data1;
            printf("Enter the data need: ");
            scanf("%d",&data1);
            head = inserting_start_position(head, data1);
            traversal_linkedlist(head);
            break;
        }
        case 2:{
            int data2;
            printf("Enter the data need: ");
            scanf("%d",&data2);
            int dex2;
            printf("Enter the index need: ");
            scanf("%d",&dex2);
            head = insert_in_btw(head, data2, dex2);
            traversal_linkedlist(head);
            break;
        }
        case 3:{
            int data3;
            printf("Enter the data need: ");
            scanf("%d",&data3);
            head = insert_at_end(head, data3);
            traversal_linkedlist(head);
            break;
        }
        case 4:{
            head = delete_first(head);
            traversal_linkedlist(head);
            break;
        }
        case 5:{
            int dex5;
            printf("Enter the index need: ");
            scanf("%d",&dex5);
            head = delete_at_index(head, dex5);
            traversal_linkedlist(head);
            break;
        }
        case 6:{
            head = delete_last(head);
            traversal_linkedlist(head);
        }
        case 7:{
            int value;
            printf("Enter the value to delete: ");
            scanf("%d",&value);
            head = delete_value(head, value);
            traversal_linkedlist(head);
            break;
        }
        case 8:{
            int value8;
            printf("Enter the value to search: ");
            scanf("%d",&value8);
            search_linkedlist(head, value8);
            break;
        }
        case 9:{
            sorting_linkedlist(head);
            traversal_linkedlist(head);
            break;
        }
        case 10:{
            head = reverse_linkedlist(head);
            traversal_linkedlist(head);
            break;
        }
        case 11:{
            printingevennode(head);
        }
        default :{break;}
    }
    return 0;
}