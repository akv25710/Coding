#include<iostream>
using namespace std;

int maxCircularSum(int ar[], int n){
	int max_sum=0,sum=0;
	int sum_now=0;
	for(int i=0;i<n;i++){
		sum+=ar[i];
		ar[i] = -ar[i];
	}
	for(int i=0;i<n;i++){
		sum_now+=ar[i];
		if(sum_now<0) sum_now=0;
		max_sum = max(max_sum,sum_now);
	}
	return sum+max_sum;	
}

int main()
{
    int a[] =  {-1, 40, -14, 7, 6, 5, -4, -1};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %d",
                              maxCircularSum(a, n));
    return 0;
}
