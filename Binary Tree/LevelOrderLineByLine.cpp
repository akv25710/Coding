#include<iostream>
#include<queue>
using namespace std;

struct Tree{
	int data;
	Tree *left;
	Tree *right;
};

void LevelOrder(Tree *root){
	queue<Tree*> Q;
	Q.push(root);
	Tree *front = root;
	int nodecount=0;
	while(1){
		int nodecount = Q.size();
		if(nodecount==0) return;
		while(nodecount){
			front = Q.front();
			Q.pop();
			cout<<front->data<<" ";
			if(front->left) Q.push(front->left);
			if(front->right) Q.push(front->right);
			nodecount--;
		}
		cout<<endl;
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
    LevelOrder(root);
 
    return 0;
}
