#include<iostream>

using namespace std;

int maxSumNoAdjacent(int ar[], int n){
	if (n==1) return ar[0];
	if(n==2) return max(ar[0],ar[1]);
	int dp[n];
	dp[0]=ar[0];
	dp[1]=max(ar[0],ar[1]);
	for(int i=2;i<n;i++){
		dp[i]=max(dp[i-2]+ar[i],dp[i-1]);
	}
	return dp[n-1];
}

int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("%d \n", maxSumNoAdjacent(arr, n));
  return 0;
}
