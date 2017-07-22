#include<iostream>
#include<stack>
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

void printSpiral(Node *root){
	stack<Node *> S1;
	stack<Node *> S2;
	S1.push(root);
	while(!S1.empty() || !S2.empty()){
		while(!S1.empty()){
			Node *temp = S1.top(); S1.pop();
			cout<<temp->data;
			if(temp->right) S2.push(temp->right);
			if(temp->left) S2.push(temp->left);
		}
		while(!S2.empty()){
			Node *temp = S2.top(); S2.pop();
			cout<<temp->data;
			if(temp->left) S1.push(temp->left);
			if(temp->right) S1.push(temp->right);
		}
	}
}

int main()
{
    Node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    printSpiral(root);
    return 0;
}
