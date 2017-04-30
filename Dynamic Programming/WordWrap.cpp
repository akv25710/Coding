#include<iostream>

int INF = INT_MAX;
using namespace std;

int printSolution(int p[],int n){
	int k;
	if(p[n]==1) k=1;
	else k=printSolution(p,p[n]-1)+1;
	cout<<"Line number"<<k<<": From word no."<<p[n]<<"to"<<n;
	cout<<endl;
	return k;
}

void solveWordWrap(int l[], int n, int M){
	
	int extras[n+1][n+1];
	int lc[n+1][n+1];
	int c[n+1];
	int p[n+1];
	int i,j;
	
	for(i=1;i<=n;i++){
		extras[i][i]= M-l[i-1];
		//cout<<extras[i][i]<<" ";
		for(j=i+1;j<=n;j++){
			extras[i][j] = extras[i][j-1]-l[j-1]-1;
			//cout<<extras[i][j]<<" ";
		}
		//cout<<endl;
	} 
	
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(extras[i][j]<0) 
				lc[i][j] = INF;
			else if(j==n && extras[i][j]>=0) 
				lc[i][j]=0;
			else 
				lc[i][j] = extras[i][j]*extras[i][j];
			//cout<<lc[i][j]<<" ";	
		}
		//cout<<endl;
	}
	
	c[0]=0;
	for(j=1;j<=n;j++){
		c[j]=INF;
		for(i=1;i<=j;i++){
			if(c[i-1]!=INF && lc[i][j]!=INF && c[i-1]+lc[i][j] < c[j]){
				c[j] = c[i-1]+lc[i][j];
				p[j]=i;
			}
		}
	}
	
/*	for(i=1;i<=n;i++){
		cout<<c[i]<<" "<<p[i];
		cout<<endl;
	}
*/

	printSolution(p,n);
}



int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    solveWordWrap (l, n, M);
    return 0;
}
