#include<iostream>
#include<climits>

using namespace std;

int main(){
	
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int dp[size+1][size+1];
    int i,j;
    
    for(i=0;i<=size;i++) {
    	dp[i][0] = 0;
    	dp[0][i] = 0;
	}
    
    for(i=1;i<=size;i++){
    	for(j=1;j<=size;j++){
    		if(i>j) dp[i][j]=dp[i-1][j];
    		else dp[i][j]=max(dp[i-1][j],arr[i-1]+dp[i][j-i]);
		}
	}
	cout<<dp[size][size];
    
    
    return 0;
}
