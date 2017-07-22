#include<iostream>
#include<stack>

using namespace std;

bool isdigit(char ch){
	return ch>=48 && ch<=57;
}

int evaluatePostfix(char exp[]){
	stack<int> S;
	for(int i=0;exp[i];i++){
		if(isdigit(exp[i]))
			S.push(exp[i]-'0');
		else{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			switch(exp[i]){
				case'+': S.push(a+b);break;
				case'-': S.push(b-a);break;
				case'*': S.push(a*b);break;
				case'/': S.push(b/a);break;
			}
			cout<<S.top()<<endl;
		}
	}
	return S.top();
}
int main()
{
    char exp[] = "231*+9-";
    printf ("Value of %s is %d", exp, evaluatePostfix(exp));
    return 0;
}
