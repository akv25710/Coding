#include<iostream>
#include<string>

using namespace std;

int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = 13;
    
    int dp[n][n];
    int i,j,l;
    for(i=0;i<n;i++) dp[i][i]=1;
    
    for(l=2;l<=n;l++)
    	for(i=0;i<n-l+1;i++){
    		j=i+l-1;
    		
			if(seq[i]==seq[j] && l==2) dp[i][j]=2;
			else if(seq[i]==seq[j])  dp[i][j]=2+dp[i+1][j-1];
			else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
			
			}
	cout<<dp[0][n-1];   
    return 0;
}
    
