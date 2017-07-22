#include<bits/stdc++.h>
using namespace std;

struct interval{
	int start,end;
};

bool compare(interval a, interval b){
	return a.start<b.start;
}

void mergeInterval(interval ar[], int n){
	sort(ar,ar+n,compare);
	stack<interval> S;
	S.push(ar[0]);
	for(int i=1;i<n;i++){
		interval top = S.top();
		if(top.end > ar[i].start){
			cout<< " ";
		}
	}
 }

void mergedIntervals(interval ar[], int n){
	sort(ar,ar+n,compare);
	int i=1,index=0,current;
	while(i<n){
		int terminal = ar[i-1].end;
		current = i-1;
		while(terminal > ar[i].start){
			terminal = max(terminal, ar[i].end);
			i++;
		}
		ar[index++] = {ar[current].start, terminal};
		i++;
	}
	for(i=0;i<index;i++) cout<<ar[i].start<<" "<<ar[i].end<<endl;
	
}

int main()
{
    interval arr[] =   {{1,3}, {2,4}, {5,7}, {6,8} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergedIntervals(arr, n);
    return 0;
}
