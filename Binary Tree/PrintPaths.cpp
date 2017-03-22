#include <iostream>
#include<stdlib.h>

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

void PrintPaths(Node *root,int path[],int pathLen){
	if(!root) return;
	path[pathLen++] = root->data;
	
	if(!root->left && !root->right){
		for(int i=0;i<pathLen;i++)
		      cout<<path[i]<<" ";
		cout<<endl;      
	}
	else{
		PrintPaths(root->left,path,pathLen);
		PrintPaths(root->right,path,pathLen);
		
	}
}
int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    int ar[10];
    PrintPaths(root,ar,0);
	
	return 0;
}
