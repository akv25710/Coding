#include<iostream>
#include<string>

using namespace std;
 
int main(){
	
	char str[] = "ababbbabbababa";
	int n = sizeof(str)/sizeof(str[0])-1;
	bool P[n][n];
	int C[n];
	int i,j,k,l;
    
	for(i=0;i<n;i++) P[i][i]=true;
	
	for(l=2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j = i+l-1;
			if(l==2) P[i][j]=(str[i]==str[j]);
			else P[i][j]= (str[i]==str[j] && P[i+1][j-1]);
		}
	}
	
	for(i=0;i<n;i++){
		if(P[0][i]==true) C[i]=0;
		else{
			C[i]=INT_MAX;
			for(j=0;j<i;j++)
				if(P[j+1][i]==true && 1+C[j]<C[i]) C[i]=C[j]+1;
		} 
	}
	
	
	cout<<C[n-1];	
	return 0;	
}
