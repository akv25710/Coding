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

void greaterSumTree(Node *root, int *sum){
	if(!root) return;
	greaterSumTree(root->right,sum);
	int data = root->data;
	root->data = *sum;
	*sum += data;
	greaterSumTree(root->left,sum);
}

void printInorder(struct Node *root)
{
    if (root == NULL) return;
 
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
     Node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
 
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);
 	int sum=0;
    greaterSumTree(root,&sum);
 
    cout << "\n\nInorder Traversal of transformed tree\n";
    printInorder(root);
 
    return 0;
}
