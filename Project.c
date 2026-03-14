#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// CROSS-PLATFORM SLEEP FUNCTION
#ifdef _WIN32
void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

// FUNTIONS PROTOTYPES
void gotoxy(int x, int y);

// MAIN FUNCTION
int main() {
    // Write Code
    return 0;
}

// FUNCTION DEFINITIONS

// =========================MOVE CURSOR TO (X, Y) POSITION=========================

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}