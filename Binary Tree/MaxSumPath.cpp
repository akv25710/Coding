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

int findMaxSum(int path[],int pathLen, int max){
	int i,current=0;
	for(i=0;i<=pathLen;i++) current += path[i];
	return current>max?current:max;
}

int MaxSumPath(Node *root,int path[],int pathLen){
	if (!root) return 0;
	path[pathLen++] = root->data;
	static int max = INT_MIN;
	if(!root->left && !root->right){
		max = findMaxSum(path,pathLen,max);
	}
	else{
		MaxSumPath(root->left,path,pathLen);
		MaxSumPath(root->right,path,pathLen);
		
	}
	return max;
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    int path[12];
    cout<<MaxSumPath(root,path,0);
	
	return 0;
}
