#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int standard();
int calculateDiffy();
int goalBased();
using namespace std;

int main()
{
    int option;
    cout << "Calculate single diffy (1), run the program to meet a goal (2), or run the standard program (3): ";
    cin >> option;
    switch (option) {
        case 1: calculateDiffy();
        break;
        case 2: goalBased();
        break;
        case 3: standard();
        break;
    }
    return 0;
}
