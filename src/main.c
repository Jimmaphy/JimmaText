#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <windows.h>


int main() {
    // Setup the variables
    HANDLE hStdin;
    DWORD result;
    int character;

    // Get the handle to the standard input
    hStdin = GetStdHandle(STD_INPUT_HANDLE);

    // Keep looping forever until EOF or q is entered
    while (1) {
        // Wait for input with a timeout of 100ms
        result = WaitForSingleObject(hStdin, 100);

        // Check if the result is WAIT_OBJECT_0, if so, read the character
        if (result == WAIT_OBJECT_0) {
            // Read the character
            character = _getch();

            // Check if the character is 'q' or EOF, if so, stop
            if (character == 'q' || character == EOF) {
                break;
            }

            // Check if the character is printable
            if (iscntrl(character)) {
                // Print the character code
                printf("Char code: %d\r\n", character);
            } else {
                // Print the code and the character
                printf("Char code: %d (%c)\r\n", character, character);
            }
        } else {
            // Print a message
            printf("Waiting for input...\r\n");
        }
    }

    // The program has ended successfully
    return 0;
}