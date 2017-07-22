
#include <bits/stdc++.h>
using namespace std;
 
// Max # of persons in the party
#define N 8
 
// Person with 2 is celebrity
bool  MATRIX[N][N] = {{0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};
 
bool knows(int a, int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n){
	int i=0,j=n-1;
	while(i<j){
		if(knows(i,j)) i++;
		else j--;
	}
	for(int x=0;x<n;x++)
		if ( (x != i) &&
                (knows(i, x) || !knows(x, i)) )
            return -1;
	
	return i;
}

int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}
