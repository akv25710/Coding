#include<iostream>

using namespace std;

int main(){
	int R=6,C=5;
	bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                     {1, 1, 0, 1, 0}, 
                     {0, 1, 1, 1, 0},
                     {1, 1, 1, 1, 0},
                     {1, 1, 1, 1, 1},
                     {0, 0, 0, 0, 0}};
    
	int mat[R+1][C+1];
	int i,j,q=0,max_i,max_j;
	
	for(i=0;i<=R;i++) mat[i][0]=0; 
	for(i=1;i<=C;i++) mat[0][i]=0;  
	
	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++){
			if(M[i-1][j-1]==0) mat[i][j]=0;
			else mat[i][j]=1+min(min(mat[i-1][j-1],mat[i][j-1]),mat[i-1][j]);
			if(mat[i][j]>q){
				q=mat[i][j];
				max_i=i;
				max_j=j;
			}   
		}
	cout<<q<<endl;	
	for(i=max_i-q+1;i<=max_i;i++){
		for(j=max_j-q+1;j<=max_j;j++) cout<<M[i-1][j-1]<<" ";
		cout<<endl;
	}
	     
}
