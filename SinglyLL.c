#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
}*new_node, *temp, *head, *temp1;
struct Node*  createNode(int value){
	struct Node* new_node = ( struct Node*)malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;	
}
void insertAtBeg(int data){
    new_node = createNode(data);
    if(head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
}
void insertAtEnd(int data){
    new_node = createNode(data);
    if(head == NULL){
        new_node = head;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void insertAtPos(int data, int pos){
    new_node = createNode(data);
    int i;
    if (pos == 0){
        insertAtBeg(data);
    }
    else{
        temp = head;
        for(i = 1; i < pos; i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void delAtBeg(){
    if(head == NULL){
        printf("List Is Empty.");
    }
    else if(head->next == NULL){
        printf("%d is Deleted.", head->data);
        free(head);
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
}
void delAtEnd(){
    if(head == NULL){
        printf("List Is Empty.");
    }
    else{
        temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

}
void delAtPos(int pos){
    int i;
    temp = head;
    if (pos == 0){
        delAtBeg();
    }
    else{
        for(i = 1; i<pos; i++){
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }

}
void displayList(){
    if(head == NULL){
        printf("List Is Empty.");
    }
    else{
        temp = head;
        while(temp != NULL){
            printf("%d ->", temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    struct Node* head = NULL;
    int value, position, choice;
do{
		printf("\n1.Insert at Begining.\n");
		printf("2.Insert at End.\n");
		printf("3.Insert at position.\n");
		printf("4.Delete at Begining.\n");
		printf("5.Delete at End.\n");
		printf("6.Delete at Position.\n");
		printf("7.Display List.\n");
		printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
        		printf("Enter data to insert: ");
				scanf("%d", &value);
				insertAtBeg(value);
				break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
				printf("Enter data to insert: ");
				scanf("%d", &value);
				printf("Enter position to Insert: ");
				scanf("%d", &position);
				insertAtPos(value, position);
				break;
			case 4:
				displayList();
				delAtBeg();
				printf("\nList after deletion:\n");
				displayList();
				break;
			case 5:
				displayList();
				delAtEnd();
				printf("List after deletion:\n");
				displayList();
				break;
			case 6:
				displayList();
				printf("\nEnter Position to delete: ");
				scanf("%d", &position);
				delAtPos(position);
				printf("List after deletion:\n");
				displayList();
				break;
			case 7:
				printf("Linked List:\n");
				displayList();
				break;
			default:
				printf("Invalid Choice.\n");
        }

}
while(choice != 7);
return 0;
}