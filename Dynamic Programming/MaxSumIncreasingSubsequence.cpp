#include<iostream>

using namespace std;

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int list[n];
    int i,j;
    
    for(i=0;i<n;i++) list[i] = arr[i];
    
    for(i=1;i<n;i++)
    	for(j=0;j<i;j++)
			if(arr[i]>arr[j]) list[i] = max(list[i],arr[i]+list[j]);
	int max = list[0];		
	for(i=1;i<n;i++) 
		if(list[i] > max) max=list[i];
    cout<<max;
    return 0;
}
