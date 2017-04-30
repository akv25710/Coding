#include<iostream>
#include<climits>

using namespace std;

int max(int a, int b) { return (a > b)? a: b; }

int eggDrop(int n, int k){
	
	if(k==0 || k==1) return k;
	if(n==1) return k;
	
	int i,res,min=INT_MAX;
	
	for(i=1;i<=k;i++){
		res = max(eggDrop(n-1,i-1),eggDrop(n,k-i));
		if (res < min)
			min = res;
	}
	return min+1;
}


int main()
{
    cout<<eggDrop(4,10);
    
    return 0;
}
