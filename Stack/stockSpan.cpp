#include<stack>
#include<iostream>

using namespace std;

void stockSpan(int price[], int n, int Span[]){
	stack<int> S;
	S.push(0);
	Span[0]=1;
	for(int i=1;i<n;i++){
		while(!S.empty() && price[S.top()]<=price[i])
			S.pop();
		Span[i]=(S.empty()) ?  i+1 : i-S.top();
		S.push(i);
	}
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
}
 
// Driver program to test above function
int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
 
    // Fill the span values in array S[]
    stockSpan(price, n, S);
 
    // print the calculated span values
    printArray(S, n);
 
    return 0;
}
