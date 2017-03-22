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
	cout<<root->data<<"	";
	Inorder(root->right);
}

findMaxIndex(int ar[],int start,int end){
	int max = INT_MIN,index;
	for(int i=start;i<=end;i++){
		if(ar[i]>max) index =i;
	}
	return index;
}

Node * BuildInorderTree(int inorder[],int start,int end){
    if(start >end) return NULL;
	int maxIndex = findMaxIndex(inorder,start,end);
	Node *root = newNode(inorder[maxIndex]);
	if(start == end) return root;
	root->left = BuildInorderTree(inorder,start,maxIndex-1);
	root->right = BuildInorderTree(inorder,maxIndex+1,end);
	return root;	
}

int main() {
	int inorder [] = {1,5,10,40,30,15,28,20};
	Node *root = BuildInorderTree(inorder,0,7);
	Inorder(root);
    
 
	
	return 0;
}
