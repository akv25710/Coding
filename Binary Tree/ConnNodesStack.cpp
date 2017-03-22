#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
    Node *nextRight;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    return temp;
}

void ConnectNodes(Node *root){
    Node *temp;
	queue <Node *> Q;
	stack <Node *> S;
	Q.push(root);
	Q.push(NULL);
	
	while(!Q.empty()){
		temp = Q.front();Q.pop();
		S.push(temp);
		if(temp == NULL)
		    if(!Q.empty()) Q.push(NULL);
			
		else{ 
		    cout<<temp->data; 
		    if(temp->left) Q.push(temp->left);
			if(temp->right) Q.push(temp->right);
 		}
	}
    Node *preTemp = NULL;
	while(!S.empty()){
		temp = S.top();S.pop();
		if(temp != NULL)
			temp->nextRight = preTemp;
	    preTemp = temp;
	}	 
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    
    ConnectNodes(root);
 
  // Let us check the values of nextRight pointers
    cout<<root->left->right->nextRight->data;
 
	return 0;
}
