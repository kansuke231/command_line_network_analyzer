#ifndef _DATA_IMPORT_H_
#define _DATA_IMPORT_H_

typedef unsigned int Node;

typedef struct Edge
{
	Node u; /* depending on the number of vertices */
	Node v; /* one may want to change the type int to unsigned long*/ 
	int weight;
} edge;

typedef struct EdgeList edge_list;
struct EdgeList
{
	edge e;
	edge_list * next;
};

typedef struct AdjacentNodes adj_nodes;
struct AdjacentNodes
{
	Node v;
	int weight;
	adj_nodes *next;
};

typedef struct AdjacencyList adj_list;
struct AdjacencyList
{
	Node u;
	adj_nodes *vs;
	adj_list *next;
};

edge_list * getEdgeList(char *fname);
adj_list * searchNode(adj_list * head, Node t);
adj_nodes * makeAdjNodes(Node t, int w);
void addNeighbors(adj_nodes * vs, Node t, int w);
adj_list * makeAdjList(edge_list * head);

#endif