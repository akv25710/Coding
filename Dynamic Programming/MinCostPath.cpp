#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	
	int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
                      
    int i,j;
    int dp[12][12];
    dp[0][0]=cost[0][0];
    
    for(i=1;i<3;i++) {
    	dp[i][0]=dp[i-1][0]+cost[i][0];
    	dp[0][i]=dp[0][i-1]+cost[0][i];	
	}
	
	for(i=1;i<3;i++)
		for(j=1;j<3;j++){
			dp[i][j]=cost[i][j]+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
		}
    cout<<dp[2][2];
	
	
	
	return 0;
}
