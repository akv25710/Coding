#include<iostream>
#include<limits>

using namespace std;

int main(){
	
	 int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int i,l,j,k,q;
    int dp[12][12];
    
    for(i=1;i<size;i++)
    	dp[i][i]=0;
    	
    for(l=2;l<size;l++){
    	for(i=1;i<size-l+1;i++){
    		j=i+l-1;
    		dp[i][j]=1223344;
    		for(k=1;k<j;k++){
    			q=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
    			if(q<dp[i][j])
    				dp[i][j]=q;
			}
		}
	}
	cout<<dp[1][size-1];
	
	return 0;
}
