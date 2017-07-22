#include<iostream>

using namespace std;

int maxDiff(int ar[], int size){
	int i,max_diff=ar[1]-ar[0],min_element=ar[0];
	for(i=1;i<size;i++){
		max_diff =  max(max_diff,ar[i]-min_element);
		min_element = min(min_element,ar[i]);	
	}
	return max_diff;
}

//find adjacent diff and store in temp array 
//solve for max sum subarray

int main()
{
  int arr[] = {4, 2, 6, 80, 100};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout<<"Maximum difference is "<<maxDiff(arr, size);
  return 0;
}
