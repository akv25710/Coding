#include <iostream>

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
void Inorder(Node *root){
	if(!root) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void increment(Node *root, int diff){
	
	if(root->left) {
	root->left->data = root->left->data + diff;
	increment(root->left,diff);
    }
    else if(root->right){
    	root->right->data = root->right->data + diff;
	increment(root->right,diff);
	}

}

void ConvertChidrenSum(Node *root){
	
	if (!root) return;
	if(!root->left&&!root->right) return;
	
	int left_data=0,right_data=0,diff;
	
	ConvertChidrenSum(root->left);
	ConvertChidrenSum(root->right);
	
		
	if(root->left) left_data = root->left->data;
	if(root->right) right_data = root->right->data;
	
	diff = left_data + right_data - root->data;
	
	if(diff > 0) root->data = root->data + diff;
	if(diff < 0) 	increment(root,-diff);
		
}

int main() {
     Node *root = newNode(51);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    ConvertChidrenSum(root);
    Inorder(root);
	
	return 0;
}
