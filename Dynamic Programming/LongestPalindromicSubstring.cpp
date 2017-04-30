#include<iostream>
#include<string>

using namespace std;

int main()
{
    char str[] = "psforof";
    int n = 7;
    
    bool dp[n][n];
    int start=0,max=1;
    int i,j,l;
  
    for(i=0;i<n;i++) dp[i][i]=true;
  
    for(l=2;l<=n;l++){
    	for(i=0;i<n-l+1;i++){
    		j=i+l-1;
    		if(l==2 && str[i]==str[j]){
    			dp[i][j]=true;
    			start = i;max=2;
			} 
			else if(dp[i+1][j-1] && str[i]==str[j]){
				dp[i][j]=true;
				start = i;
				max=l;
			}
    	}
	}
	cout<<max<<" ";
	for(i=start;i<start+max;i++) cout<<str[i];
	
	return 0;
}
