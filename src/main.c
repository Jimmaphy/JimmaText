#include <ctype.h>
#include <stdio.h>
#include <windows.h>


void saveOriginalConsoleMode(HANDLE hStdin, LPDWORD originalConsoleMode) {
    // Get the current console mode and store it
    GetConsoleMode(hStdin, originalConsoleMode);
}

void resetConsoleMode(HANDLE hStdin, DWORD originalConsoleMode) {
    // Set the original console mode
    SetConsoleMode(hStdin, originalConsoleMode);
}

void enableRawMode(HANDLE hStdin) {
    // DWORD (32-bit unsigned integer) to store the console mode
    DWORD mode;

    // Get the current console mode and store it
    GetConsoleMode(hStdin, &mode);

    // Disable line input and echo input
    // &= is a bitwise AND assignment operator
    // ~ is a bitwise NOT operator
    // Only ENABLE_ECHO_INPUT and ENABLE_LINE_INPUT bits are changed
    mode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);

    // Set the new console mode
    SetConsoleMode(hStdin, mode);
}

void disableRawMode(HANDLE hStdin) {
    // DWORD (32-bit unsigned integer) to store the console mode
    DWORD mode;

    // Get the current console mode and store it
    GetConsoleMode(hStdin, &mode);

    // Enable line input and echo input
    // |= is a bitwise OR assignment operator
    // ENABLE_ECHO_INPUT and ENABLE_LINE_INPUT bits are changed
    mode |= (ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);

    // Set the new console mode
    SetConsoleMode(hStdin, mode);
}

int main() {
    // Setup the variables
    HANDLE hStdin;
    DWORD originalConsoleMode;
    char c;

    // Get the handle to the standard input
    hStdin = GetStdHandle(STD_INPUT_HANDLE);

    // Save the original console mode
    saveOriginalConsoleMode(hStdin, &originalConsoleMode);

    // Enable raw mode
    enableRawMode(hStdin);

    // Loop until the user presses 'q' or EOF is reached
    while((c = getchar()) != EOF && c != 'q') {
        // Check if the character is printable
        if(iscntrl(c)) {
            // Print the character code
            printf("Char code: %d\n", c);
        } else {
            // Print the code and the character
            printf("Char code: %d (%c)\n", c, c);
        }
    }

    // Reset the console mode
    resetConsoleMode(hStdin, originalConsoleMode);

    // The program has ended successfully
    return 0;
}