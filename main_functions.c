#include "main_functions.h"

/****************************************************************************
This function displays the main menu. It calls a sub-function to get input
and then returns the input if it is valid, else looping back to get input again.

Input parameters:   N/A

Return:             choice, char
****************************************************************************/
char show_menu()
{
    char choice;
    bool invald_menu_choice = true;

    //loop until a valid menu option is selected
    while(invald_menu_choice)
    {
        //display menu choices
        printf("Aircraft Database Utility:\n\n"
                "\tL - Load Database\n"
                "\tI - Insert New Aircraft\n"
                "\tA - Display Single Aircraft\n"
                "\tP - Display Entire Database\n"
                "\tX - Exit\n\n"
                "Input Choice: ");

        //call function to get choice and return it if it is valid
        choice = get_menu_choice();

        if(choice != 'F')
            invald_menu_choice = false;
        else//if menu choice is not valid, show error and repeat
            printf("\n\tInvalid Input. Try again.\n\n");
    }

    return choice;
}

/****************************************************************************
This function gets a line of input and tests to see if it is a valid char
choice. If it s valid, thn it is returned. If not, then a 'F' is returned
to signify bad input.

Input parameters:   N/A

Return:             choice (or 'F'), char
****************************************************************************/
char get_menu_choice()
{
    char choice, test;
    char input[MAX_INPUT_LENGTH];

    //get user input and scan for a valid choice
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sscanf(input, "%c%c", &choice, &test);

    //if the user inputs more than 1 character, return F to indicate incorrect input
    if(test != '\n')
        return 'F';
    else
    {
        //input switch
        switch(choice)
        {
            case 'L'://valid choices
            case 'l':
            case 'I':
            case 'i':
            case 'A':
            case 'a':
            case 'P':
            case 'p':
            case 'X':
            case 'x':
                return choice;
            default://invalid choice
                return 'F';
        }
    }
}

/****************************************************************************
This function uses a switch to call the function specified by the user
choice. The boolean database_accessed determines which sub-functions
can be called based on whether or not the

Input parameters:   choice, char
                    first node, Node **
                    last node, Node **
                    database accessed, boolean

Return:             database accessed, boolean
****************************************************************************/
bool perform_menu_choice(char choice, Node **first_node, bool database_accessed)
{
    switch(choice)//menu switch
    {
        case 'L'://database option, returns true on success
        case 'l':
            if(!database_accessed)
            {
                database_accessed = load_database(first_node);
                break;
            }
            else
            {
                printf("\n\tDatabase has already been loaded.\n\n");
                break;
            }
        case 'I'://insert option, only valid if database has been accessed
        case 'i':
            if(!database_accessed)
            {
                printf("\n\tPlease load database first.\n\n");
                break;
            }
            else
            {
                insert_new_aircraft(first_node);
                break;
            }
        case 'A'://display one aircraft option, only valid if database has been accessed
        case 'a':
            if(!database_accessed)
            {
                printf("\n\tPlease load database first.\n\n");
                break;
            }
            else
            {
                print_one_aircraft(first_node);
                break;
            }
        case 'P'://display database option, only valid if database has been accessed
        case 'p':
            if(!database_accessed)
            {
                printf("\n\tPlease load database first.\n\n");
                break;
            }
            else
            {
                print_database(first_node);
                break;
            }
        case 'X'://exit program option
        case 'x':
            if(!database_accessed)//if the database hasn't been loaded, simply exit
            {
                printf("\n\tExiting...\n\n");
                exit(0);
            }
            else//call function to free nodes from database and then exit
            {
                exit_program(first_node);
                break;
            }
    }

    //return the boolean corresponding to database access
    return database_accessed;
}

/****************************************************************************
This function reads a file of aircraft data and stores the data read in
a linked-list. The function uses the number of planes, the first entry
in the file, to loop through the file contents and call sub-functions
that make aircraft structs and add them to the list. It returns true
if it ends sucessfully, so that the calling function can identify whether
it has been run or not.

Input parameters:   first node, Node**
                    last node, Node**

Return:             true, boolean
****************************************************************************/
bool load_database(Node **first_node)
{
    FILE *file_p;
    char input[MAX_INPUT_LENGTH], name[MAX_NAME_LENGTH];
    double wingspan, length, height, width, cost;
    int number_planes, i;

    //open file
    file_p = fopen(FILENAME, "r");

    //if file is empty or DNE
    if(file_p == NULL)
    {
        printf("\nFile Error.\n\n");
        exit(-1);
    }

    //read the first line to find the number of entries
    fscanf(file_p, "%d", &number_planes);

    //read each line from file and use to make a new entry in list
    for(i = 0; i < number_planes; i++)
    {
        fscanf(file_p, "%s\t%lf\t%lf\t%lf\t%lf\t%lf", name, &wingspan, &length, &height, &width, &cost);

        add_node(make_node(make_aircraft(name, wingspan, length, height, width, cost)), first_node);
    }

    //print notice of successful read
    printf("\n\tRead %d entries from file.\n\n", number_planes);

    //close file
    fclose(file_p);

    return true;
}

/****************************************************************************
This function appends a new aircraft to the end of the linked-list. Each
variable in the aircraft struct is prompted for. When all fields have been
completed a new aircraft node appended to the end of the list with the
append node function.

Input parameters:   last node, **Node

Return: N/A
****************************************************************************/
void insert_new_aircraft(Node **first_node)
{
    int i;
    char input[MAX_INPUT_LENGTH], name[MAX_NAME_LENGTH];
    double wingspan, length, height, width, cost;

    printf("\nEnter the name of the Aircraft: ");//get name
    fgets(name, MAX_INPUT_LENGTH, stdin);

    for(i = 0; i < MAX_NAME_LENGTH; i++)//remove any newlines from name input
    {
        if(name[i] == '\n')
            name[i] = '\0';
    }

    printf("\nEnter the wingspan of the Aircraft: ");//get wingspan
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sscanf(input, "%lf", &wingspan);

    printf("\nEnter the length of the Aircraft: ");//get length
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sscanf(input, "%lf", &length);

    printf("\nEnter the height of the Aircraft: ");//get height
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sscanf(input, "%lf", &height);

    printf("\nEnter the width of the Aircraft: ");//get width
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sscanf(input, "%lf", &width);

    printf("\nEnter the cost of the Aircraft: ");//get cost
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sscanf(input, "%lf", &cost);

    //call function to make and append node with entered values
    append_node(make_node(make_aircraft(name, wingspan, length, height, width, cost)), first_node);

    printf("\n");
}

/****************************************************************************
Thi function prints one aircraft from the database. It gets user input for
the name of the plane to print, and then stores it in a temporary node.
This node is sent to the search node function. If a node is found, then
it is printed and freed. Otherwise an error is displayed.

Input parameters:   first node, **Node

Return: N/A
****************************************************************************/
void print_one_aircraft(Node **first_node)
{
    int i;
    Node *plane;
    plane = (Node*)malloc(sizeof(Node));

    printf("\nEnter the name of the Aircraft to display data: ");//get input for aircraft to display
    fgets(plane->current.name, MAX_NAME_LENGTH, stdin);

    for(i = 0; i < MAX_NAME_LENGTH; i++)//remove any newlines from input
    {
        if(plane->current.name[i] == '\n')
            plane->current.name[i] = '\0';
    }

    if(search_nodes(&plane, first_node))//if the search returns true, display values
    {
        printf("\nName:\t\t%-15s\nWingspan:\t%-15.2f\nLength:\t\t%-15.2f\nHeight:\t\t%-15.2f\nWidth:\t\t%-15.2f\n",
            plane->current.name, plane->current.wingspan, plane->current.length, plane->current.height, plane->current.width);

        if(plane->current.cost != 0.0)
        {
            printf("Cost:\t\t$%-15.2f\n\n", plane->current.cost);
        }
        else
        {
            printf("Cost:\t\t%-15s\n\n", "CLASSIFIED");
        }
    }
    else//otherwise display not found error
        printf("\n\t%s not found in database.\n\n", plane->current.name);

    free(plane);


}

/****************************************************************************
This function loops through the database and prints all entries until it
reaches NULL and ends.

Input parameters:   first node, **Node

Return: N/A
****************************************************************************/
void print_database(Node **first_node)
{
    Node *i_node;
    i_node = (Node*)malloc(sizeof(Node));

    //initialize the iterated node to the head
    i_node = *first_node;

    while(i_node != NULL)//print every entry until the iterated node reaches NULL
    {
        printf("\nName:\t\t%-10s\nWingspan:\t%-15.2f\nLength:\t\t%-15.2f\nHeight:\t\t%-10.2f\nWidth:\t\t%-15.2f\n",
            i_node->current.name, i_node->current.wingspan, i_node->current.length, i_node->current.height, i_node->current.width, i_node->current.cost);

        if(i_node->current.cost != 0.0)
        {
            printf("Cost:\t\t$%-15.2f\n\n", i_node->current.cost);
        }
        else
        {
            printf("Cost:\t\t%-15s\n\n", "CLASSIFIED");
        }

        //proceed to the next node
        i_node = i_node->next;
    }

}

/****************************************************************************
This function loops through the linked-list and clears all memory allocated
and then exits.

Input parameters:   first node, **Node
                    last node, **Node

Return: N/A
****************************************************************************/
void exit_program(Node **first_node)
{
    Node *i_node, *placeholder;
    i_node = (Node*)malloc(sizeof(Node));
    placeholder = (Node*)malloc(sizeof(Node));

    //initialize the iterated node to the head
    i_node = *first_node;

    while(i_node != NULL)//loop while the iterated node is not NULL
    {
        placeholder = i_node;//temporarily store the iterated node
        i_node = i_node->next;//set the iterated node to the next node
        free(placeholder);//free the temporary node
    }

    //free the iterated node
    free(i_node);

    //exit
    printf("\n\tExiting...\n\n");
    exit(0);
}
