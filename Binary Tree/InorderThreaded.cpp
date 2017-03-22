#include <iostream>
using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
    bool rightThread;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* leftMost(struct Node *n)
{
    if (n == NULL)
       return NULL;
 
    while (n->left != NULL)
        n = n->left;
 
    return n;
}
void InorderThreaded(Node * root){
	Node *current = leftMost(root);
	while(current){
		cout<<current->data;
		if(current->rightThread)
			current = current->right;
		else
			current = leftMost(current->right);
		
	}
	
}
int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    InorderThreaded(root);
	
	return 0;
}
