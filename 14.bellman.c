#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
	int u;	
	int v;	
	int w;	};


struct Graph {
	int V;
	int E;	
	struct Edge *edge;
};

void bellmanford(struct Graph *g, int source);
void printArr(int arr[], int size);

int main(void) {
	
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	printf("ENTER NO VERIVES: ");
	scanf("%d",&g->V);
	printf("ENTER NO edges: ");
	scanf("%d",&g->E);
	int tv=g->V;
	int te=g->E;	
	
	
	g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));
	
	
        for (int j = 0; j < te; j++)
        {
	    printf("ENTER SOURSE DESTINATION & weight OF EDGE: %d",j);
            scanf("%d",&g->edge[j].u);
            scanf("%d",&g->edge[j].v);
            scanf("%d",&g->edge[j].w);
            
        }
    
	
	bellmanford(g, 0);		
	
	return 0;
}


void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 

void bellmanford(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
 
    
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
 
   
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u1 = graph->edge[j].u;
            int v1 = graph->edge[j].v;
            int weight = graph->edge[j].w;
            if (dist[u1] != INT_MAX && dist[u1] + weight < dist[v1])
                dist[v1] = dist[u1] + weight;
        }
    }
 
    
    for (int i = 0; i < E; i++)
    {
        int u1 = graph->edge[i].u;
        int v1 = graph->edge[i].v;
        int weight = graph->edge[i].w;
        if (dist[u1] != INT_MAX && dist[u1] + weight < dist[v1])
            printf("Graph contains negative weight cycle");
    }
 
    printArr(dist, V);
 
    return;
}

