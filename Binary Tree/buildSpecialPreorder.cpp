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

void printInorder (Node* node)
{
    if (node == NULL) return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

Node *buildSpecialPreorder(int pre[], char LN[], int *start, int n){
	int index = *start;
	if(index == n) return NULL;
	Node *temp = newNode(pre[index]);
	(*start)++;
	if(LN[index]=='N'){
		temp->left = buildSpecialPreorder(pre,LN,start,n);
		temp->right = buildSpecialPreorder(pre,LN,start,n);
	}
	return temp;
}

int main()
{
    Node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
 	int start = 0;
    // construct the above tree
    root = buildSpecialPreorder (pre, preLN, &start, n);
 
    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);
 
    return 0;
}
 

