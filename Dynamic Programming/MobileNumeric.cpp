#include<iostream>
#include<cmath>
using namespace std;

int  getcount(int n){
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=1;
	int b[10];
	for(int i=1;i<n;i++){
		b[0]=a[0]+a[8];
		b[1]=a[1]+a[2]+a[4];
		b[2]=a[2]+a[1]+a[5]+a[3];
		b[3]=a[3]+a[2]+a[6];
		b[4]=a[4]+a[1]+a[5]+a[7];
		b[5]=a[5]+a[2]+a[6]+a[8]+a[4];
		b[6]=a[6]+a[3]+a[5]+a[9];
		b[7]=a[7]+a[4]+a[8];
		b[8]=a[8]+a[5]+a[7]+a[9]+a[0];
		b[9]=a[9]+a[8]+a[6];
		for(int j=0;j<10;j++)
			a[j]=b[j];
	}

	int count=0;
	for(int i=0;i<10;i++)
		count=count+a[i];
	return count;
}

int main(){
	for(int i=1;i<10;i++){
	cout<<"for n="<<i<<" count is "<<getcount(i)<<endl;
	}	
	return 0;
}
