#include<stdio.h>
#include<stdlib.h>
#include "data_import.h"
#include "DFS.h"


int main(int argc, char const *argv[])
{
	
	int i;
	tuple head_n_m;
	adj_nodes *adj_v;
	adj_list adjacency_list;
	dfs_result *result;

	head_n_m = getEdgeList("test.txt");
	adjacency_list = makeAdjList(head_n_m);

    DFS(adjacency_list,head_n_m.max);

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