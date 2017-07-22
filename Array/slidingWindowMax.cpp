#include<iostream>
using namespace std;

void slidingWindowMax(int arr[], int n, int k)
{
    int j, max;
 
    for (int i = 0; i <= n-k; i++)
    {
        max = arr[i];
 
        for (j = 1; j < k; j++)
        {
            if (arr[i+j] > max)
               max = arr[i+j];
        }
        printf("%d ", max);
    }
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    slidingWindowMax(arr, n, k);
    return 0;
}
