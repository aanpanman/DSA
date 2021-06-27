#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX = 100

struct node 
{
  char vt;
  struct node* next;
};

struct Graph 
{
  int nv;
  struct node** adjnode;
  int* visited;
};

struct node* createNode(char v)
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vt = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int v) 
{
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->nv = v;

  graph->adjnode = malloc(v * sizeof(struct node*));

  int i;
  for (i = 0; i < v; i++)
    graph->adjnode[i] = NULL;

  return graph;
}

void addEdge(struct Graph* graph, char s, char d) 
{
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adjnode[s];
  graph->adjnode[s] = newNode;
}

void adjList(struct Graph* graph) 
{
  int v;
  for (v = 0; v < graph->nv; v++) 
  {
    struct node* temp = graph->adjnode[v];
    printf("\n%d\n: ", v);
    while (temp) 
    {
      printf("%d ", temp->vt);
      temp = temp->next;
    }
    printf("\n");
  }
}

void sortAlphabets(char n[])
{
    char temp;
    for (int i = 0; i < strlen(n)-1; i++) 
    {
        for (int j = i+1; j < strlen(n); j++) 
        {
            if (n[i] > n[j]) 
            {
                temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
}

/*void DFS(struct Graph* graph, char vertex) 
{
    struct node* adjList = graph->adjnode[vertex];
    struct node* temp = adjList;

    graph->visited[0] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) 
    {
      int connectedVertex = temp->vt;

      if (graph->visited[connectedVertex] == 0) 
        DFS(graph, connectedVertex);
      
      temp = temp->next;
    }
}*/

int main() 
{
    char name[100];
    fgets(name, sizeof(name), stdin);
    sortAlphabets(name);
    printf("sorted: \n%s", name);

   struct Graph* graph = createAGraph(4);
    for (int i=0; i<strlen(name); i++)
    {
        addEdge(graph, name[i], name[i+1]);
    }
    adjList(graph);

    DFS(graph, "a");
    
    return 0;
}