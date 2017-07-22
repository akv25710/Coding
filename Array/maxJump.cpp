#include<iostream>
using namespace std;


int minJumps(int ar[],int n){
	if(n<=1) return 0;
	if(ar[0]==0) return -1;
	int maxReach=ar[0],step=ar[0],jump=0;
	for(int i=0;i<n;i++){
		if(i==n-1) return jump;
		maxReach=max(maxReach,i+ar[i]);
		step--;
		if(step==0){
			jump++;
			if(i>=maxReach) return -1;
			step=maxReach-i;
		}
	}
	return -1;
}

int main()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
   
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
}
