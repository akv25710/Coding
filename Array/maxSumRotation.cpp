#include<iostream>
using namespace std;

int maxSumRotation(int ar[], int n){
	int sum=0,val=0,i;
	for(i=0;i<n;i++){
		sum+=ar[i];
		val+=i*ar[i];
	}
	int maxVal=val;
	for(i=1;i<n;i++){
		val = val + sum - n*ar[n-i];
		maxVal = max(maxVal,val);
	}
	return maxVal;
}

int main()
{
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMax sum is " << maxSumRotation(arr, n);
    return 0;
}
