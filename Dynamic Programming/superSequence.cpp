#include<iostream>
#include<string.h>

using namespace std;

int superSequenceR(char* X, char* Y, int m, int n){
	if (!m) return n;
    if (!n) return m;
    
    if(X[m-1]==Y[n-1]) return 1+superSequenceR(X,Y,m-1,n-1);
    
    return  1+min(superSequenceR(X,Y,m-1,n), superSequenceR(X,Y,m,n-1));
	
}

int superSequence(char* X, char* Y, int m, int n){
	int dp[m+1][n+1];
	int i,j;
	
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++){
			if (!i)
               dp[i][j] = j;
           else if (!j)
               dp[i][j] = i;
           else if(X[i-1]==Y[j-1])
		   		dp[i][j]=1+dp[i-1][j-1];
		   else
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);		 
		}
	return dp[m][n];
}



int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout << "Length of the shortest supersequence is "<<endl
         << superSequenceR(X, Y, strlen(X), strlen(Y))<<endl
		 << superSequence(X, Y, strlen(X), strlen(Y));
    return 0;
}
