#include<iostream>
using namespace std;

int maxPathSum(int ar[], int br[], int m, int n){
	int i,j,sum1=0,sum2=0,sum=0;
	while(i<m && j<n){
		if(ar[i]<br[j]) sum1+=ar[i++];
		else if(ar[i]>br[j]) sum2+=br[j++];
		else{
			sum+=max(sum1,sum2);
			sum1=0;
			sum2=0;
			 while (i < m &&  j < n && ar[i] == br[j])
            {
                sum = sum + ar[i++];
                j++;
            }
		}
	}
	 // Add remaining elements of ar1[]
    while (i < m)
        sum1  +=  ar[i++];
 
    // Add remaining elements of ar2[]
    while (j < n)
        sum2 +=  br[j++];
 
    // Add maximum of two sums of remaining elements
    sum +=  max(sum1, sum2);
	return sum;
}

int main()
{
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << "Maximum sum path is "
         << maxPathSum(ar1, ar2, m, n);
    return 0;
}
