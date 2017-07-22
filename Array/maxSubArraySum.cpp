#include<iostream>

using namespace std;

int maxSubArraySum(int ar[], int n){
	int maxTotal=0, maxSum=0;
	for(int i=0;i<n;i++){
		maxSum += ar[i];
		if(maxSum < 0) maxSum=0;
		maxTotal = max(maxSum, maxTotal);
	}
	return maxTotal;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

