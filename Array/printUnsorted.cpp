#include<iostream>

using namespace std;

void printUnsorted(int ar[], int n){
	int i,s,e,max,min;
	for(s=0;s<n-1;s++) if(ar[s]>ar[s+1]) break;
	if(s==n-1){
		cout<<"Sorted Array";
		return;
	} 
	for(e=n-1;e>0;e--) if(ar[e]<ar[e-1]) break;
 	max = ar[s]; min = ar[s];
  	for(i = s + 1; i <= e; i++)
  	{
    	if(ar[i] > max)
      		max = ar[i];
    	if(ar[i] < min)
      		min = ar[i];
  	}
  	for(i=0;i<s;i++){
  		if(ar[i]>min){
  			s=i;
  			break;
		  }
	}
	for(i=n-1;i>e;i--){
		if(ar[i]<max){
			e=i;
			break;
		}
	}
	cout<<s<<" "<<e;
}


int main()
{
  int arr[] = {10, 12, 20, 30, 25, 8, 32, 31, 35, 50, 60};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printUnsorted(arr, arr_size);
  getchar();
  return 0;
}
