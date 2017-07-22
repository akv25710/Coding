#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
  cout<<endl;    

}


void RotateArray(int ar[], int n, int d){
	int x=n-d;
	for(int i=0;i<x;i++){
		swap(ar[i],ar[i+d]);
	}
	for(int i=n-1;i>x;i--){
		swap(ar[i],ar[i-1]);	
	}
	
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   RotateArray(arr, 7, 2);
   printArray(arr, 7);
   return 0;
}
