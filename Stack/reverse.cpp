#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

stack<int> reverse(stack<int> S, stack<int> X){
	if(S.empty()){
		return X;
	}
	X.push(S.top());
	S.pop();
	return reverse(S,X);
}

int main() {
    int i;
	stack<int> s,x;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<"Top of stack before swap : "<<s.top()<<"\n";
	s = reverse(s,x);
	cout<<"Top of stack after swap : "<<s.top()<<"\n";
	return 0;
}
