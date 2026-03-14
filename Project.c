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
    char restart;

    do
    {
        system("cls"); // clear the console

        int difficulty, attempts = 0, max_attempts[3] = {5, 4, 3};

        color(14);

        gotoxy(15, 1);
        p_line("================================", 0.1);

        gotoxy(15, 2);
        p_line("|     Number Guessing Game     |", 0.1);

        gotoxy(15, 3);
        p_line("================================\n\n", 0.1);

        color(11);
        p_line("==========================\n", 0.1);
        p_line("Select a difficulty level~\n", 0.1);
        p_line("==========================\n\n", 0.1);

        color(11);
        printf("1.");
        color(10);
        p_line(" Easy (1-50)   - 5 attempts\n", 0.1);

        color(11);
        printf("2.");
        color(14);
        p_line(" Medium (1-100) - 4 attempts\n", 0.1);

        color(11);
        printf("3.");
        color(12);
        p_line(" Hard (1-500)   - 3 attempts\n\n", 0.1);

        color(11);
        p_line("Enter difficulty level (1-3):  ", 0.1);

        color(15);
        if ((scanf("%d", &difficulty) != 1) || difficulty < 1 || difficulty > 3)
        {
            color(12);
            p_line("\n\t\tInvalid input!\nPlease enter a valid selection between 1 and 3.\n\n", 0.5);
            exit_spining();
            color(15);

            while (getchar() != '\n')
                ;
            break;
        }
        else
        {
            color(11);
            p_line("\n\n==========================", 0.1);
            p_line("\nDifficulty level: ", 0.1);

            switch (difficulty)
            {
            case 1:
                color(10);
                p_line("Easy\n", 0.1);
                break;
            case 2:
                color(14);
                p_line("Medium\n", 0.1);
                break;
            case 3:
                color(12);
                p_line("Hard\n", 0.1);
                break;
            }
        }

        color(11);
        p_line("==========================\n\n", 0.1);

        color(14);
        int selected_number = select_number(difficulty);

        color(11);
        if (difficulty == 1)
        {
            p_line("\n\n==================================\n", 0.1);
            p_line("Guess the number between ", 0.1);
            color(10);
            p_line("1 and 50!", 0.1);
            color(11);
            p_line("\n==================================\n", 0.1);
        }
        else if (difficulty == 2)
        {
            p_line("\n\n====================================\n", 0.1);
            p_line("Guess the number between ", 0.1);
            color(14);
            p_line(" 1 and 100!", 0.1);
            color(11);
            p_line("\n====================================\n", 0.1);
        }
        else
        {
            p_line("\n\n====================================\n", 0.1);
            p_line("Guess the number between ", 0.1);
            color(12);
            p_line(" 1 and 500!", 0.1);
            color(11);
            p_line("\n====================================\n", 0.1);
        }
    } while (restart == 'Y');
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