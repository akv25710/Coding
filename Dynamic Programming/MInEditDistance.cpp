#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	
	string str1 = "sunday";
    string str2 = "saturday";
    
    int m = str1.length();
    int n = str2.length();
    int dp [12][12];
    
    int i,j;
    
   
    for(i=0;i<=m;i++)
    	for(j=0;j<=n;j++){
    		if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i; 
    		else if(str1[i-1]==str2[j-1]) 
				dp[i][j]=dp[i-1][j-1];
    		else 
				dp[i][j]=1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]); 
		}
		
	cout<<dp[m][n];	
	
	return 0;
}
