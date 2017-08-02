#include<iostream>
#include<stack>

using namespace std;

void nextGreaterElement(int ar[], int n){
	stack<int> S;
	S.push(ar[0]);
	for(int i=1;i<n;i++){
		int next = ar[i];
		if(!S.empty()){
			while(!S.empty() && S.top()<next){
				cout<<S.top()<<"-->"<<next<<endl;
				S.pop();
			}
		S.push(next);
		}
	}
	while(!S.empty()){
		cout<<S.top()<<"-->"<<-1<<endl;
		S.pop();
	}
	return;
} 

int main()
{
    int arr[]= {4,5,2,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreaterElement(arr, n);
    getchar();
    return 0;
}
