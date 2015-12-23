#include "Aircraft.h"

/****************************************************************************
This is a simple constructor for structs of the Aircraft type.

Input parameters:   name, char*
                    wingspan, double
                    length, double
                    height, double
                    width, double
                    cost, double

Return:             plane, Aircraft
****************************************************************************/
Aircraft make_aircraft(char name[MAX_NAME_LENGTH], double wingspan, double length, double height, double width, double cost)
{
    //make a new plane and initialize all variables
    Aircraft plane;
    strcpy(plane.name, name);
    plane.wingspan = wingspan;
    plane.length = length;
    plane.height = height;
    plane.width = width;
    plane.cost = cost;

    return plane;
}
