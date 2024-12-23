#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio> 
#include <stdlib.h>

namespace fs = std::filesystem;
struct flights_t 
{
    union
    {
        int number;
        long numberL;
    } d;
    char type[30];
    char destination[30];
    char time[6];
}; 
typedef struct flights_t Flights;
extern Flights* flightsArr;

int checkNum();
int check();
void inputFlights();
void readFromFile();
void addFlightsToFile();
void deletionFlight(int deleteNumber);
void testFile();
void changeFlight();
void testFile1();
void menu();