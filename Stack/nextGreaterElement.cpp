#include<iostream>
#include<stack>

using namespace std;

void nextGreaterElement(int ar[], int n){
	stack<int> S;
	for(int i=0;i<n;i++){
		int next = ar[i];
		if(!S.empty()){
			while(!S.empty() && next > S.top()){
				cout<<S.top()<<" --> "<<next<<endl;
				S.pop();
			}
		}
		S.push(next);
	}
	while(!S.empty()){
		cout<<S.top()<<" --> "<<-1<<endl;
		S.pop();
	}
}

int main()
{
    int arr[]= {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreaterElement(arr, n);
    getchar();
    return 0;
}
