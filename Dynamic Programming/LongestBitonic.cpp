#include<iostream>

using namespace std;

int main(){
	
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
	
	int i,j,ans=0;
	int list1[n],list2[n];
	
	for(i=0;i<n;i++){
		list1[i]=1;
		list2[i]=1;
	}
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++)
			if(arr[i]>arr[j]) list1[i]=max(list1[i],list1[j]+1);
	}
	
	for(i=n-2;i>=0;i--){
		for(j=n-1;j>i;j--)
			if(arr[i]>arr[j]) list2[i]=max(list2[i],list2[j]+1);
	}
	
	for(i=0;i<n;i++)
		list1[i] += list2[i]-1;
		
	for(i=0;i<n;i++)
		if(ans < list1[i]) ans=list1[i];
				
	cout<<ans;
	return 0;
}
