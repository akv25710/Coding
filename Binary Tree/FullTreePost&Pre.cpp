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

int FindIndex(int ar[],int start,int end,int num){
	for(int i=start;i<=end;i++)
	    if(ar[i]==num) return i;
	return -1;	 
}

Node *FullTreePostPre(int pre[],int post[],int start,int end){
	if (start > end) return NULL;
	static int preIndex = 0;
	Node *root = newNode(pre[preIndex++]);
	
	if(start == end) return root;
	int myIndex = FindIndex(post,start,end,pre[preIndex]);
	
	root->left = FullTreePostPre(pre,post,start,myIndex);
	root->right = FullTreePostPre(pre,post,myIndex+1,end-1) ;
	
	return root;
}

int main() {
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    
    
    Node *root = FullTreePostPre(pre,post,0,8);
    Inorder(root);
 
	
	return 0;
}
