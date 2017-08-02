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

Node *sortedArray2BST(int ar[], int start, int end){
	if(start>end) return NULL;
	int mid = (start + end)/2;
	Node *root = newNode(ar[mid]);
	root->left = sortedArray2BST(ar,start,mid-1);
	root->right = sortedArray2BST(ar,mid+1,end);
	return root;
}

void Inorder(Node* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
	cout<<node->data<<" ";
    Inorder(node->right);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    Node *root = sortedArray2BST(arr, 0, n-1);
    printf("n Inorder Traversal of constructed BST ");
    Inorder(root);
 
    return 0;
}
