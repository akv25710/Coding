#include<iostream>
using namespace std;

void sortInWave(int ar[], int n){
	for(int i=0;i<n;i+=2){
		if(i>0 && ar[i-1]>ar[i]) swap(ar[i],ar[i-1]);
		if(i<n-1 && ar[i+1]>ar[i]) swap(ar[i],ar[i+1]);
	}
}

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}
