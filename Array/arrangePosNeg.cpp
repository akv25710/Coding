#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%4d ", arr[i]);
    cout<<endl;
}

void arrangePosNeg(int ar[], int n){
	int i,j=0;
	for(i=0;i<n;i++)
		if(ar[i] < 0) swap(ar[j++],ar[i]);
	int neg=0,pos=j;
	while(pos<n && neg<pos && ar[neg]<0){
		swap(ar[pos],ar[neg]);
		neg+=2;
		pos++;
	}
		
}

void rearrange(int ar[],int n){
	int pos=0, neg =1;
	while(pos < n && neg < n ){
		while(ar[pos]>0) pos+=2;
		while(ar[neg]<0) neg+=2;
		if(pos<n && neg<n) swap(ar[pos],ar[neg]);
		pos+=2;
		neg+=2;
	}	
}
 

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    arrangePosNeg(arr, n);
    printArray(arr, n);
    return 0;
}
