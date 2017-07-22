#include<iostream>

using namespace std;

int merge(int ar[], int temp[], int left, int mid, int right){
	int i=left,j=mid,k=left;
	int count=0;
	while(i<mid&&j<=right){
		if(ar[i]<=ar[j]) temp[k++]=ar[i++];
		else{
			temp[k++]=ar[j++];
			count+=(mid-1);
		}
	}
	while (i < mid)
    	temp[k++] = ar[i++];

	while (j <= right)
    	temp[k++] = ar[j++];
    	
    for (i=left; i <= right; i++)
    	ar[i] = temp[i];
 
    return count;
}

int mergeSort(int ar[], int temp[], int left, int right){
	int mid,count=0;
	if(right>left){
		mid = (right+left)/2;
		count = mergeSort(ar,temp,left,mid);
		count += mergeSort(ar,temp,mid+1,right);
		count += merge(ar,temp,left,mid+1,right);		
	}
	return count;
}

int countInversion(int arr[],int size){
	int temp[size];
	return mergeSort(arr,temp,0,size-1);
}

int main()
{
  int arr[] = {1, 20, 6, 4, 5};
  cout<<" Number of inversions ="<<countInversion(arr, 5);
  return 0;
}
