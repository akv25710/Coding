#include<iostream>

using namespace std;

void productArray(int ar[], int n){
	int i,product[n],temp=1;
	for(i=0;i<n;i++) product[i]=1;
	for(i=1;i<n;i++) product[i] = product[i-1]*ar[i-1];
	for(i=n-1;i>=0;i--) {
		product[i]*=temp;
		temp*=ar[i];
	}
	for(i=0;i<n;i++) cout<<product[i]<<" ";
	return;
}


int main()
{
  int arr[] = {10, 3, 5, 6, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The product array is: \n");
  productArray(arr, n);
  getchar();
}
