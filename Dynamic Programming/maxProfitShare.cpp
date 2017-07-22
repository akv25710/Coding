#include<iostream>

using namespace std;

int maxProfitShare(int prices[],int n, int k){
	int profit[k+1][n];
	
	for(int i=0;i<=k;i++) profit[i][0]=0;
	for(int i=1;i<n;i++) profit[0][i]=0;
	
	for(int i=1;i<=k;i++){
		int maxDiff=-prices[0];
		for(int j=1;j<n;j++){
			profit[i][j]=max(profit[i][j-1],prices[j]+maxDiff);
			maxDiff=max(maxDiff,profit[i-1][j]-prices[j]);
		//	cout<<profit[i][j]<<" ";
		}
		//cout<<maxDiff<<endl;
	}
	return profit[k][n-1];
}

int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfitShare(price, n, 2);
    return 0;
}
