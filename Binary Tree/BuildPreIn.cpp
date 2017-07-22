#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
	char data;
	Node *left;
	Node *right;
};

Node* newNode(char data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int Search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

Node *BuildPreIn(char pre[], char in[], int start, int end){
	static int pIndex = 0;
	if(start > end) return NULL;
	Node *temp = newNode(pre[pIndex++]);
	if(start == end) return temp;
	int index = Search(in, start, end, temp->data);
	temp->left = BuildPreIn(pre,in,start,index-1);
	temp->right = BuildPreIn(pre,in,index+1,end);
	return temp;
}

void printInorder(Node* node){
	if(!node) return;
	printInorder(node->left);
	cout<<node->data;
	printInorder(node->right);
}
 

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  Node *root = BuildPreIn(pre, in, 0, len - 1);
 
  
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
}


