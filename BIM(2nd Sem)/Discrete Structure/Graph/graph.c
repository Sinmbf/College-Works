<<<<<<< HEAD
#include<stdio.h>
#include<conio.h>

struct node {
	int vertex;s
	struct node*next;
};

struct node* createNode(int);
struct Graph {
	int numVertices;
	struct node**adjLists;
=======
// WAP to implement graph using adjacency lists

#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct node {
    int vertex;
    struct node* next;
}; 	

// Graph structure
struct Graph {
    int numVertices;
    struct node** adjLists;
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
};

// Create a node
struct node* createNode(int v) {
<<<<<<< HEAD
	struct node* newNode=malloc(sizeof(struct node));
	newNode->vertex=v;
	newNode->next=NULL;
=======
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
}

// Create a graph
struct Graph* createAGraph(int vertices) {
<<<<<<< HEAD
	struct Graph* graph=malloc(sizeof(struct Graph));
	graph->numVertices=vertices;
	graph->adjLists=malloc(vertices*sizeof(struct node*));
	int i;
	for(i =0; i<vertices; i++) {
		graph->adjLists[i]=NULL;
		return graph;
	}
}

// Add edge+
void addEdge(struct Graph* graph, int s, int d) {
	// Add edge from s to d
	struct node* newNode=createNode(d);
	newNode->next=graph->adjLists[s];
	graph->adjLists[s]=newNode;
	// Add edge from d to s
	newNode=createNode(s);
	newNode->next=graph->adjLists[d];
	graph->adjLists[d]=newNode;
}

// Print the graph
void printGraph(struct Graph* graph){
	int v;
	for(v=0;v<graph->numVertices;v++){
		struct node* temp=graph->adjLists[v];
		printf("\nVertex %d\n:",v);
		while(temp){
			printf("%d ->",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(){
	struct Graph* graph=createAGraph(4);
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,0,3);
	addEdge(graph,1,2);
	printGraph(graph);
	return 0;
=======
	int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
    
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int s, int d) {
    // Add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
    
    // Add edge from d to s
    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
	int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\nVertex %d:\n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Free the allocated memory
void freeGraph(struct Graph* graph) {
	int i;
    for (i = 0; i < graph->numVertices; i++) {
        struct node* temp = graph->adjLists[i];
        while (temp) {
            struct node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    struct Graph* graph = createAGraph(4);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    
    printGraph(graph);
    
    freeGraph(graph); // Free memory
    return 0;
>>>>>>> 0cf41913e859f782c6f8dfd6e72496e4ada4307f
}

