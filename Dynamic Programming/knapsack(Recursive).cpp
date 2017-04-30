// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<iostream>

using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n)
{
	
	if(W==0 || n==0) return 0;
	if(wt[n-1] > W) return knapsack(W,wt,val,n-1);
	return max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1), knapsack(W,wt,val,n-1));
  
}
 
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(W, wt, val, n);
    return 0;
}
