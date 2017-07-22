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

Node *buildPrePost(int pre[], int post[], int start, int end, int n){
	static int preIndex = 0;
	 if(preIndex >= n || start > end) return NULL;
	Node *root = newNode(pre[preIndex++]);
	if(start == end ) return root;
	int i = 0;
	for(i=start;i<=end;i++)
		if(pre[preIndex]==post[i]) break;
	if(i<n){
		root->left = buildPrePost(pre,post,start,i,n);
		root->right = buildPrePost(pre,post,i+1,end,n);
	}
	return root;
}
void printInorder (Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printInorder(node->left);
    printInorder(node->right);
}
 
// Driver program to test above functions
int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = buildPrePost(pre, post, 0, size-1, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}
