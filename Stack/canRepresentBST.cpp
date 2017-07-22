#include<iostream>
#include<stack>

using namespace std;

bool canRepresentBST(int ar[], int n){
	stack<int> S;
	int root = INT_MIN;
	for(int i=0;i<n;i++){
		if(ar[i]<root) return false;
		while(!S.empty() && ar[i]>S.top()){
			root = S.top();
			S.pop();
		}
		S.push(ar[i]);
	} 
	return true;
}

int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true\n":
                              cout << "false\n";
 
    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true\n":
                              cout << "false\n";
 
    return 0;
}
