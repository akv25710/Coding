#include<iostream>
using namespace std;

int partition(int ar[], int l, int r){
	int x=ar[r];
	int i=l,j;
	for(j=l;j<r;j++)
		if(ar[j]<=x) swap(ar[i++],ar[j]);
	swap(ar[i],ar[r]);
	return i;	
}

int kthSmallest(int ar[], int l, int r, int k){
	if(k<=0 && k>r-l) return INT_MAX;
	int pos = partition(ar,l,r);
	if(pos-l==k-1) return ar[pos];
	if(pos-l>k-1) return kthSmallest(ar,l,pos-1,k);
	return kthSmallest(ar,pos+1,r,k-pos+l-1);
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);
    return 0;
}
