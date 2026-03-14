#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// CROSS-PLATFORM SLEEP FUNCTION
#ifdef _WIN32
void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

int main() {
    // Write Code
    return 0;
}