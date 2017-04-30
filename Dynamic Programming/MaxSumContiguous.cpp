#include<iostream>

using namespace std;

int main(){
	
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    
    int i,j,C[n],s=INT_MIN;
    for(i=0;i<n;i++) C[i]=a[i];
    
    for(i=1;i<n;i++)
    	if(C[i]<C[i]+C[i-1]) C[i]+=C[i-1];
    

	for(i=0;i<n;i++)
		if(s<C[i]) s=C[i];
	
	
	cout<<s;
	
	return 0;
}
