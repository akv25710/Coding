#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int ar[] = {3,4,-1,0,6,2,3};
	int T[12];
	int i,j;
	int max = -1;
	int n = sizeof(ar)/sizeof(ar[0]);
	
	for (i=0;i<n;i++)
		T[i]=1;
		
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(ar[j] < ar[i] && T[i] < T[j]+1)
				T[i] = T[j]+1;			
	
	
	for (i=0;i<n;i++){   
		if(T[i]>max)
			max = T[i];
	}
	cout<<max;
	
	return 0;
	
}
