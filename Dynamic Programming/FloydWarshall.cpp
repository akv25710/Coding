#include<iostream>

using namespace std;

int main(){
	 int V=4;
	 int INF = 99999;
	 int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
	
	int i,j,k;
	int dist[V][V];
	
	for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
            
    for(k=0;k<V;k++)
    	for(i=0;i<V;i++)
    		for(j=0;j<V;j++)
    			if(dist[i][k]+dist[k][j] < dist[i][j])  dist[i][j] = dist[i][k]+dist[k][j];
    			
	for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF";
            else
                cout<<dist[i][j];
        }
        cout<<" \n";
    }
	
	return 0;
}
