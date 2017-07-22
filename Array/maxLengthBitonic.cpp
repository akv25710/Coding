#include<iostream>
using namespace std;

int maxLengthBitonic(int ar[], int low, int high){
	if(low>high) return 0;
	if(low==high) return 1;
	if(ar[low]<=ar[low+1]) return 1+maxLengthBitonic(ar,low+1,high);
	if(ar[high]<=ar[high-1]) return 1+maxLengthBitonic(ar,low,high-1);
	if(ar[low]>ar[low+1]) return maxLengthBitonic(ar,low+1,high);
	if(ar[high]>ar[high-1]) return maxLengthBitonic(ar,low,high-1);
}

int main()
{
    int arr[] = {20, 4, 1, 2, 3, 4, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nLength of max length Bitnoic Subarray is %d",
            maxLengthBitonic(arr, 0, n-1));
    return 0;
}
