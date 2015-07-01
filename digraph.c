#include<stdio.h>
#include<stdlib.h>
#include "digraph.h"

Digraph initDigraph(int V) {
    Digraph G = malloc(sizeof *G);
    G->V = V;
    G->adj = malloc(V * sizeof(link));
    G->degrees = malloc(V * sizeof(int));
    for (int v = 0; v < V; v++) {
        G->adj[v] = NULL;
        G->degrees[v] = 0;
    }
    return G;
}

void readDigraph(Digraph G) {
    for (int v = 0; v < G->V; v++) {
        scanf("%d", &G->degrees[v]);
        for (int i = 0; i < G->degrees[v]; i++) {
            link edge = malloc(sizeof *edge);
            scanf("%d", &edge->v);
            edge->next = G->adj[v];
            G->adj[v] = edge;
        }
    }
}

void freeDigraph(Digraph G) {
    for (Vertex v = 0; v < G->V; v++) {
        while (G->adj[v] != NULL) {
            link aux = G->adj[v];
            G->adj[v] = G->adj[v]->next;
            free(aux);
        }
    }
    free(G->adj);
    free(G->degrees);
    free(G);
}
