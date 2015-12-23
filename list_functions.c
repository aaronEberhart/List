#include "list_functions.h"

/***************************************************************************
This function combines the add_first and append functions with a conditional
statement that determines which should be called when adding any node.
It will return the results of these functions.

Input parameters:   added node, *Node
                    first node, **Node
                    last node, **Node

Return: N/A
****************************************************************************/
void add_node(Node *added_node, Node **first_node)
{
    if(*first_node == NULL)//if the first node has not been set, set it to the current node
    {
        add_first_node(added_node, first_node);
    }
    else//otherwise append a new node
    {
        append_node(added_node, first_node);
    }
}

/****************************************************************************
This function starts the linked-list by adding the first node and setting
the last node equal to it.

Input parameters:   added node, *Node
                    first node, **Node
                    last node, **Node

Return:             first node, *Node
****************************************************************************/
void add_first_node(Node *added_node, Node **first_node)
{
    //set the address of the first and last nodes to the new node
    *first_node = added_node;

}

/****************************************************************************
This function appends a new node to the end of the linked-list and sets the
address of the added node to the last node variable.

Input parameters:   added node, *Node
                    last node, **Node

Return:             last node, *Node
****************************************************************************/
void append_node(Node *added_node, Node **first_node)
{
	Node *i_node;
	i_node = *first_node;

	while(i_node != NULL)
	{

		if(i_node->next == NULL)
		{
           //set the new node to the address of the last node next pointer
          //then set the last node to the new node
          i_node->next = added_node;
          i_node = added_node;
          break;
		}
        else
            i_node = i_node->next;
	}

}

/****************************************************************************
This function searches through the list to see if a match is found to the
node name passed to it. If a match is found, the passed node pointers are set to
the values of the node iterator and the boolean found is set to true.
Otherwise if a match is not found, the boolean stays false.

Input parameters:   search node, **Node
                    first node, **Node

Return:             found, boolean
****************************************************************************/
bool search_nodes(Node **search_node, Node **first_node)
{
    bool found = false;
    Node *i_node;

    //initialize iterated node to first node
    i_node = *first_node;

    while(i_node != NULL)//while the iterated node is not NULL
    {
        if(strcmp((*search_node)->current.name, i_node->current.name) == 0)//if the name of the aircraft is the same as the iterated struct
        {
            (*search_node)->current = i_node->current;//set the node pointers and boolean to true then break the loop
            (*search_node)->next = i_node->next;
            found = true;
            break;
        }
        else//otherwise proceed to the next node
            i_node = i_node->next;
    }

    return found;
}
