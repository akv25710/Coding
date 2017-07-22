#include<iostream>
using namespace std;

int countIncreasing(int ar[], int n){
	int count=0,len=1;
	for(int i=0;i<n;i++){
		if(ar[i]<ar[i+1]) len++;
		else{
			count+=len*(len-1)/2;
			len=1;
		}
	}
	return count;
}

int main()
{
  int arr[] = {1, 2, 2, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Count of strictly increasing subarrays is "
       << countIncreasing(arr, n);
  return 0;
}
