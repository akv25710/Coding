#include<iostream>
#define R 3
#define C 3

using namespace std;

int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};
	
int isValid(int i, int j){
	if(i<0||i>=R||j<0||j>=C) return false;
	return true;
}

bool isAdjacent(char prev, char curr){
	return ( (curr-prev) == 1);
}

int getLength(char dp[][C],char key, int i, int j){
	int ans=0,p,q;
	for(int k=0;k<8;k++){
		for(int move=0;move<8;move++){
			p = i+x[move];
			q = j+y[move];
			if(isValid(p,q) && isAdjacent( dp[i][j],dp[p][q] )){
				ans+=1;
				i = p;
				j = q;
			}
		}
	}
	return ans;
	
} 

int LongestConsecutive(char mat[][C], char key){
	int i,j;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			if(mat[i][j] == key ) return 1+getLength(mat,key,i,j);
	return 0;	
}

int main() {
 
    char mat[R][C] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};
 
    cout << LongestConsecutive(mat, 'a') << endl;
    cout << LongestConsecutive(mat, 'e') << endl;
    cout << LongestConsecutive(mat, 'b') << endl;
    cout << LongestConsecutive(mat, 'f') << endl;
    return 0;
}
