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

void createNode(int parent[], int i, Node *created[], Node **root){
	if(!created[i]) return;
	created[i] = newNode(i);
	if(parent[i]==-1){
		*root = created[i];
		return;
	}
	if(!created[parent[i]])
		createNode(parent,parent[i],created,root);
	Node *p = created[parent[i]];
	if(!p->left)
		p->left = created[i];
	else
		p->right = created[i];
}

Node *parentArray(int parent[], int n){
	Node *root = NULL;
	Node *created[n];
	for(int i=0;i<n;i++) created[i]=NULL;
	for(int i=0;i<n;i++) createNode(parent,i,created,&root);
	cout<<root->data;
	return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
 
// Driver method
int main()
{
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *root = parentArray(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    return 0;
}
