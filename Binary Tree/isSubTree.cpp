#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

Node *Search(Node *root, int data){
	if(!root) return NULL;
	if(data == root->data){
		return root;
	}
	Node *next = Search(root->left, data);
	if(next->data == data) return next;
	return Search(root->right, data);
}

int isIdentical(Node *root1, Node* root2){
	if(!root1 && !root2) return 1;
	if(!root1 || !root2) return 0;
	return root1->data==root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right, root2->right);
}

int isSubTree(Node *root1, Node *root2){
	Node *temp = Search(root1,root2->data);
	return isIdentical(temp,root2);
}

int main()
{
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
 
 
    if (isSubTree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
 
    getchar();
    return 0;
}

