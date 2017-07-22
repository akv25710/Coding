#include<iostream>
#include<stack>

using namespace std;

int maxLength(string exp){
	int n = exp.length();
	int result=0;
	stack<int> S;
	S.push(-1);
	for(int i=0;i<n;i++){
		result=0;
		if(exp[i]=='(') S.push(i);
		else{
			S.pop();
			if (!S.empty())
				result = max(result, i-S.top());
				
			else S.push(i);
		}

		
	}
	return result;
	
}

int main()
{
    string str = "((()()";
    cout << maxLength(str) << endl;
 
    str = "(()(()";
    cout << maxLength(str) << endl ;
 
    return 0;
}

