#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *root = new Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node* insert(Node* root, int key)
{
    if (root == NULL)
       return newNode(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
 
// Utility function to traverse the binary tree after conversion
void inorderTraversal(Node* root,int ar[],int *i)
{
    if (root)
    {
        inorderTraversal( root->left,ar,i);
        ar[*i] = root->data;
        *i += 1;
        inorderTraversal( root->right,ar,i );
    }
}

int isTripletPresent(Node *root){
	int ar[23];
	int n = 0;
	inorderTraversal(root,ar,&n);
	int i,j,k;
	for(i=0;i<n;i++){
		j=i+1;k=n-1;
		while(j<k){
			if(ar[i]+ar[j]+ar[k]==0) return 1;
			else if(ar[i]+ar[j]+ar[k] < 0) j++;
			else k++;
		}
	}
	return 0;
}

int main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
    if (isTripletPresent(root))
        printf("Present");
    else
        printf("Not Present");
    return 0;
}
 
