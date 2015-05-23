#include<stdio.h>
#include<stdlib.h>
#include "data_import.h"

edge_list * getEdgeList(char *fname){
	/*
	input: a pointer to a string fname (file name)
	output: a pointer to the struct object edge_list
	*/
	
	edge_list *head, *curr;
	head = NULL;
	FILE *fp;

	fp = fopen( fname, "r" );

	if( fp == NULL )
	{
    	printf( "can not open the file:%s\n", fname );
    	return NULL;
    }

   
    char line[128];
    while (fgets(line, sizeof(line), fp))
    {
    	curr = (edge_list *)malloc(sizeof(edge_list));
    	sscanf(line,"%d,%d,%d",&(curr -> e.u),&(curr -> e.v),&(curr -> e.weight));
    	curr -> next = head;
    	head = curr;

    }
    fclose(fp);
    return head;
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

adj_list * makeAdjList(edge_list * head)
{
    /*
    input: a pointer to an edge_list object
    output: a pointer to an adj_list object
    This function creates an adjacency list  for a given edge list
    */
    adj_list * root, * adj_p, * p;
    root = NULL;

    while(head)
    {
        if( (adj_p = searchNode(root,head -> e.u)) != NULL)
        {
            addNeighbors(adj_p -> vs,head -> e.v, head -> e.weight);
        }
        else
        {

            p = (adj_list *)malloc(sizeof(adj_list));
            p -> u = head -> e.u;
            p -> vs = makeAdjNodes(head -> e.v, head -> e.weight);
            p -> next = root;
            root = p;
        }

        head = head -> next;
        
    }
    return root;

}