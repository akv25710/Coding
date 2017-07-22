#include<iostream>
using namespace std;

int getInvCount(int ar[], int n){
	int count=0;
	for(int i=1;i<n-1;i++){
		int small=0;
		for(int j=i+1;j<n;j++) if(ar[j]<ar[i]) small++;
		int great=0;
		for(int j=i-1;j>=0;j--) if(ar[j]>ar[i]) great++;
		count+=small*great;
	}
	return count;
}

int main()
{
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Inversion Count : " << getInvCount(arr, n);
    return 0;
}
