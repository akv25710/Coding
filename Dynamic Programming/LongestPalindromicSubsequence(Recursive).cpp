#include<iostream>
#include<string>

using namespace std;

int lps(char *seq, int i, int j){
	if(i==j) return 1;
	if(i>j) return 0;
	if(seq[i]==seq[j])  return 2+lps(seq,i+1,j-1);
	return max(lps(seq,i,j-1),lps(seq,i+1,j));
}

int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = 13;
 
 	cout<<lps(seq,0,n-1);
 
    
    return 0;
}
