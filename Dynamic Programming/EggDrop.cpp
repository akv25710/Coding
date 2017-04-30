#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b) { return (a > b)? a: b; }

int main(){
	int n=2,x=10;
	int i,j,k,res;
	int dp[n+1][k+1];
	

	
	for(i=1;i<=n;i++)
		for(j=1;j<=x;j++){
			dp[i][j]=888888888;
			if (i==1) dp[i][j]=j;
		
			else{
				for(k=1;k<=j;k++){
					res = 1+max(dp[i-1][k-1],dp[i][j-k]);
					if(dp[i][j]>res)
						dp[i][j] = res;
				}
			}
			
		}
		
		cout<<dp[n][x];
		
	
	return 0;
	
}
