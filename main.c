#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_import.h"

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

int main(int argc, char const *argv[])
{
	
	int i;
	tuple head_n_m;
	adj_nodes *adj_v;
	adj_list adjacency_list;

	head_n_m = getEdgeList("test.txt");
	adjacency_list = makeAdjList(head_n_m);

    int clk = 1;
    int visited[head_n_m.max+1];
    int prev[head_n_m.max+1];
    int post[head_n_m.max+1];
    
    memset(visited,0,sizeof(visited));
    memset(prev,0,sizeof(prev));
    memset(post,0,sizeof(post));

    explore(adjacency_list,0,visited,prev,post,&clk);
    for(i = 0;i <= head_n_m.max; i++)
    {
    	printf("node: %d visited:%d prev:%d post:%d\n",i,visited[i], prev[i], post[i]);
    }


	for(i = 0;i <= head_n_m.max; i++)
	{
		printf("u:%d\n",i);
		adj_v = adjacency_list[i];

		while(adj_v != NULL)
		{
			printf("--v:%d w:%d\n",adj_v -> v,adj_v -> weight);
			adj_v = adj_v -> next;
		}
	}
	
	
	return 0;
}