#include <iostream>
#include <stack>
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
void InorederWithoutRecursion(Node *root){
	stack <Node *> S;
	while(1){
		while(root){
			S.push(root);
			root = root->left;
		}
		if(S.empty()) break;
		root = S.top();
		S.pop();
		cout<<root->data<<" ";
		root = root->right;
	}
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    
    InorederWithoutRecursion(root);
 
 
	
	return 0;
}
