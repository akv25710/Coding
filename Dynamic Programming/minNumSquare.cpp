#include<iostream>
#include<math.h>

using namespace std;

int minNumSquare(int n){
	if(n<=0) return 0;
	int x,a=0;
	while(n>0){
		x = sqrt(n);
		n -= x*x;
		a+=1;
	}
	return a;
}

int main(){
	cout<<minNumSquare(100);
	return 0;
}
