#include<stdio.h>
#include<stdlib.h>
 struct Node{
    int data;
    struct Node *next;
}*new_node, *temp, *head, *root;
struct Node *creatNode(int data){
    root =  (struct Node*)malloc(sizeof(struct node*));
    root->data = data;
    root->next = NULL;
}
void enqueue(int data){
    new_node = creatNode(data);
    if(head == NULL){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void dequeue(){
    if(head == NULL){
        printf("Queue is empty.");
    }
    temp = head;
    head = head->next;
    free(temp);
}
void display(){
    if(head == NULL){
        printf("Queue Is Empty.\n");
    }
    else{
        temp = head;
        while(temp != NULL){
            printf("--> %d\t",temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    int choice,data;
    do{
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    while(choice != 4);
    return 0;
}
