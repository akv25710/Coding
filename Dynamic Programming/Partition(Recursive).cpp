#include<iostream>

using namespace std;

bool isSubsetSum(int ar[], int n, int sum){
	if(sum==0) return true;
	if(n==0&&sum!=0) return false;
	if(ar[n-1]>sum) return isSubsetSum(ar,n-1,sum);
	return isSubsetSum(ar,n-1,sum)||isSubsetSum(ar,n-1,sum-ar[n-1]);
}

bool findPartition(int ar[],int n){
	int i,sum=0;
	for(i=0;i<n;i++) sum+=ar[i];
	if(sum%2!=0) return false;
	return isSubsetSum(ar,n,sum/2);	
}

int main(){
	int arr[] = {3, 1, 5, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<findPartition(arr,n);
  return 0;
}
