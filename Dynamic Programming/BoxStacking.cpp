#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct Box{
	int l,b,h;
};

int compare (const void *a, const void * b)
{
    return ( (*(Box *)b).l * (*(Box *)b).b ) -
           ( (*(Box *)a).l * (*(Box *)a).b );
}

int maxBoxHeight(Box ar[], int n){
	int index=0;
	int i,j,q=0;
	Box rot[3*n];
	
	for(i=0;i<n;i++){
		rot[index++] = ar[i];
		
		rot[index].h = ar[i].b;
		rot[index].l = max(ar[i].l,ar[i].h);
		rot[index].b = min(ar[i].l,ar[i].h);
		index++;
		
		rot[index].h = ar[i].l;
		rot[index].l = max(ar[i].b,ar[i].h);
		rot[index].b = min(ar[i].b,ar[i].h);
		index++;		
	}
	
	n = 3*n;
	sort(rot,rot+n,compare);
	
	int msh[3*n];
	
	for(i=0;i<n;i++)
		msh[i] = rot[i].h;
		
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(rot[i].l>rot[j].l && rot[i].b>rot[j].b)
				msh[i] = max(msh[i],msh[j]+ar[i].h);
				
	for(i=0;i<n;i++)
		if(msh[i]>q) q=msh[i];
		
	return q;	
}

int main(){
	
	Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<maxBoxHeight(arr,n);	
	
	return 0;
}
