#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int EditDist(string str1, string str2, int m, int n){
	if (m==0) return n;
	if (n==0) return m;
	if (str1[m-1] == str2[n-1]) return EditDist(str1,str2,m-1,n-1);
	return 1+min(min(EditDist(str1,str2,m,n-1),EditDist(str1,str2,m-1,n)),EditDist(str1,str2,m-1,n-1));
	
}

int main(){
	
	string str1 = "sunday";
    string str2 = "saturday";
    
    int m = str1.length();
    int n = str2.length();
    
    cout<<EditDist(str1,str2,m,n);
    
    return 0;
}
