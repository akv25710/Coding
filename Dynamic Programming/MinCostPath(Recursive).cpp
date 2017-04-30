#include<iostream>
#include<algorithm>

using namespace std;


int MinCostPath(int cost[3][3], int m, int n){
	
	if (n < 0 || m < 0)
		return INT_MAX;	
	if(m==0 && n==0) 
		return cost[m][n];
	return cost[m][n] + min(min(MinCostPath(cost,m-1,n),
								MinCostPath(cost,m,n-1)),
								MinCostPath(cost,m-1,n-1));
}

int main(){
	
	int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
                      
    cout<<MinCostPath(cost,2,2);                  
	return 0;
}
