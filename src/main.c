#include <stdio.h>
#include <windows.h>

void enableRawMode() {
    // Create a handle to the console input buffer
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

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

int main() {
    // Enable raw mode
    enableRawMode();

    // Variable to hold the current character
    char c;

    // Loop until the user presses 'q' or EOF is reached
    while((c = getchar()) != EOF && c != 'q');

    // The program has ended successfully
    return 0;
}