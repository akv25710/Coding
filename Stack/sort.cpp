#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> S){
	if(S.empty()) return;
	cout<<S.top()<<" ";
	S.pop();
	print(S);
}

void Insert(stack<int> S, int x){
	if(S.empty()){
		S.push(x);
		return;
	}
	if( x > S.top() )
	      {
	           int t=S.top();
	           S.pop();
	           
	           Insert(S, x);
	           S.push( t );
	           
	           }
	           
	     else
	      {
	           S.push( x );
	           return;
	           
	           }
}



void sort(stack<int> S){
	if(S.empty()) return;
	int x = S.top();
	S.pop();
	sort(S);
	Insert(S,x);
}

int main(void)
{
    stack<int> S;
    S.push(4);
 	S.push(5);
 	S.push(2);
 	S.push(25);
  	print(S);
  	cout<<endl;
  	sort(S);
  	print(S);
 
    return 0;
}
