#include<stdio.h>
#include<stdlib.h>
#include "data_import.h"


int main(int argc, char const *argv[])
{
	
	edge_list *head;
	adj_nodes * adj_v;

	head = getEdgeList("test.txt");
	adj_list *adj_head;
	adj_head = makeAdjList(head);
	while(adj_head)
	{
		printf("in main, u:%d\n",adj_head -> u);

		adj_v = adj_head -> vs;

		while(adj_v != NULL)
		{
			printf("v:%d w:%d\n",adj_v -> v,adj_v -> weight);
			adj_v = adj_v -> next;
		}
		adj_head = adj_head -> next;
	}

	return 0;
}