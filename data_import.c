#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_import.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX3(a, b, c) ((a) > (MAX(b, c)) ? (a) : (MAX(b, c)))

tuple getEdgeList(char *fname){
	/*
	input: a pointer to a string fname (file name)
	output: a pointer to the struct object edge_list
	*/
	
	edge_list *head, *curr;
	head = NULL;
	FILE *fp;
    int max = 0;
    tuple head_n_m; 
    char line[128];

    head_n_m.head = NULL;
    head_n_m.max = 0;

	fp = fopen( fname, "r" );

	if( fp == NULL )
	{
    	printf( "can not open the file:%s\n", fname );
    	return head_n_m;
    }
   
    while (fgets(line, sizeof(line), fp))
    {
    	curr = (edge_list *)malloc(sizeof(edge_list));
    	sscanf(line,"%d,%d,%d",&(curr -> e.u),&(curr -> e.v),&(curr -> e.weight));
    	curr -> next = head;
        max = MAX3(max, curr -> e.u, curr -> e.v);
    	head = curr;
    }
    fclose(fp);

    head_n_m.head = head;
    head_n_m.max = max;

    return head_n_m;
}


adj_list * searchNode(adj_list * head, Node t)
{
    /*
    input: a pointer to adj_list object and a target node t
    output: a pointer to adj_list object
    This function searches the target node t in an adjacency list
    and returns its pointer in the list or NULL if not found
    */
    while(head){
        if(head -> u == t)
        {
            return head;
        }
        head = head -> next;
    }
    return NULL;
}

adj_nodes * makeAdjNodes(Node t, int w)
{
    /*
    input: Node t and a weight w
    output: a pointer to adj_nodes object
    This function creates a adj_nodes object to a specific node
    */
    adj_nodes * new_node;
    new_node = (adj_nodes *)malloc(sizeof(adj_nodes));
    new_node -> v = t;
    new_node -> weight = w;
    new_node -> next = NULL;
    return new_node;


}
void addNeighbors(adj_nodes * vs, Node t, int w)
{
    /*
    input: a pointer to adj_nodes object, Node and a weight
    output: None
    This function puts the Node object t to the adj_nodes
    */
    adj_nodes * new_node;

    while((vs -> next) != NULL)
    {
        vs = vs -> next;
    }
    new_node = (adj_nodes *)malloc(sizeof(adj_nodes));
    new_node -> v = t;
    new_node -> weight = w;
    new_node -> next = NULL;
    vs -> next = new_node;
    
    return; 

}

adj_nodes ** makeAdjList(tuple head_n_m)
{
    /*
    input: a pointer to an edge_list object
    output: a pointer (array) of pointers to adj_nodes objects
    This function creates an adjacency list  for a given edge list
    */
    edge_list * head;
    int max;
    head = head_n_m.head;
    max = head_n_m.max;
    adj_nodes **adjacency_list = (adj_nodes **)malloc(sizeof(adj_nodes *)*(max+1));
    memset(adjacency_list,0,sizeof(adjacency_list[0])*(max+1));

    while(head)
    {
        if(adjacency_list[head -> e.u] != 0)
        {
            addNeighbors(adjacency_list[head -> e.u],head -> e.v, head -> e.weight);
        }
        else
        {
            adjacency_list[head -> e.u] = makeAdjNodes(head -> e.v, head -> e.weight);
        }
        head = head -> next;
        
    }
    
    return adjacency_list;

}