#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
	char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    int T [13][12];
    int i,j;
    
    int m = strlen(X);
    int n = strlen(Y);
    
    for(i=0;i<=m;i++)
    	for(j=0;j<=n;j++){
    		if(i==0 || j==0)
    			T[i][j]=0;
			else if(X[i-1]==Y[j-1])
				T[i][j] = T[i-1][j-1] + 1;
			else
				T[i][j] = max(T[i-1][j],T[i][j-1]);			
		}
		
	cout<<T[m][n];
	return 0;
	
}
