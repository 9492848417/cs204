#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 10000000 

// Solves the all-pairs shortest path  
// problem using Floyd Warshall algorithm  
void floydWarshall(int graph[][V],int k[][V])
{
	int dist[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<V;k++)
	{
	// Pick all vertices as source one by one  
		for(int i=0;i<V; i++)
	    {

            // Pick all vertices as destination for the  
            // above picked source
			for(int j=0;j<V;j++)
			{
		// If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
				if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
				
			}
		}
	}
// Print the shortest distance matrix 
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			k[i][j]=dist[i][j];
		}
	}
}
int main()
{
	 int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
     int k[V][V];
    floydWarshall(graph,k); 
    for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			 if (k[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<k[i][j]<<"     ";  
		}
		cout<<endl;
	}

    return 0;  
}
