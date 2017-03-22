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

void PrintSpiral(Node *root){
	if(!root) return;
	stack <Node *> s1;
	stack <Node *> s2;
	Node *temp;
	s1.push(root);
	
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			temp = s1.top();
			s1.pop();
			cout<<temp->data;
			if(temp->right) s2.push(temp->right);
			if(temp->left)  s2.push(temp->left);
		}
		
		while(!s2.empty()){
			temp = s2.top();
			s2.pop();
			cout<<temp->data;
			if(temp->left) s1.push(temp->left);
			if(temp->right) s1.push(temp->right);
		}
	}
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    PrintSpiral(root); 
	
	return 0;
}
