#include<iostream>
using namespace std;

int maxOnesIndex(bool ar[], int n){
	int curr,prev=-1,prev_prev=-1;
	int max_len=0,index;
	for(curr=0;curr<n;curr++){
		 if(ar[curr]==0){
		 	if(curr-prev_prev>max_len){
		 		max_len=curr-prev_prev;
		 		index = curr;
			    }
			 prev_prev=prev;
			 prev=curr;
			}
	}
	if(n-prev_prev > max_len) index = prev;
	return index;
}

int main()
{
    bool arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of 0 to be replaced is "
         << maxOnesIndex(arr, n);
    return 0;
}
