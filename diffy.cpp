#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <time.h>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>
#define _GLIBCXX_USE_C99 1

using namespace std;


int diffyGoal;
int highestScore;
int DiffyRange; //Range diffy starting values can be in
int DiffyCount = 10; //How many Diffies to make
int *highestScoreStart;  //Pointer to highest score
int timeout;
bool printEach;
void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

int * GenerateStart()
{
    static int start[4]; //Input numbers; will be generated later
    for (int x = 0; x<=3; ++x)
    {
        start[x] = rand()%DiffyRange;
    }

    return start;
}

int GenerateDiffy(int start[], bool process=FALSE)
{
    int counter = 1;
    int num[4]; //Array to hold current step
    int newNum[4] = {0,0,0,0}; //Array to hold next step
    for (int x=0; x<=3; ++x)
    {
        num[x] = start[x];  //Set current step to the start
    }

    while (num[0]+num[1]+num[2]+num[3] != 0)
    {
        newNum[0] = abs(num[0]-num[1]); //Get difference
        newNum[1] = abs(num[1]-num[2]);
        newNum[2] = abs(num[2]-num[3]);
        newNum[3] = abs(num[3]-num[0]);
        for (int x=0; x<=3; ++x)
        {
            num[x] = newNum[x];  //Set current step to next step
        }
        if (process==TRUE)
        {
            for (int x=0; x<=3; ++x)
            {
                cout << num[x] << ", "; // Show full process
            }
            cout << endl;
        }
        counter++;
    }
    if (printEach == TRUE)
    {
        for (int x = 0; x<=3; ++x)
        {
            cout << start[x] << ", ";
        }

        cout << endl << "Final score: " << counter << endl;
    }

    if (process == TRUE)
        return counter-1;
    else
        return counter;
}

int standard()
{
    srand(time(NULL));
    highestScore = 0;
    int *start;
    cout << "Range of diffy starting values: ";
    cin >> DiffyRange;
    cout << endl;
    cout << "Diffies to create: ";
    cin >> DiffyCount;
    cout << endl;
    cout << "Print each diffy? (y/n): ";
    char input;
    cin >> input;
    if (input == 'n')
    {
        printEach = FALSE;
    } else
    {
        printEach = TRUE;
    }
    for (int x = 0; x <= DiffyCount; ++x)
    {
        start = GenerateStart();
        if (GenerateDiffy(start, FALSE) > highestScore)
        {
            highestScoreStart = start;
            highestScore = GenerateDiffy(start);
        }
    }
    SetColor(10);
    cout << "Highest score: " << highestScore << endl;
    cout << "Starting diffy: ";
    for (int x=0; x<=3; ++x)
    {
        cout << highestScoreStart[x] << ", ";
    }
    cout << endl;
    system("pause");
    return 0;
}

int goalBased()
{
    srand(time(NULL));
    highestScore = 0;
    int *start;
    cout << "Range of diffy starting values: ";
    cin >> DiffyRange;
    cout << endl;
    cout << "Diffy goal: ";
    cin >> diffyGoal;
    cout << endl;
    cout << "Print each diffy? (y/n): ";
    char input;
    cin >> input;
    if (input == 'n')
    {
        printEach = FALSE;
    } else
    {
        printEach = TRUE;
    }
    cout << endl << "How long to run in seconds? (-1 for forever): ";
    cin >> timeout;
    int endTime = time(0) + timeout;
    while (highestScore < diffyGoal  && time(0) != endTime)
    {
        start = GenerateStart();
        if (GenerateDiffy(start) > highestScore)
        {
            highestScoreStart = start;
            highestScore = GenerateDiffy(start);
        }
    }
    SetColor(10);
    if (highestScore == diffyGoal)
        cout << "Score: " << highestScore << endl;
    else if (highestScore > diffyGoal)
        cout << "Score managed: " << highestScore << endl;
    cout << "Starting Diffy: ";
    for (int x=0; x<=3; ++x)
    {
        cout << highestScoreStart[x] << ", ";
    }
    cout << endl;
    system("pause");
    return 0;
}


int calculateDiffy()
{

    int diffy[4];
    int x;
    for (x = 0; x<=3; ++x)
    {
        cout << endl << "Enter number " << x+1 << " ";
        cin >> diffy[x];
    }
    SetColor(10);
    cout << "Final score: " << GenerateDiffy(diffy, TRUE);
    return 0;
}
