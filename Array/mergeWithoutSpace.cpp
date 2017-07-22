#include<iostream>
#include<algorithm>
using namespace std;

void mergeWithoutSpace(int ar[], int br[], int m, int n){
	int i,j,k;
	for(j=n-1;j>=0;j--){
		if(br[j]<ar[m-1]) swap(br[j],ar[m-1]);
		i=m-1;
		k=m-2;
		while(ar[i] < ar[k]) swap(ar[i--],ar[k--]);		
	}
}

int main(void)
{
    int ar1[] = {1, 5, 9, 10, 15, 20};
    int ar2[] = {2, 3, 8, 13};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    mergeWithoutSpace(ar1, ar2, m, n);
 
    cout << "After Merging \nFirst Array: ";
    for (int i=0; i<m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i=0; i<n; i++)
        cout << ar2[i] << " ";
   return 0;
}
