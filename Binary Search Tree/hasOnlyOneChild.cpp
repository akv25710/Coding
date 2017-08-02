#include<iostream>
using namespace std;

bool hasOnlyOneChild(int ar[], int n){
	int max, min;
	if(ar[n-1]>ar[n-2]){
		max = ar[n-1];
		min = ar[n-2];
	}
	else{
		max = ar[n-2];
		min = ar[n-1];
	}
	for(int i=n-3;i>=0;i--){
		if(ar[i]<min) min = ar[i];
		else if (ar[i]>max) max = ar[i];
		else return 0;
	}
	return 1;
}

int main()
{
    int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (hasOnlyOneChild(pre, size) == true )
        printf("Yes");
    else
        printf("No");
    return 0;
}
