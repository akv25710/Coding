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

int ClosestDown(Node *root){
	if(!root) return INT_MAX;
	if(!root->left && !root->right) return 0;
	return 1+min(ClosestDown(root->left), ClosestDown(root->right));
}

int Closest(Node *root, Node *ancestors[], char k, int index){
	if(!root) return INT_MAX;
	if(root->data == k){
		int res = ClosestDown(root);
		for(int i=index-1;i>=0;i--)
			res = min(res,index-i+ClosestDown(ancestors[i]));
		return res;
	}
	ancestors[index] = root;
	return min(Closest(root->left,ancestors,k,index+1), Closest(root->right,ancestors,k,index+1));
}

int findClosestLeaf(Node *root, char k){
	Node *ancestors[100];
	return Closest(root,ancestors,k,0);
}

int main()
{
    // Let us construct the BST shown in the above figure
    struct Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
 
    char k = 'H';
    cout << "Distace of the closest key from " << k << " is "
         << findClosestLeaf(root, k) << endl;
    k = 'C';
    cout << "Distace of the closest key from " << k << " is "
         << findClosestLeaf(root, k) << endl;
    k = 'E';
    cout << "Distace of the closest key from " << k << " is "
         << findClosestLeaf(root, k) << endl;
    k = 'B';
    cout << "Distace of the closest key from " << k << " is "
         << findClosestLeaf(root, k) << endl;
 
    return 0;
}
