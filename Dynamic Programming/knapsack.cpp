#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	
	int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    int i,j,T[n+1][W+1];
    
    for(i=0;i<n+1;i++){
    	
    	for(j=0;j<W+1;j++){
    		
    		if(i==0 || j==0)
				T[i][j]=0;
    		else if(wt[i-1] <= j) 
    			T[i][j]=max(val[i-1]+T[i-1][j-wt[i-1]], T[i-1][j]);
				
    		else 
				T[i][j]=T[i-1][j];
		}
	}
    
    cout<<T[n][W];
	
	return 0;
}
