#include<iostream>
# include <bits/stdc++.h>
using namespace std;

int triplet(int ar[], int n, int sum){
	int i,l,r;
	sort(ar,ar+n);
	for(i=0;i<n-1;i++){
		r=i+1;
		l=n-1;
		while(r<l){
			if(ar[i]+ar[r]+ar[l]==sum){
				cout<<ar[i]<<endl<<ar[r]<<endl<<ar[l]<<"\nFound";
				return 1;
			}
			else if(ar[i]+ar[r]+ar[l]>sum) l--;
			else r++;
		}
	}
	cout<<"Not found";
	return 0;
}

int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    triplet(A, arr_size, sum);
 
    return 0;
}
