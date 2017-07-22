#include<iostream>

using namespace std;

int ceilSearch(int ar[],int low, int high, int x){
	if(x <= ar[low])
    	return low; 
    	
    if(x >= ar[high])
    return -1;
	
	int mid = (low+high) / 2;
	 
	if(ar[mid]==x) return mid;
	else if(ar[mid]>x)
		if(x<=ar[mid+1]) return mid+1;
		else ceilSearch(ar,low, mid, x);
	else
		if(x<=ar[mid-1]) return mid-1;
		else	ceilSearch(ar,mid+1, high, x);
}

int main()
{
   int arr[] = {1, 2, 8, 10, 10, 12, 19};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 13;
   int index = ceilSearch(arr, 0, n-1, x);
   if(index == -1)
     printf("Ceiling of %d doesn't exist in array ", x);
   else 
     printf("ceiling of %d is %d", x, arr[index]);
   getchar();
   return 0;
}
