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

Node *BuildPreorderTree(int pre[],char preLN[],int start,int *index_ptr, int l){
	int index = *index_ptr; // store the current value of index in pre[]
 
    // Base Case: All nodes are constructed
    if (index == l)
        return NULL;
 
    // Allocate memory for this node and increment index for
    // subsequent recursive calls
     Node *temp = newNode ( pre[index] );
    (*index_ptr)++;
 
    // If this is an internal node, construct left and right subtrees and link the subtrees
    if (preLN[index] == 'N')
    {
      temp->left  = BuildPreorderTree(pre, preLN, index_ptr,l);
      temp->right = BuildPreorderTree(pre, preLN, index_ptr,l);
    }
 
    return temp;

}

void Inorder(Node *root){
	if(!root) return;
	Inorder(root->left);
	cout<<root->data<<"	";
	Inorder(root->right);
}

int main() {
      int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int *n =0;
    Node *root = BuildPreorderTree (pre, preLN,&n,4);
 
 
	
	return 0;
}
