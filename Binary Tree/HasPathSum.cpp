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

bool HasPathSum(Node *root, int sum){
	if(!root) return(sum==0);
	int remainingSum = sum - root->data;
	
	if(remainingSum==0&&!root->left&&!root->right) return 1;
	bool ans=0;
	if(root->left) ans = ans||HasPathSum(root->left,remainingSum);
	if(root->right) ans = ans||HasPathSum(root->right,remainingSum);
	
	return ans;
}
int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    cout<<HasPathSum(root,10);
	
	return 0;
}
