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

int Search(int ar[],int start, int end, int value){
	for(int i=start;i<=end;i++)
		if(ar[start]==value) return i;
	return -1;
}

int *extract(int in[], int level[],  int m,int n){
	int *newLevel = new int[m],j=0;
	for(int i=0;i<n;i++)
		if(Search(in,0,m-1,level[i]!=-1))
			newLevel[j++] = level[i];
	return newLevel;
}

Node *buildTreeInLevel(int in[], int level[], int start, int end, int n){
	if(start > end) return NULL;
	Node *root = newNode(level[0]);
	int index = Search(in,start,end,level[0]);
	cout<<index;
	int *left = extract(in,level,index,n);
	int *right = extract(in+index+1,level,n-index-1,n);
	root->left = buildTreeInLevel(in,left,start,index-1,n);
	root->right = buildTreeInLevel(in,right,index+1,end,n);
	delete [] left;
	delete [] right;
	return root;
}

void printInorder(Node* node)
{
    if (node == NULL)
       return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
 
/* Driver program to test above functions */
int main()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    Node *root = buildTreeInLevel(in, level, 0, n - 1, n);
 
    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
 
    return 0;
}

