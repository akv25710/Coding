#include<iostream>

using namespace std;

int sumOfDigits(int n){
	int dp[n+1],result=1;
	dp[0]=0,dp[1]=1;
	for(int i=2;i<=n;i++){
		if(i%10==0) dp[i]=dp[i/10];
		else
			dp[i] = dp[i-1]+1;
		result+=dp[i];
	}
	return result;
}



int main()
{
    int n = 328;
    cout << "Sum of digits in numbers from 1 to " << n << " is "
         << endl<<sumOfDigits(n);
    return 0;
}
