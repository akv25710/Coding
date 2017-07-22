#include<iostream>

using namespace std;

int sum(int freq[], int i, int j){
	int sum=0;
	for(int k=i;k<=j;k++) sum+=freq[k];
	return sum;
}

int optimalBinarySearchTreeRecursive(int freq[], int i, int j){
	if(i>j) return 0;
	if(i==j) return freq[i];
	
	int fsum = sum(freq,i,j);
	int min = INT_MAX;
	
	for(int k=i; k<=j; ++k){
		int cost = optimalBinarySearchTreeRecursive(freq,i,k-1) + optimalBinarySearchTreeRecursive(freq,k+1,j);
		if(cost < min) min = cost;
	}
	return min+fsum;
}

int optimalBinarySearchTree(int freq[], int n){
	int cost[n][n];
	for(int i=0;i<n;i++) cost[i][i] = freq[i];
	
	for(int L=2;L<=n;L++){
		for(int i=0;i<n-L+1;i++){
			int j = i+L-1;
			cost[i][j] = INT_MAX;
			for(int r=i; r<=j; r++){
				int c=((r>i)? cost[i][r-1]:0) + ((r<j)? cost[r+1][j]:0) + sum(freq,i,j);
				if(c < cost[i][j]) cost[i][j]=c;
			}
		}
	}
	return cost[0][n-1];
}



int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d ", optimalBinarySearchTreeRecursive(freq,0,n-1));
    cout<<optimalBinarySearchTree(freq,n);
    return 0;
}
