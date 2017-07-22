#include<iostream>
#define ROW 4
#define COL 5

using namespace std;

int kadane(int ar[],int *start, int *finish, int n){
	int sum=0,maxSum=INT_MIN,i;
	int local_start=0;
	
	for(i=0;i<n;i++){
		sum+=ar[i];
		if(sum<0){
			sum=0;
			local_start=i+1;
		}
		else if(sum > maxSum){
			maxSum=sum;
			*start = local_start;
			*finish = i;
		}
	}
	return maxSum;
}

int maxSumRectangle(int M[][COL]){
	int maxSum=INT_MIN;
	int finalLeft,finalRight,finalTop,finalBottom;
	int left,right,i;
	int temp[ROW],sum,start,finish;
	
	for(left=0;left<COL;left++){
		for(i=0;i<ROW;i++) temp[i]=0;
		for(right=left;right<COL;right++){
			for(i=0;i<ROW;i++) temp[i]+=M[i][right];
			sum = kadane(temp,&start,&finish,ROW);
			if(sum>maxSum){
				maxSum = sum;
				finalTop=start;
				finalBottom=finish;
				finalLeft = left;
				finalRight = right;
			}
		}
	}
	for(i=finalTop;i<=finalBottom;i++){
		for(int j=finalLeft;j<=finalRight;j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	return maxSum;
}

int main()
{
	int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
 
   cout<<maxSumRectangle(M);
 
    return 0;
}
