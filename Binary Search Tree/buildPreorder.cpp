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

Node *buildPreorderUtil(int pre[], int n, int min, int max){
	static int preIndex = 0;
	if(preIndex > n-1) return NULL;
	Node *root = NULL;
	int key = pre[preIndex];
	if(key>min && key<max){	
	root = newNode(key);
	preIndex++;
	root->left = buildPreorderUtil(pre,n,min,key);
	root->right = buildPreorderUtil(pre,n,key,max);
	}
	return root;	
}

Node *buildPreorder(int pre[], int n){
	int min = INT_MIN, max = INT_MAX;
	return buildPreorderUtil(pre,n,min,max);
}

void printInorder (Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = buildPreorder(pre, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}
