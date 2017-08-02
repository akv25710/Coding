#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void printPermutation(string str, int start, int end, map<string, int> &mymap)
{
	if(start == end)
	{
		mymap[str]++;
	}
	for(int i = start; i <= end; i++)
	{
		swap(&str[i],&str[start]);
		printPermutation(str, start+1, end, mymap);
		swap(&str[i],&str[start]);
	}
}

int print(string str)
{
	map<string, int> mymap;
	printPermutation(str, 0, str.length()-1, mymap);
	map<string, int>:: iterator i;
	for(i = mymap.begin(); i != mymap.end();i++)
	{
		while(i->second--)
		{
			cout<<i->first<<" ";
		}
	}
}
int main()
{
	print("abbc");
}
