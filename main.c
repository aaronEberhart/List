/****************************************************************************
Author: Aaron Eberhart
Project: [6]
Class: CEG 2170-01
Lab Section: 05
File Name: [eberhart_project06]
Instructor: Starkey
Due Date: [12/05/2015]

Overview:   This program is designed to implement a linked-list to store
            data for aircrafts. The main menu allows the user to import
            the database, append a new aircraft from input information,
            print a single aircraft, print all aircraft, or exit.

Input Parameters:   FILE input.txt, aircraft data
                    Aircraft[New]
                        name, char*
                        wingspan, double
                        length, double
                        height, double
                        width, double
                        cost, double
                    menu choice, char

Output Parameters:  Aircraft[Single, Database]
                        name, char*
                        wingspan, double
                        length, double
                        height, double
                        width, double
                        cost, double

Known Issues:   N/A
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "main_functions.h"

int main(void)
{

    char choice;
    bool database_accessed = false, menu_loop = true;
    Node *first_node = NULL;

    while(menu_loop)//begin menu loop
    {
        //call main menu function and assign returned choice
        choice = show_menu();

        //call function to perform menu choice, and assign the boolean corresponding to database access
        database_accessed = perform_menu_choice(choice, &first_node, database_accessed);

    }

    return (0);
}
