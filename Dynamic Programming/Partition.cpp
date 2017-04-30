#include<iostream>

using namespace std;


bool findPartition(int ar[],int n){
	int i,j,sum=0;
	
	for(i=0;i<n;i++) sum+=ar[i];
	if(sum%2!=0) return false;
	
	bool part[sum/2+1][n];

	for(i=0;i<=n;i++) part[0][i]=true;
	for(i=1;i<=sum/2;i++) part[i][0]=false;
	
	for(i=1;i<=sum/2;i++){
		for(j=1;i<=n;j++){
			part[i][j]=part[i][j-1];
			if(i>=ar[j-1])
				part[i][j] = (part[i][j]||part[i-ar[j-1]][j-1]);
		}
	}
	return part[sum/2][n];
}


int main(){
	int arr[] = {3, 1, 1, 2, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  if(findPartition(arr,n)) cout<<"Possible";
  else cout<<"Not Possible";
  return 0;
}
