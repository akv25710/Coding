#include<iostream>

using namespace std;

int BinomialRecursive(int n, int k){
	
	if(k==0 || k==n) return 1;
	return BinomialRecursive(n-1,k-1)+BinomialRecursive(n-1,k);
	
} 

int main(){
	int n=5,k=2;
	int c[12][12];
	int i,j;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=min(i,k);j++){
			if(j==i || j==0)
				c[i][j]=1;
			else
				c[i][j]= c[i-1][j-1]+c[i-1][j];
		}
	}
	cout<<c[5][2]<<"\n";
	cout<<BinomialRecursive(5,2);
	
	
	return 0;
}

