#include<iostream>

using namespace std;

void printTwoOdd(int ar[], int n){
	int xor2=ar[0],i;
	for(i=1;i<n;i++)
		xor2 = xor2^ar[i];
	i=5^1;	
	cout<<i;
	return;
}

int main()
{
  int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printTwoOdd(arr, arr_size);
  getchar();
  return 0;
}
