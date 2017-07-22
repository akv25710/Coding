#include<iostream>
using namespace std;

int maxSubarrayProduct(int ar[], int n){
	int i,max_so_far=ar[0];
	int product=1;
	for(i=0;i<n;i++){
		if((product<0 && ar[i]>0) || product ==0)
			product = ar[i];
		
		else 
			product*=ar[i];
		max_so_far = max(max_so_far,product);
	//	cout<<product<<" "<<max_so_far<<endl;
	}
	return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 0, -2, -40};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Sub array product is %d", 
            maxSubarrayProduct(arr, n));
    return 0;
}
