#include<iostream>
#include<math.h>
using namespace std;

void printClosest(int ar[], int br[], int m, int n, int x){
	int l=0,r=n-1;
	int a,b;
	int maxDiff = INT_MAX;
	while(l<m && r>=0){
		if(abs(ar[l]+br[r]-x)<maxDiff){
			maxDiff = ar[l]+br[r]-x;
			a=l;
			b=r;
		}
		if(ar[l]+br[r]>x) r--;
		else l++;
	}	
	cout<<ar[a]<<" "<<br[b];	
}

int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 30;
    printClosest(ar1, ar2, m, n, x);
    return 0;
}
