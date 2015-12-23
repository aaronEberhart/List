#include "Node.h"

/****************************************************************************
This is a constructor for making new nodes. It sets the value passed
to it and then sets the next pointer to NULL for later.

Input parameters:   plane, struct Aircraft

Return:             node, *Node
                        current == plane
                        next == NULL
****************************************************************************/
Node* make_node(Aircraft plane)
{
    Node *node;
    node = (Node*)malloc(sizeof(Node));

    //set the node's values
    node->current = plane;
    node->next = NULL;

    return node;
}

