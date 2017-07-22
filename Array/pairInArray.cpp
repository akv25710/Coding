#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void pairInArray(int arr[],int n, int sum){
	int l=0,h=n-1;
	sort(arr, arr+n);
	while(l<h){
		if(arr[l]+arr[h] > sum) h--;
		else if (arr[l]+arr[h] < sum) l++;
		if(arr[l]+arr[h] == sum){
			cout<<arr[l]<<" "<<arr[h];
			return;
		}
	}
	cout<<"Not Possible";
}

int main()
{
    int A[] = {1, 4, 45, 6, 10, -8};
    int n = 16;
    int arr_size = 6;
    pairInArray(A,arr_size,n);
    
    return 0;
}
