#include<iostream>
#include<stack>

using namespace std;

int isOperand(char x){
	return (x>='a' && x<='z') || (x>='A' && x<='Z');
}

int precedence(char x){
	switch (x)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char exp[], int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		if(isOperand(exp[i])) cout<<exp[i];
		else if(exp[i]=='(') S.push(exp[i]);
		else if(exp[i]==')') {
			while(!S.empty() && S.top()!='('){
			cout<<S.top();
			S.pop();
			}
			if (!S.empty() && S.top() != '(')
                return -1;              
            else
                S.pop();
		}
		else{
			while(!S.empty() && precedence(S.top())>=precedence(exp[i])){
				cout<<S.top();
				S.pop();
			}
			S.push(exp[i]);
		}
	}
	while(!S.empty()){
		cout<<S.top();
		S.pop();
	}
	return 1;
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    int n = sizeof(exp)/sizeof(exp[0]);
    infixToPostfix(exp,n);
    return 0;
}
