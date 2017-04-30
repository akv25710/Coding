#include<iostream>
#include<algorithm>

using namespace std;


int CoinChange(int S[], int m, int n){
	if(n==0) return 1;
	if(n<0) return 0;
	if(m<=0 && n>0) return 0;
	return CoinChange(S,m-1,n)+CoinChange(S,m,n-S[m-1]);
	
}

int main(){
	
	int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    cout<<CoinChange(arr,m,n);
    
    return 0;
}
