#include<iostream>

using namespace std;

int searchInSortedAndRotated(int ar[], int low, int high, int key){
	if(low>high) return -1;
	int mid = (low + high)/2;
	
	if(ar[mid]==key) return mid;
	
	if(ar[low] <= ar[mid]){
		if(key>=ar[low] && key <= ar[mid]) return searchInSortedAndRotated(ar, low, mid-1, key);
		return searchInSortedAndRotated(ar, mid+1, high, key);
	}
	
	if(key<=ar[high] && key >= ar[mid]) return searchInSortedAndRotated(ar, mid+1, high, key);
	return searchInSortedAndRotated(ar, low, mid-1, key);	
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 1;
    cout<<searchInSortedAndRotated(arr, 0, n-1, key);
    
    return 0;    
}
