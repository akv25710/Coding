#include<iostream>
#include<stack>
using namespace std;

int countMinReversals(string exp){
	int n = exp.length();
	if(n%2!=0) return -1;
	stack<char> S;
	int count = 0;
	for(int i=0;i<n;i++){
		if(exp[i]=='{') S.push(exp[i]);
		else{
			if(!S.empty() && S.top()=='{')
				S.pop();
			else S.push(exp[i]);
		}
	}
	while(!S.empty()){
		S.pop();
		count++;
	}
	return count/2;
}


int main()
{
   string expr = "{{{{}}";
   cout << countMinReversals(expr);
   return 0;
}
