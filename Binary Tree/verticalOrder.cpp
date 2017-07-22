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

void findMinMax(Node *root, int *min, int *max, int hd){
	if(!root) return;
	if(hd < *min) *min = hd;
	if(hd > *max) *max = hd;
	findMinMax(root->left,min,max,hd-1);
	findMinMax(root->right,min,max,hd+1);
}

void printVeticalLine(Node *root, int d, int hd){
	if(!root) return;
	if(hd==d) cout<<root->data<<" ";
	printVeticalLine(root->left,d,hd-1);
	printVeticalLine(root->right,d,hd+1);
}

void verticalOrder(Node *root){
	if(!root) return;
	int min=0,max=0;
	findMinMax(root,&min,&max,0);
	for(int i=min;i<=max;i++){
		printVeticalLine(root,i,0);
		cout<<endl;
	}
}

int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
 
    cout << "Vertical order traversal is \n";
    verticalOrder(root);
 
    return 0;
}
