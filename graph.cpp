#include <stdio.h>
#include <stdlib.h>


#define N 6

// Node Structure
struct Node {
	int dest;
	struct Node *next;
};

// Graph Structure
struct Graph {
	struct Node* head[N];
};

// Edge Structure
struct Edge {
	int src;
	int dest;
};

void printPath(struct Graph *graph)
{

}
void printList(Node *head,int index) {
	if (!head) {
		printf("\n");
		return;
	}
	if (head) {
		printf("(%d----->%d)    ", index, head->dest);
		printList(head->next, index);
	}
}
void printGraph(struct Graph *graph)
{
	for (int i = 0; i < N; i++)
		printList(graph->head[i], i);
	
}
struct Graph *createGraph(struct Edge edges[], int n) {
	Graph *graph = new Graph;
	for (int i = 0; i < N; i++)
	{
		graph->head[i] = NULL;
	}
	for (int i = 0; i < n; i++)
	{

		if (graph->head[edges[i].src] == NULL)
		{
			graph->head[edges[i].src] = new Node;
			graph->head[edges[i].src]->dest = edges[i].dest;
			graph->head[edges[i].src]->next = NULL;
		}
		else
		{
			while (graph->head[edges[i].src]->next != NULL)
			{
				graph->head[edges[i].src] = graph->head[edges[i].src]->next;
			}
			graph->head[edges[i].src]->next = new Node;
			graph->head[edges[i].src]->next->dest = edges[i].dest;
			graph->head[edges[i].src]->next->next = NULL;
		}
	}
	return graph;
}


int main() {
	struct Edge edges[] = {
		{ 0,1 },{ 1,2 },{ 2,0 },{ 3,2 },{ 4,5 },{4,3}
	};
	int n = sizeof(edges) / sizeof(edges[0]);

	struct Graph *graph = createGraph(edges, n);

	printGraph(graph);

	return 0;
};