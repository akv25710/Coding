#include<iostream>
#include<stack>

using namespace std;

void nextGreaterElement(int ar[], int n){
	stack<int> S;
	S.push(ar[0]);
	int element, next;
	for(int i=1;i<n;i++){
		next = ar[i];
		if(!S.empty()){
			element = S.top();
			while(element < next){
				cout<<element<<"-->"<<next<<endl;
				if(!S.empty()) break;
				element = S.top();
			}
			if(element > next) S.push(next);
			S.pop();
		}
		S.push(next);
	}
	while(!S.empty()){
		element = S.top();
		next = -1;
		cout<<element<<"-->"<<next<<endl;
		S.pop();
	}
	return;
} 

int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreaterElement(arr, n);
    getchar();
    return 0;
}
