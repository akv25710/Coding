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

Node *findLCA(Node* root, int a, int b){
	if(!root) return NULL;
	if(root->data==a || root->data==b) return root;
	Node *left = findLCA(root->left,a,b);
	Node *right = findLCA(root->right,a,b);
	if(!left && !right) return NULL;
	if(left && right) return root;
	return left?left:right;
}

int findDistanceUtil(Node *root, int a, int level){
	if(!root) return 0;
	if(root->data == a) return level;
	int x = findDistanceUtil(root->left,a,level+1);
	if(x) return x;
	return findDistanceUtil(root->right,a,level+1);	
}

int findDistance(Node *root, int a, int b){
	if(!root) return -1;
	Node *LCA = findLCA(root,a,b);
	if(!LCA) return -1;
	return findDistanceUtil(LCA,a,0)+findDistanceUtil(LCA,b,0);
}


int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
