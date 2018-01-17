#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
int highestScore;
int DiffyRange; //Range diffy starting values can be in
int DiffyCount = 10; //How many Diffies to make
int *highestScoreStart;  //Pointer to highest score

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

int GenerateDiffy(int start[])
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


    return counter;
}

int main()
{
    srand(time(NULL));
    int highestScore = 0;
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
        if (GenerateDiffy(start) > highestScore)
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
