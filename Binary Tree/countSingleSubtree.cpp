#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int countSingle(Node *root, int *count){
	if(!root) return 1;
	if(!root->left && !root->right){
		*count+=1;
		return 1;
	}
	int l = countSingle(root->left,count);
	int r = countSingle(root->right,count);
	int data = root->left? root->left->data : root->right->data;
	if(l&&r&&root->data==data){
		*count+=1;
		return 1;
	}
	return 0;
}

int main()
{
    /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
     4    4      5 */
    Node* root        = newNode(5);
    root->left        = newNode(4);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);
    int count = 0;
    countSingle(root,&count);
 
    cout << "Count of Single Valued Subtrees is "<< count;
    return 0;
}
