#include<iostream>
using namespace std;

struct Stock{
	int buy,sell;
};

void stockBuySell(int ar[], int n){
	int i=0,count=0;
	Stock sol[n];
	while(i<n-1){
		while(i<n-1 && ar[i]>=ar[i+1]) i++;
		if(i==n-1) break;
		sol[count].buy = i++;
		
		while(i<n && ar[i]<ar[i+1]) i++;
		sol[count].sell = i;
		count++;
	}
	 if (count == 0)
        printf("There is no day when buying the stock will make profit\n");
    else
    {
       for (int i = 0; i < count; i++)
          printf("Buy on day: %d\t Sell on day: %d\n", sol[i].buy, sol[i].sell);
    }
 	
}

int main()
{
    
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);
    stockBuySell(price, n);
 
    return 0;
}
