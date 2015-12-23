#ifndef LIST_FUNCTIONS_H_INCLUDED
#define LIST_FUNCTIONS_H_INCLUDED

#include "Node.h"
#include <stdbool.h>

void add_node(Node *added_node, Node **first_node);
void add_first_node(Node *added_node, Node **first_node);
void append_node(Node *added_node, Node **first_node);
bool search_nodes(Node **search_node, Node **first_node);

#include "list_functions.c"

#endif // LIST_FUNCTIONS_H_INCLUDED
