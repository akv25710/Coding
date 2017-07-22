#include<iostream>

using namespace std;

void sortedSub3(int ar[], int n){
	int max=n-1,min=0;
	int i,smaller[n],greater[n];
	smaller[0]=-1;
	for(i=1;i<n;i++){
		if(ar[i]<=ar[min]){
			min = i;
			smaller[i] = -1;
		}
		else 
			smaller[i]=min;
	}
	greater[n-1]=-1;
	for(i=n-2;i>=0;i--){
		if(ar[i]>=ar[max]){
			max=i;
			greater[i]=-1;
		}
		else
			greater[i]=max;
	}
	for(i=0;i<n;i++){
		if(smaller[i]!=-1 && greater[i]!= -1){
			cout<<ar[smaller[i]]<<" "<<ar[i]<<" "<<ar[greater[i]];
			break;
		}
	}
}

int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortedSub3(arr, n);
    return 0;
}
