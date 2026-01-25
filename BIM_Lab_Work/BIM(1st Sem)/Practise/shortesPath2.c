#include<stdio.h>
#include<stdlib.h>

// ******Structures******
struct vertex{
    int id;
    struct adjacentVertex{
        int id;
        int weight;
    }adjVertex[50];
}vertices[50];

// ******Function Prototype******
void fillArray(int [10][10],int);
int determineValidityOfGraph(int [10][10],int);
void determineVertexConnectivity(struct vertex* v,int [10][10],int);
int minimum(int,int);

// ******Main Program******
int main(){
    int numOfVertices,i,j,adjacencyMatrix[10][10];
    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d",&numOfVertices);
    // Input values for the matrix
    printf("Enter %d values for adjacency matrix[0 or 1]: ",numOfVertices*numOfVertices);
    fillArray(adjacencyMatrix,numOfVertices);
    // Determine graph validity
    int isValid=determineValidityOfGraph(adjacencyMatrix,numOfVertices);
    // Determine vertex connectivity
    if(isValid){
        determineVertexConnectivity(vertices,adjacencyMatrix,numOfVertices);
    }
    return 0;
}

// ******Function Definition******

// Function to fill array
void fillArray(int adjacencyMatrix[10][10],int numOfVertices){
    int i,j;
    // Take values for matrix
    for(i=0;i<numOfVertices;i++){
        for(j=0;j<numOfVertices;j++){
            scanf("%d",&adjacencyMatrix[i][j]);
            while(adjacencyMatrix[i][j]>1 || adjacencyMatrix[i][j]<0){
                printf("Invalid number! Please enter either 0 or 1\n");
                scanf("%d",&adjacencyMatrix[i][j]);
            } 
        }
    }
}

// Function to determine validity of graph
int determineValidityOfGraph(int adjacencyMatrix[10][10],int numOfVertices){
    int i,j,k,index1,index2;
    for(i=0;i<numOfVertices;i++){
        for(j=0;j<numOfVertices;j++){
            if(adjacencyMatrix[i][j]==1){
                if(adjacencyMatrix[j][i]!=1){
                    printf("Invalid graph");
                    exit(1);
                }  
            }
        }
    }
    return 1;
}

// Function to determine vertex connectivity
void determineVertexConnectivity(struct vertex* v,int adjacencyMatrix[10][10],int numOfVertices){
    int i,j,k,v1,v2;
    for(i=0;i<numOfVertices;i++){
        for(j=0;j<numOfVertices;j++){
            if(adjacencyMatrix[i][j]==1 && adjacencyMatrix[j][i]==1){
                (v+j)->id=i+1;
                (v+j)->adjVertex[j].id=j+1;
                printf("Vertex %d connected to vertex %d\n",(v+j)->id,(v+j)->adjVertex[j].id); 
                if((v+i)->id)
                printf("What is the weight of their edges? ");
                scanf("%d",&(v+j)->adjVertex[j].weight);
            }
        }
    }
}

int minimum(int n1,int n2){
    return (n1<n2)?n1:n2;
}