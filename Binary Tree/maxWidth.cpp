#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

int maxWidth(Node *root){
	if(!root) return -1;
	queue<Node *> Q;
	Q.push(root);
	int result = 0;
	while(!Q.empty()){
		int count = Q.size();
		result = max(result,count);
		while(count--){
			Node *temp = Q.front();
			Q.pop();
			if(temp->left) Q.push(temp->left);
			if(temp->right) Q.push(temp->right);
		}
	}
	return result;
}

Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}


int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);
 
    /*   Constructed Binary tree is:
                 1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7    */
    cout << "Maximum width is "
         << maxWidth(root) << endl;
    return 0;
}
