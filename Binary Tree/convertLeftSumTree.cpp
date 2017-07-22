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

int convertLeftSumTree(Node *root){
	if(!root) return 0;
	int left = convertLeftSumTree(root->left);
	int right = convertLeftSumTree(root->right);
	root->data += left;
	return root->data + right;
}

void inorder(Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}


int main()
{
    /* Let us construct below tree
                1
               / \
              2   3
             / \   \
            4   5   6    */
    Node *root  = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);
 
    convertLeftSumTree(root);
 
    cout << "Inorder traversal of the modified tree is \n";
    inorder(root);
    return 0;
}
