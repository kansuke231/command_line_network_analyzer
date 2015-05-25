#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_import.h"
#include "DFS.h"


void explore(adj_list G, Node v, int visited[], int prev[], int post[], int *clk)
{

	adj_nodes *adj_v;
	adj_v = G[v];

	visited[v] = 1;
	prev[v] = *clk;
	*clk = *clk +1;

	while(adj_v != NULL)
	{
		if(visited[adj_v -> v] == 0)
		{
			explore(G,adj_v -> v,visited,prev,post,clk);
		}
		adj_v = adj_v -> next;
	}

	post[v] = *clk;
	*clk = *clk +1;
	return;
}

void DFS(adj_list G, int max)
{
	dfs_result *result = (dfs_result *)malloc(sizeof(dfs_result));
	int clk = 1;
    int visited[max+1];
    int prev[max+1];
    int post[max+1];
    
    memset(visited,0,sizeof(visited));
    memset(prev,0,sizeof(prev));
    memset(post,0,sizeof(post));

    for (int i = 0; i <= max; ++i)
    {
    	if(visited[i] == 0)
    	{
    		explore(G,0,visited,prev,post,&clk);
    	}
    }
    result -> prev = prev;
    result -> post = post;
    for(int j = 0; j <= max; j++)
    {
    	printf("prev:%d\n",result -> prev[j]);
    	printf("post:%d\n",result -> post[j]);
    }
    return ;// this is not safe (i.e. result will be different at the other scope)

}









