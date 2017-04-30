#include<iostream>

using namespace std;

struct Pair{
	int a;
	int b;
};

int main(){
	
	struct Pair ar[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
    int n = sizeof(ar)/sizeof(ar[0]);
    
    int i,j,q=0;
    int mcl[n];
    
    for(i=0;i<n;i++) mcl[i]=1;
    
    for(i=1;i<n;i++)
    	for(j=0;j<i;j++)
    		if(ar[i].a > ar[j].b)
    			mcl[i] = max(mcl[i],1+mcl[j]);
	
	for(i=0;i<n;i++) 
		if(mcl[i]>q)
			q = mcl[i];
	
	cout<<q;
	
	return 0;
}
