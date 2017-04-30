#include<iostream>
#include<climits>

using namespace std;

int Rod(int price[], int n){
	
	if (n<=0) return 0;
	int value = INT_MIN;
	
	for(int i =0;i<n;i++){
		value = max(value, price[i]+Rod(price,n-i-1));
	}
	return value;
}

int main(){
	
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
	cout<<Rod(arr,size);
	return 0;
}
