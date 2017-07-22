#include<iostream>
#include<cstring>
#define ROW 5
#define COL 5
using namespace std;

bool isSafe(int ar[][COL], int row, int col, bool visited[][COL]){
	
	return (row<ROW && col<COL && row >=0 &&
			col>=0 && ar[row][col] && !visited[row][col]);
}

void DFS(int ar[][COL], int row, int col, bool visited[][COL]){
	static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    visited[row][col] = true;
    for(int k=0;k<8;k++)
    	if(isSafe(ar,row+rowNbr[k],col+colNbr[k],visited))
    		DFS(ar,row+rowNbr[k],col+colNbr[k],visited);
}

int countIsland(int ar[][COL]){
	bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    int count=0;
    for(int i=0;i<ROW;i++)
    	for(int j=0;j<COL;j++)
    		if(!visited[i][j] && ar[i][j]){
    			DFS(ar,i,j,visited);
    			count++;
			}
			
	return count;
}

int main()
{
    int M[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIsland(M));
 
    return 0;
}
