#ifndef AIRCRAFT_H_INCLUDED
#define AIRCRAFT_H_INCLUDED

#include <string.h>
#define MAX_NAME_LENGTH 20

typedef struct Aircraft{
    char name[MAX_NAME_LENGTH];
    double wingspan;
    double length;
    double height;
    double width;
    double cost;
}Aircraft;

Aircraft make_aircraft(char name[MAX_NAME_LENGTH], double wingspan, double length, double height, double width, double cost);

#include "Aircraft.c"

#endif // AIRCRAFT_H_INCLUDED
