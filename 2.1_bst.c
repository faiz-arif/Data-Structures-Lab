#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

//creating new node

struct node* set(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

//insertion

struct node* insertion(struct node* newnode,int key){
	if (newnode == NULL){
		return set(key);
	}
	if (key < newnode->data){
		newnode->left = insertion(newnode->left, key);
	}
	else if (key > newnode->data){
		newnode->right = insertion(newnode->right, key);
	}
	return newnode;
}

//display root node

void display(struct node *root){
	if(root==NULL){
	printf("Tree is empty....!");
	}
	else{
	printf("Root node: %d \n",root->data);
	}	
}

//traversal

void preorder(struct node *root){
	if(root!=NULL){
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */

struct node *minValueNode(struct node *node){
	struct node *current = node;
	while (current && current->left != NULL)
	current = current->left;
	return current;
}

//Deletion

struct node *deleteNode(struct node *root, int key){
	if (root == NULL) 
		return root;
	if (key < root->data)
		root->left = deleteNode(root->left, key);
  	else if (key > root->data)
    		root->right = deleteNode(root->right, key);

  	else{
/* 		node has no child
  		if (root->left == NULL and root->right == NULL)
            		return NULL;         	
            	node with only one child or no child */
    		if (root->left == NULL) {
      			struct node *temp = root->right;
      			free(root);
      			return temp;
    		} else if (root->right == NULL) {
      			struct node *temp = root->left;
      			free(root);
      			return temp;
    		}
    	// node with two children: Get the inorder successor (smallest in the right subtree)
   	struct node *temp = minValueNode(root->right);
   	root->data = temp->data;
   	// Delete the inorder successor
   	root->right = deleteNode(root->right, temp->data);
   	}
   	return root;
}

//main function

void main(){

	struct node* root = NULL;
	int choice,data,i,n;
	printf("OPTIONS:\n1.Creation of binary search tree \n2.Insertion of node\n3.Preorder traverse\n4.Inorder traverse\n5.Post order traverse \n6.Dispaly root node\n7.Deletion of node\n0.Exit\n");
	do{
	
		printf("\nEnter your choice :\n");
		scanf("%d",&choice);

		switch(choice){
		
			case 1 : {	
					printf("How many data want to insert :");
					scanf("%d",&n);
					for(i=0;i<n;i++){
						printf("Enter the data :");
				    		scanf("%d",&data);
						root=insertion(root,data);
					}
					break;
				 } 
			case 2 : {
					printf("Enter the data :");
				    	scanf("%d",&data);
					root=insertion(root,data);
					break;
				 }
			case 3 : {
					preorder(root);
					break;
				 }
			case 4 : {
					inorder(root);
					break;
				 }
			case 5 : {
					postorder(root);
					break;
				 }
			case 6 : {
					display(root);
					break;
				 }
			case 7 : {
					printf("Enter the data :");
				    	scanf("%d",&data);
					root = deleteNode(root,data);
					break;
				 }
			case 0 : {
					printf("Exiting....!\n");
					break;
				 }
			default : {
					printf("Wrong input\n");
					break;
				  }
		}
	}while(choice != 0 );
}
