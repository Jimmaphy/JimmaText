#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdio.h>


int main() {
    // Setup the variables
    int character;

    // Keep looping forever until EOF or q is entered
    while (1) {
        // Check if a key has been pressed
        if (_kbhit()) {
            // Read the character
            character = _getch();

            // Check if the character is 'q' or EOF, if so, stop
            if (character == 'q' || character == EOF) {
                break;
            }

            // Check if the character is a control character
            if (iscntrl(character)) {
                // Print the character code
                printf("Char code: %d\r\n", character);
            } else {
                // Print the code and the character
                printf("Char code: %d (%c)\r\n", character, character);
            }
        } else {
            // No key is pressed, wait for 100ms
            Sleep(100);
        }
    }

    // The program has ended successfully
    return 0;
}