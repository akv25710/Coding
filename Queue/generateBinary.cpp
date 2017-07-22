#include<iostream>
#include<queue>

using namespace std;

void generateBinary(int n){
	queue<string> Q;
	Q.push("1");
	while(n--){
		string s1 = Q.front();
		Q.pop();
		cout<<s1<<endl;
		string s2 = s1;
		Q.push(s1.append("0"));
		Q.push(s2.append("1"));
	}
}
int main()
{
    int n = 10;
    generateBinary(n);
    return 0;
}
