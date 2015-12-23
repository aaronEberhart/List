#ifndef MAIN_FUNCTIONS_H_INCLUDED
#define MAIN_FUNCTIONS_H_INCLUDED

#define MAX_INPUT_LENGTH 50
#define FILENAME "input.txt"
#include "list_functions.h"

char show_menu();
char get_menu_choice();
bool perform_menu_choice(char choice, Node **first_node, bool database_accessed);
bool load_database(Node **first_node);
void insert_new_aircraft(Node **first_node);
void print_one_aircraft(Node **first_node);
void print_database(Node **first_node);
void exit_program(Node **first_node);

#include "main_functions.c"

#endif // MAIN_FUNCTIONS_H_INCLUDED
