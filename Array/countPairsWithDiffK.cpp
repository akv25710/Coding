#include<iostream>
#include<algorithm>
using namespace std;

int countPairsWithDiffK(int ar[], int n, int k){
	int count=0;
	sort(ar,ar+n);
	int l=0,r=0;
	while(r<n){
		if(ar[r]-ar[l] == k){
			count++;
			r++;
			l++;
		}
		else if(ar[r]-ar[l]>k) l++;
		else r++;
	}
	return count;
}

int main()
{
    int arr[] =  {1, 5, 3, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << "Count of pairs with given diff is "
         << countPairsWithDiffK(arr, n, k);
    return 0;
}
