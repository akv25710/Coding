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

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

void findPreSuc(Node *root, Node **pre, Node **succ, int data){
	if(!root) return;
	if(root->data == data){
		if(root->left){
			Node *temp = root->left;
			while(temp->right) temp = temp->right;
			*pre = temp;
		}
		if(root->right){
			Node *temp = root->right;
			while(temp->left) temp = temp->left;
			*succ = temp;
		}
	}
	else if (root->data < data){
		*pre = root;
		findPreSuc(root->right,pre,succ,data);		
	}
	else{
		*succ = root;
		findPreSuc(root->left,pre,succ,data);			
	}
	
}
 
// Driver program to test above function
int main()
{
    int key = 65;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    Node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, &pre, &suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor";
    return 0;
}
