#include<iostream>
#include<stack>

using namespace std;

int getMaxArea(int hist[], int n){
	stack<int> S;
	int i=0,top;
	int max_area = 0, area_with_top;
	while(i<n){
		if(S.empty() || hist[S.top()] <= hist[i])
			S.push(i++);
		else{
			top = S.top();
			S.pop();
			area_with_top = hist[top]*( S.empty() ? i: i-S.top()-1 );
			max_area = max(max_area, area_with_top);
		}
	}
	while(!S.empty()){
		top = S.top();
			S.pop();
			area_with_top = hist[top]*( S.empty() ? i: i-S.top()-1 );
			max_area = max(max_area, area_with_top);
	}
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
