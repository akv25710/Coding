#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int Height(Node *root){
	if(!root) return 0;
	return 1+max(Height(root->left), Height(root->right));
}

int main()
{
    Node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    printf("Hight of tree is %d", Height(root));
   
    getchar();
    return 0;
}
