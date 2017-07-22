#include<iostream>

using namespace std;

bool isSubsetSum(int ar[], int sum,int n){
	bool dp[12][12];
	int i,j;
	
	for(i=0;i<=n;i++) dp[i][0]=true;
	for(i=1;i<=sum;i++) dp[0][i]=false;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=sum;j++){
			if(i>j) dp[i][j]=dp[i-1][j];
			else dp[i][j] = dp[i-1][j]||dp[i-1][j-ar[i]];
		}
		
	return dp[n][sum];
}

bool isSubsetSumR(int ar[], int sum, int n){
	if(sum==0) return true;
	if(n==0 && sum!=0) return false;
	if(ar[n]>sum) return isSubsetSumR(ar,sum,n-1);
	return isSubsetSum(ar,sum,n-1)||isSubsetSumR(ar,sum-ar[n],n-1);
}


int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, sum, n) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  if (isSubsetSumR(set, sum, n-1) == true)
     printf("\nFound a subset with given sum");
  else
     printf("\nNo subset with given sum");
  return 0;
}
