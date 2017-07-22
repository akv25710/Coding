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

int max (int arr[], int strt, int end)
{
    int i, max = arr[strt], maxind = strt;
    for(i = strt+1; i <= end; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}


Node *buildSpecialInorder(int inorder[], int start, int end){
	if(start>end) return NULL;
	int index = max(inorder,start,end);
	Node *temp = newNode(inorder[index]);
//	if(start==end) return temp;
	temp->left = buildSpecialInorder(inorder,start,index-1);
	temp->right = buildSpecialInorder(inorder,index+1,end);
	return temp;
}

void printInorder (Node* node)
{
    if (node == NULL) return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}
 
int main()
{
   /* Assume that inorder traversal of following tree is given
         40
       /   \
      10     30
     /         \
    5          28 */
 
    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    Node *root = buildSpecialInorder(inorder, 0, len - 1);
 
    /* Let us test the built tree by printing Insorder traversal */
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}
