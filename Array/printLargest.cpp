#include <bits/stdc++.h>
using namespace std;

bool myCompare(string X, string Y){
	string XY = X.append(Y);
	string YX = Y.append(X);
	return XY.compare(YX) ? 1:0;
}

void printLargest(int ar[], int n){
	sort(ar, ar+n, myCompare);
	for(int i=0;i<n;i++)
		cout<<ar[i];
}

int main(){
	int ar[] = {1, 34, 3, 98, 9, 76, 45, 4};
	int n = 8;
	printLargest(ar,n);
	return 0;
}
