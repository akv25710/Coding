#include<iostream>
using namespace std;

void printFrequency(int ar[], int n){
	for(int i=0;i<n;i++) ar[i]-=1;
	for(int i=0;i<n;i++) ar[ar[i]%n]+=n;
	for(int i=0;i<n;i++) cout<<i+1<<"->"<<ar[i]/n<<endl;
}

int main()
{
    int arr[] = {2, 3, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printFrequency(arr,n);
    return 0;
}
