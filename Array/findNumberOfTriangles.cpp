#include<iostream>
using namespace std;

int findNumberOfTriangles(int ar[], int n){
	int i,count=0;
	for(int j=2;j<n;j++){
		i=j;
		while(ar[i]<ar[j-1]+ar[j-2] && i<n){
			i++;
			cout<<i;
		}
		count += n-i-1;
		cout<<endl<<count;
	}
	return count;
}

int main()
{
    int arr[] =   {5,5,5};
    int size = sizeof( arr ) / sizeof( arr[0] );
 
    printf("Total number of triangles possible is %d ",
           findNumberOfTriangles( arr, size ) );
 
    return 0;
}
