#include<iostream>

using namespace std;

int Search(int ar[], int data, int n){
	for(int i=0;i<n;i++)
		if(ar[i]==data) return i;
	return -1;
}

void printPostorder(int in[], int pre[], int n){
	int root = Search(in,pre[0],n);
	if(root!=0) printPostorder(in,pre+1,root);
	if(root!=n-1) printPostorder(in+root+1, pre+root+1,n-root-1);
	cout<<pre[0]<<" ";
}

int main()
{
   int in[] = {4, 2, 5, 1, 3, 6};
   int pre[] =  {1, 2, 4, 5, 3, 6};
   int n = sizeof(in)/sizeof(in[0]);
   cout << "Postorder traversal " << endl;
   printPostorder(in, pre, n);
   return 0;
}
