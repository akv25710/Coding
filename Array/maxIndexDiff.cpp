#include<iostream>

using namespace std;

int maxIndexDiff(int ar[],int n){
	int maxDiff=-1;
	if(n<1) return -1;
	if(n==0) return 0;
	int i=0,j=n-1;
	while(i<j){
		if(ar[j]>ar[i]){
			maxDiff=j-i;
			break;
		} 
		else {
			i++;
			if(ar[j]>ar[i]){
			maxDiff=j-i;
			break;
			}
			j--;
			i--;
			if(ar[j]>ar[i]){
			maxDiff=j-i;
			break;
			}
			i++;						
		}
	} 
	return maxDiff;
}

int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    printf("\n %d", maxDiff);
    getchar();
    return 0;
}
