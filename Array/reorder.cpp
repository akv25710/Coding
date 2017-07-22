#include<iostream>
using namespace std;

void reorder(int ar[], int index[], int n){
	for(int i=0;i<n;i++){
		if(i!=index[i]){
			swap(ar[i],ar[index[i]]);
			swap(index[i],index[index[i]]);
		}
	}
}

int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    reorder(arr, index, n);
 
    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    return 0;
}
