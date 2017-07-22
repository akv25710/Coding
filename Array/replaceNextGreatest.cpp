#include<iostream>
using namespace std;

void replaceNextGreatest(int ar[], int n){
	int greatest=ar[n-1];
	for(int i=n-2;i>=0;i--){
		int temp=ar[i];
		ar[i]=greatest;
		greatest = max(temp,greatest);
	}
	ar[n-1] = -1;
}

void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = {16, 17, 4, 3, 5, 2};
  int size = sizeof(arr)/sizeof(arr[0]);
  replaceNextGreatest (arr, size);
  printf ("The modified array is: \n");
  printArray (arr, size);
  return (0);
}
