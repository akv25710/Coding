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

int largestBSTutil(Node *root, int *min, int *max, int *size){
	int lmin = INT_MIN, lmax = INT_MAX, lsize = 0, lisBST = 0;
	int rmin = INT_MIN, rmax = INT_MAX, rsize = 0, risBST = 0;
	if(!root){
		*size = 0;
		return 0;
	}
	if(!root->left && !root->right){
		*size = 1;
		*min = root->data;
		*max = root->data;
		return 1;
	}
	if(root->left){
		lisBST = largestBSTutil(root->left,&lmin,&lmax,&lsize);
		lisBST = lisBST && (root->data > lmax);
		*min = lmin;
	}
	else{
		*min = root->data;
		lisBST = 1;
	}
	if(root->right){
		risBST = largestBSTutil(root->right,&rmin,&rmax,&rsize);
		risBST = risBST && (root->data < rmin);
		*max = rmax;
	}
	else{
		*max = root->data;
		risBST = 1;
	}
			
	if(lisBST && risBST){
		*size = 1+rsize+lsize;
		return 1;
	}
	*size = rsize>lsize?rsize:lsize;
	return 0;
}

int largestBST(Node *root){
	int min = INT_MIN;
	int max = INT_MAX;
	int size = 0;
	largestBSTutil(root,&min,&max,&size);
	return size;
}

int main()
{
       
	
   struct Node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
    
        printf("%d",largestBST(root));
 
    return 0;
}
