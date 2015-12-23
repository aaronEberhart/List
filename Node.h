#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Aircraft.h"

typedef struct Node{
    Aircraft current;
    struct Node *next;
}Node;

Node* make_node(Aircraft plane);

#include "Node.c"

#endif // NODE_H_INCLUDED
