#ifndef _DFS_H_
#define _DFS_H_

typedef struct DFS_result dfs_result;
struct DFS_result
{
	int *prev;
	int *post;
};

void explore(adj_list G, Node v, int visited[], int prev[], int post[], int *clk);
void DFS(adj_list G, int max);

#endif