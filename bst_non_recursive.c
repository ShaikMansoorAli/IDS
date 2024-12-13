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
void PreorderTraversal(struct Node* root){
    if(root == NULL){
        printf("Tree is Empty.");
        return;
    }
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while(top >= 0){
        struct Node* curr = stack[top--];
        printf("%d", curr->data);
        if(curr->right != NULL){
            stack[++top] = curr->right;
        }
        if(curr->left != NULL){
            stack[++top] = curr->left;
        }
    }
}