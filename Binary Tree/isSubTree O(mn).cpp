#include <iostream>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool AreIdentical(Node *root,Node *root1){
	
	if(!root && !root1) return true;
	if(!root || !root1) return false;
	return (root->data == root1->data && AreIdentical(root->left,root1->left) && AreIdentical(root->right,root1->right));	
}

int isSubTree(Node *root1, Node *root2){
	if(!root2) return 1;
	if(!root1) return 0;
	if(AreIdentical(root1,root2))  return 1;
	return isSubTree(root1->left,root2)||isSubTree(root1->right,root2);
}

int main() {
      // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
     Node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    Node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
    cout<<isSubTree(T,S);
	
	return 0;
}
