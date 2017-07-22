#include<iostream>
using namespace std;

void maxMin(int ar[], int n){
	int temp[n];
	int i=0,j=n-1;
	for(int k=0;k<n;k++){
		if(k%2==0) temp[k]=ar[j--];
		else temp[k]=ar[i++];
	}
	for(i=0;i<n;i++)
		ar[i]=temp[i];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Original Array\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    maxMin(arr, n);
 
    cout << "\nModified Array\n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
