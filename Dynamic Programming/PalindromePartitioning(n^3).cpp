#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(char *string1 , int start , int end){
	
	while(start<end){
		if(string1[start++]!=string1[end--]) return false;
	}
	return true;
}

int main(){
	
	char str[] = "abcbm";
	int n = sizeof(str)/sizeof(str[0])-1;
	int P[n][n];
	int i,j,k,l;
	
	for(i=0;i<n;i++) P[i][i] = 0;
	
	for(l=2;l<=n;l++)
		for(i=0;i<=n-l+1;i++){
			j = i+l-1;
			
			if(isPalindrome(str,i,j)) P[i][j]=0;
			else{
				P[i][j]=INT_MAX;
				for(k=i;k<j;k++)
					P[i][j] = min(P[i][j],1+P[i][k]+P[k+1][j]);	
			
		}
	}
	
	cout<<P[0][n-1];
	
	
	return 0;
}
