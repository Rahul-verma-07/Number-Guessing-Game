#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// CROSS-PLATFORM SLEEP FUNCTION
#ifdef _WIN32
void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

// FUNTIONS PROTOTYPES
void gotoxy(int x, int y);
void color(int c);
void p_line(const char *line, float seconds);
int select_number(int level);
void restart_spining();
void exit_spining();

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

        do
        {
            color(11);
            p_line("\n=> Enter your guess:  ", 0.1);

            int guess;

            color(15);
            if ((scanf("%d", &guess) != 1) || guess < 1 || guess > (difficulty == 1 ? 50 : (difficulty == 2 ? 100 : 500)))
            {
                color(12);
                p_line("\n\t\tInvalid input!\nPlease enter a valid number within the specified range.\n", 0.5);

                while (getchar() != '\n')
                    ;
                continue;
            }
            else if (guess == selected_number)
            {
                color(10);
                p_line("\n========================================\n", 0.1);
                p_line("Congratulations! You guessed the number!", 0.1);
                p_line("\n========================================\n\n", 0.1);
                break;
            }
            else if (guess < selected_number)
            {
                color(14);
                p_line("\nToo low! Try again.\n", 0.1);
                attempts++;

                while (getchar() != '\n')
                    ;

                if (attempts >= max_attempts[difficulty - 1])
                {
                    color(12);
                    p_line("\n========================================\n", 0.1);
                    p_line("Game Over! You've used all your attempts", 0.1);
                    p_line("\n========================================\n\n", 0.1);
                    
                    color(10);
                    printf("  ---| The correct number was: %d |---\n\n", selected_number);
                    break;
                }

                printf("Attempts left: %d\n", max_attempts[difficulty - 1] - attempts);
                continue;
            }
            else
            {
                color(12);
                p_line("\nToo high! Try again.\n", 0.1);
                attempts++;

                while (getchar() != '\n')
                    ;

                if (attempts >= max_attempts[difficulty - 1])
                {
                    color(12);
                    p_line("\n========================================\n", 0.1);
                    p_line("Game Over! You've used all your attempts", 0.1);
                    p_line("\n========================================\n\n", 0.1);
                    
                    color(10);
                    printf("  ---| The correct number was: %d |---\n\n", selected_number);
                    break;
                }

                printf("Attempts left: %d\n", max_attempts[difficulty - 1] - attempts);
                continue;
            }

        } while (1);

        color(11);
        p_line("Do you want to play again? (Y/N): ", 0.1);
        scanf(" %c", &restart);
        restart = toupper(restart);

        if(restart == 'N')
        {
            color(14);
            p_line("\n\tThank you for playing!\n\n", 0.1);
            exit_spining();
            break;
        }
        else if (restart == 'Y')
        {
            color(14);
            restart_spining();
            continue;
        }
        else
        {
            color(12);
            p_line("\n\t\tInvalid input!\n\n", 0.5);
            p_line("\t\t ", 0.5);
            exit_spining();
            color(15);
            break;
        }

    } while (restart == 'Y');

    color(15);
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

// =========================SET CONSOLE TEXT COLOR=========================

void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    // 11 ==> cyan, 12 ==> red, 10 ==> green, 14 ==> yellow, 15 ==> white
}

// =========================PRINT LINE WITH TYPEWRITER EFFECT=========================

void p_line(const char *line, float seconds)
{
    int len = strlen(line);
    if (len == 0 || seconds <= 0)
        return;

    int total_ms = (int)(seconds * 1000);
    int delay_step = 3; // delay after every 3 characters
    int per_delay = total_ms / (len / delay_step + 1);

    for (int i = 0; line[i] != '\0'; i++)
    {
        putchar(line[i]);
        fflush(stdout);

        if (i % delay_step == 0) // delay less often
            sleep_ms(per_delay);
    }
}

// =========================SELECT A RANDOM NUMBER WITH ANIMATION=========================

int select_number(int level)
{
    int max_range, true_number;

    printf("\n");

    // SET MAX RANGE BASED ON DIFFICULTY
    if (level == 1)
        max_range = 50;
    else if (level == 2)
        max_range = 100;
    else
        max_range = 500;

    srand(time(0));
    true_number = rand() % max_range + 1;

    char spin[] = {'|', '/', '-', '\\'};

    for (int i = 0; i < 20; i++)
    {
        printf("\rSelecting number... %c", spin[i % 4]);
        fflush(stdout);
        sleep_ms(100);
    }

    color(10);
    printf("\rSelecting number... Complete!     \n");

    return true_number;
}

// =========================RESTART GAME ANIMATION=========================

void restart_spining()
{
    char spin[] = {'|', '/', '-', '\\'};

    printf("\n");

    for (int i = 0; i < 20; i++)
    {
        printf("\rRestarting Game... %c", spin[i % 4]);
        fflush(stdout);
        sleep_ms(100);
    }

    color(10);
    printf("\rRestarting Game... Complete!     \n");
}

// =========================EXIT GAME ANIMATION=========================
void exit_spining()
{
    char spin[] = {'|', '/', '-', '\\'};

    printf("\t");

    for (int i = 0; i < 20; i++)
    {
        printf("\rExiting Game... %c", spin[i % 4]);
        fflush(stdout);
        sleep_ms(100);
    }

    color(10);
    printf("\rExiting Game... Complete!     \n");
}