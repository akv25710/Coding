#include<iostream>
#include<stack>
using namespace std;

struct Tree{
	int data;
	Tree *left;
	Tree *right;
};

void InOrder(Tree *root){
	stack<Tree*> S;
	S.push(root);
	while(root){
		if(S.empty()) return;
		while(root->left){
			root=root->left;
			S.push(root);
		}
		
		root = S.top();S.pop();
		cout<<root->data<<" ";
		
		if(root->right){
			root = root->right;
			S.push(root);
		}
	}
}

Tree* newNode(int data)
{
    Tree *node = new Tree;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

int main()
{
    struct Tree *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    InOrder(root);
 
    return 0;
}
