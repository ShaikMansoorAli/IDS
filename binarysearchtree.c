#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *create(int val ) {
	struct Node *n=(struct Node *)malloc(sizeof(struct Node));
	n->data=val;
	n->left=NULL;
	n->right=NULL;
	return n;
}
struct Node *insert(struct Node *root,int data) {
	if(root==NULL) {
		return create(data);
	}


	if(data<root->data ){
		root->left=insert(root->left,data);
	}
	else if(data>root->data ){
		root->right=insert(root->right,data);
	}
	return root;
}
struct Node*search(struct Node *root,int key) {
	if(root==NULL || root->data==key ) {
		return root;
	}
	if(key<root->data) {
		return search(root->left,key);
		if(key==root->data) {
			printf("found : ");
		}
	}
	else{
		return search(root->right,key);
		if(key==root->data) {
			printf("found : ");
		}
	
	}
	
}

void preorder(struct Node *root) {
	if(root!=NULL){
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
		
	}

	
}
	
void inorder(struct Node *root) {
	if(root!=NULL){
		
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	
	}
	
	
}
	

void postorder(struct Node *root) {
	if(root!=NULL){
		
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	
	}

	
}
int main() {
    int choice, value;
    struct Node *root = NULL;
    struct Node *result = NULL;

    do {
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result != NULL) {
                    printf("Node with value %d found in the tree.\n", value);
                } else {
                    printf("Node with value %d not found in the tree.\n", value);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}