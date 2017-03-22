#include <iostream>
#include <queue>

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

int MaximumWidth(Node *root){
	if (!root) return -1;
	queue <Node *> Q;
	Q.push(root);
	Q.push(NULL);
	int count=0,maxCount=0,level=1,maxLevel;
	while(!Q.empty()){
		Node *temp = Q.front();Q.pop();
		if(temp == NULL){
			if(count > maxCount) maxLevel = level;
			count = 0;
			level++;
			if(!Q.empty()) Q.push(NULL);
		}
		else {
		   if(temp->left){
		    Q.push(temp->left); 
			count++;	
		    } 
		   if(temp->right){
			Q.push(temp->right);
			count++;	
		    }
		   
    	}
    	
	}
	return maxLevel;
} 

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    int a = MaximumWidth(root);
    cout<<a;
	
	return 0;
}
