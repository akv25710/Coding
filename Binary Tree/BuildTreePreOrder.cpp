#include <iostream>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
};

int Search(int ar[],int start, int end,int data){
	for(int i=start;i<=end;i++){
		if(ar[i] == data)  
			return i;
	}
			
}

Node *BuildTree(int inOrder[], int preOrder[], int inOrderStart, int inOrderEnd){
	static int preOrderIndex = 0;
	
	if(inOrderStart > inOrderEnd) 
			return NULL;
	Node *root = new Node();
	
	root->data = preOrder[preOrderIndex++];
	if(inOrderStart == inOrderEnd)
	{
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	
	int myIndex = Search(inOrder,inOrderStart,inOrderEnd,root->data);
	
	root->left = BuildTree(inOrder,preOrder,inOrderStart,myIndex-1);
	root->right = BuildTree(inOrder,preOrder,myIndex+1,inOrderEnd);
	
	return root;
}

void Inorder(Node *root){
	if(!root) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right); 
}


int main() {
	int inOrder[] ={4,2,5,1,3,6};
	int preOrder[] = {1,2,4,5,3,6};
	
	Node *root = BuildTree(inOrder,preOrder,0,5);
	
	Inorder(root);
	return 0;
}
