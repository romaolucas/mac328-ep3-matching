#ifndef DIGRAPH_H_INCLUDED
#define DIGRAPH_H_INCLUDED
#define Vertex int

typedef struct node *link;

struct node {
    Vertex v;
    link next;
};

struct digraph {
    int V;
    link *adj;
    int *degrees;
};

typedef struct digraph *Digraph;

Digraph initDigraph(int V);

void readDigraph(Digraph G);

void printDigraph(Digraph G);

void freeDigraph(Digraph G);

#endif
