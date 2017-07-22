#include<iostream>
using namespace std;

int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

int getMedian(int ar[],int br[], int n){
	if(n<=0) return -1;
	if(n==1) return ar[0];
	if(n==2) return (max(ar[0],br[0]) + min(ar[1],br[1]))/2;
	
	int m1 = median(ar,n);
	int m2 = median(br,n);
	
	if(m1<m2){
		if(n%2==0) return getMedian(ar+n/2-1,br,n-n/2+1);
		return getMedian(ar+n/2,br,n-n/2);
	}
	if(n%2==0) return getMedian(br+n/2-1,ar,n-n/2+1);
	return getMedian(br+n/2,ar,n-n/2);

}

int main()
{
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}
