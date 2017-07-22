#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
 

Node* newNode(int data)
{
    Node *node = new Node;
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
 
    return(node);
}

int identicalTrees(Node *root1, Node *root2){
	if(!root1 && !root2) return 1;
	if(!root1 || !root2) return 0;
	return root1->data==root2->data && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}

int main()
{
     Node *root1 = newNode(1);
    Node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
 
    if(identicalTrees(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
 
    getchar();
  return 0;
}
