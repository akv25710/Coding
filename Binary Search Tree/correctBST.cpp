#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *root = new Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node* insert(Node* root, int key)
{
    if (root == NULL)
       return newNode(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}

void correctBSTutil(Node *root, Node **first, Node **middle, Node **last, Node **prev){
	if(!root) return;
	correctBSTutil(root->left, first, middle, last, prev);
	if(*prev && (*prev)->data > root->data){
		if(!*first){
			*first = *prev;
			*middle = root; 
		}
		else
			*last = root;
	}
	*prev = root;
	correctBSTutil(root->right, first, middle, last, prev);
}

void correctBST(Node *root){
	Node *first = NULL, *middle = NULL, *last = NULL, *prev=NULL;
	correctBSTutil(root,&first,&middle,&last,&prev);
	if(first && last) swap(first->data, last->data);
	else if(first && middle) swap(first->data, middle->data);	 
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
/* Driver program to test above functions*/
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    Node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
 
    printf("Inorder Traversal of the original tree \n");
    printInorder(root);
 
    correctBST(root);
 
    printf("\nInorder Traversal of the fixed tree \n");
    printInorder(root);
 
    return 0;
}
