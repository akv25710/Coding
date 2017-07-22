#include<iostream>
using namespace std;

void subArraySum(int ar[], int n, int sum){
	int curr_sum=ar[0];
	int start=0;
	for(int i=1;i<=n;i++){
		while(curr_sum>sum && start < i-1){
			curr_sum -= ar[start];
			start++;
		}
		if(curr_sum==sum){
			cout<<"Between "<<start<<" and "<<i-1;
			return;
		}
		if(i<n) curr_sum+=ar[i];
	}
	cout<<"No subarray found";
	return;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}
