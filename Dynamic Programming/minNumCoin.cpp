#include<iostream>

using namespace std;

int minNumCoinR(int coins[], int m, int V){
	if(V==0) return 0;
	int res = INT_MAX;
	
	for(int i=0; i<m; i++){
		if(coins[i]<=V){
		int sub_res = minNumCoinR(coins, m, V-coins[i]);
        if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
		}
	}
	return res;
}

int minNumCoin(int coins[], int m ,int V){
	int i,dp[V+1];
	dp[0]=0;
	for(i=1;i<=V;i++) dp[i]=INT_MAX;
	for(i=1;i<=V;i++)
		for(int j=0;j<m;j++)
			if(coins[j]<=i)
				dp[i] = min(dp[i],1+dp[i-coins[j]]);
	return dp[V];
}



int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minNumCoin(coins, m, V)<<endl;
    cout << "Minimum coins required is "
         << minNumCoinR(coins, m, V);
    return 0;
}
