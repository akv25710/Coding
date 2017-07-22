#include<iostream>
#include<bits/stdc++.h>
#define R 3
#define C 3

using namespace std;

int minInitialPoints(int points[][C]){
	int dp[R][C];
	int i,j;
	int m=R,n=C;
	
	dp[m-1][n-1] = points[m-1][n-1]>0?1:abs(points[m-1][n-1])+1;
		
	for(i=m-2;i>=0;i--) dp[i][n-1] = max(dp[i+1][n-1] - points[i][n-1],1);
	for(i=n-2;i>=0;i--) dp[m-1][i] = max(dp[m-1][i+1] - points[m-1][i],1);
	
	for(i=m-2;i>=0;i--){
		for(j=n-2;j>=0;j--){
			int min_p = min(dp[i+1][j],dp[i][j+1]);
			dp[i][j] = max(min_p-points[i][j],1);
		}
	}	
	
	return dp[0][0];
}

int main()
{

	int points[R][C] = { {-2,-3,3},
					{-5,-10,1},
					{10,30,-5}
					};
	cout << "Minimum Initial Points Required: "
		<< minInitialPoints(points);
	return 0;
}
