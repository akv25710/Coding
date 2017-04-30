#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	
	int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    int i,j;
    int dp[12][12];
    
    for (i=0;i<m;i++)
    	dp[i][0]=1;
    	
    for(i=0;i<m;i++)
    	for(j=1;j<=n;j++){
    		int x = (i>=1)?dp[i-1][j]:0;
    		int y = ((j-arr[i])>=0)?dp[i][j-arr[i]]:0;
    		dp[i][j] = x+y;
		}
    
	cout<<dp[m-1][n];
	return 0;
}
