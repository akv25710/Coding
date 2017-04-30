#include<iostream>

using namespace std;

int main(){
	
	int arr[] = {1, 3, 6, 1, 0, 9};
    int n = sizeof(arr)/sizeof(int);
    
    int i,j,jumps[n];
    jumps[0]=0;
    
    for(i=1;i<n;i++){
    	jumps[i]=INT_MAX;
    	for(j=0;j<i;j++){
    		if(i<=j+arr[j] && jumps[j]!=INT_MAX)
    			jumps[i]=min(jumps[i],1+jumps[j]);
		}
	}
	
	cout<<jumps[n-1];
	
	return 0;
}
