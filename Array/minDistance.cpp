#include<iostream>
using namespace std;

int minDistance(int ar[], int n, int x, int y){
	int prev,i,min_dist=INT_MAX;
	for(i=0;i<n;i++)
		if(ar[i]==x||ar[i]==y){
			prev=i;
			break;
		}
	
	for(i=prev+1;i<n;i++)
		if(ar[i]==x||ar[i]==y){
			if(ar[i]!=ar[prev]) 
				min_dist = min(min_dist,i-prev);
		  	prev=i;
	    }

	return min_dist;
}

int main()
{
    int arr[] ={3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 6;
 
    printf("Minimum distance between %d and %d is %d\n", x, y,
              minDistance(arr, n, x, y));
    return 0;
}
