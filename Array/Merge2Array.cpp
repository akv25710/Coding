#include<iostream>
using namespace std;
#define NA -1
 
/* Function to move m elements at the end of array mPlusN[] */
void moveToEnd(int mPlusN[], int size)
{
  int i = 0, j = size - 1;
  for (i = size-1; i >= 0; i--)
    if (mPlusN[i] != NA)
    {
      mPlusN[j] = mPlusN[i];
      j--;
    }
}


void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
 
  printf("\n");
}


void Merge2Array( int MplusN[], int N[], int m, int n){
	
	int i=n,k=0,j=0;
	while(k<=m+n){
		if(i<m+n && MplusN[i] <= N[j] || j==n) MplusN[k++]=MplusN[i++];
		else MplusN[k++]=N[j++];
	}
}


 
/* Driver function to test above functions */
int main()
{
  /* Initialize arrays */
  int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
  int N[] = {5, 7, 9, 25};
  int n = sizeof(N)/sizeof(N[0]);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
 
  /*Move the m elements at the end of mPlusN*/
  moveToEnd(mPlusN, m+n);
   printArray(mPlusN, m+n);
 
  /*Merge N[] into mPlusN[] */
  Merge2Array(mPlusN, N, m, n);
 
  /* Print the resultant mPlusN */
  printArray(mPlusN, m+n);
 
  return 0;
}
