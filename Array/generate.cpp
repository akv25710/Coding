#include<iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
/*
void generate(int ar[], int br[], int m, int n){
	int i,j,k,l,result[m+n];
	for(i=0;i<m;i++){
		k=0;
		l=i;
		result[k++]=ar[i];
		for(j=0;j<n;j++){
			if(br[j]>ar[l]){
				result[k++]=br[j];
				printArr(result,k);
				while(ar[l]<br[j]) l++;
				result[k++]=ar[l];
			}
		}
	}
}
*/
void generateUtil(int ar[], int br[], int output[], int i, int j, int m, int n, int len, bool flag){
	if(flag){
		if(len) printArr(output,len+1);
		for(int k=i;k<m;k++){
			if(!len){
				output[len]=ar[k];
				generateUtil(ar,br,output,k+1,j,m,n,len,!flag);
			}
			else{
				if(ar[k]>output[len]){
					output[len+1]=ar[k];
					generateUtil(ar,br,output,k+1,j,m,n,len+1,!flag);
				}
			}
		}
		
	}
	else{
		for(int l=j;l<n;l++){
			if(br[l]>output[len]){
				output[len+1]=br[l];
				generateUtil(ar,br,output,i,l+1,m,n,len+1,!flag);
			}
		}
	}
}

void generateR(int A[], int B[], int m, int n)
{
    int C[m+n]; 
    generateUtil(A, B, C, 0, 0, m, n, 0, true);
}
 


int main()
{
    int A[] = {10, 15, 25};
    int B[] = {5, 20, 30};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    generateR(A, B, n, m);
    return 0;
}
