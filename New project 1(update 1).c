#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //time er jonno windows e kaj kore amar jana mote

// Function declarations
void startGame();
void mistyRiver();
void guardEncounter();
void gameOver();
void resetGame();

// Global variables to track game state
int mistyRiverVisited = 0; // ekhane hisab kore rakhtese je age kono bar river option dise naki
int returnedToFork = 0;    // ekhane dekhtese je abr prothome back asche naki

int main() {
    startGame(); // Start the game initially
    return 0;
}

void startGame() {
    int choice;

    while (1) { // Main game loop, starts fresh each time

        // jehetu abr river er por return korse sehetu come back dekhabe
        if (returnedToFork) {
            printf("\n\nYou have come back again. Now choose the correct path.\n\n");
            Sleep(2000); // Wait for 2 seconds
            returnedToFork = 0; // rest kore dicchi cause abr jdi game start hoy tkhn eta count kore rakhbe ey karon e ekta error hoye jabe
        } else {
            printf("\n\nGame starts. You find yourself lost in the woods.\n");
            Sleep(2000);
            printf("You see two paths: one towards a Misty River and another towards a Paved Road.\n\n");
            Sleep(2000);
        }

        printf("Choose your path:\n");
        printf("  (1) Misty River\n");
        printf("  (2) Paved Road\n");
        printf("\nYour choice: ");

        // proti  ta rasthar jonno koy bar invalid hoccho oy shb er jonno
        int attempts = 0; // koy bar invalid hocche
        while (1) {
            scanf("%d", &choice);
            if (choice == 1 || choice == 2) {
                break; // jdi choice invalid nah hoy taile ey loop theke ber hoye jabe
            }
            attempts++;
            if (attempts >= 3) {
                gameOver(); // Game Over after 3 invalid attempts
                return;     // function er te ber hoye jabe game over
            }
            printf("\n\nInvalid choice! Please choose again:\n");
            printf("  (1) Misty River\n");
            printf("  (2) Paved Road\n");
            printf("\nYour choice: ");
        }

        printf("\n");

        switch (choice) {
        case 1:
            if (mistyRiverVisited) {
                printf("\n\nYou've already visited the Misty River.\n\n");
                Sleep(2000);
                gameOver(); // Restart game if the Misty River is revisited
            } else {
                mistyRiver();
                mistyRiverVisited = 1; // Mark Misty River as visited
                returnedToFork = 1;    // Set flag to indicate return to fork
            }
            break;
        case 2:
            guardEncounter();
            returnedToFork = 1; // Set flag if coming back to the fork
            break;
        }
    }
}

void mistyRiver() {
    printf("\n\nYou proceed towards the Misty River...\n\n");
    Sleep(2000);
    printf("The road is so slippery...\n\n");
    Sleep(2000);
    printf("Unfortunately, it's too dangerous to cross. You slipped and fell in the river.\n\n");
    Sleep(2000);
    printf("There is a log. Do you want to grab it and go back safely to the previous place?\n");

    int n;
    printf("\nEnter your choice:\n");
    printf("  1. Yes\n");
    printf("  2. No\n");
    printf("\nYour choice: ");

    // Validate input for the log choice
    int attempts = 0; // Counter for invalid attempts
    while (1) {
        scanf("%d", &n);
        if (n == 1 || n == 2) {
            break; // Exit loop if valid choice
        }
        attempts++;
        if (attempts >= 3) {
            gameOver(); // Game Over after 3 invalid attempts
            return;     // Exit the function after game over
        }
        printf("\n\nInvalid choice! Please choose again:\n");
        printf("  1. Yes\n");
        printf("  2. No\n");
        printf("\nYour choice: ");
    }
    printf("\n");

    switch (n) {
    case 1: {
        int choice;
        printf("\nWhat do you want to do next?\n");
        printf("  (1) Try to cross again\n");
        printf("  (2) Go back to the fork in the path\n");
        printf("\nYour choice: ");

        // Validate input for the next choice
        attempts = 0; // Reset attempts for next choice
        while (1) {
            scanf("%d", &choice);
            if (choice == 1 || choice == 2) {
                break; // Exit loop if valid choice
            }
            attempts++;
            if (attempts >= 3) {
                gameOver(); // Game Over after 3 invalid attempts
                return;     // Exit the function after game over
            }
            printf("\n\nInvalid choice! Please choose again:\n");
            printf("  (1) Try to cross again\n");
            printf("  (2) Go back to the fork in the path\n");
            printf("\nYour choice: ");
        }
        printf("\n");

        if (choice == 1) {
            printf("\n\nYou bravely attempt to cross again...\n\n");
            Sleep(2000);
            printf("You fell again!\n\n");
            Sleep(2000);
            gameOver();
        } else if (choice == 2) {
            printf("\n\nYou decided to go back to the fork in the path.\n\n");
            Sleep(2000);
            returnedToFork = 1; // Set flag for returning to fork
            return; // Return to the main game loop
        }
        break;
    }
    case 2:
        printf("\n\nYou chose not to grab the log and are swept away! Game Over.\n\n");
        Sleep(2000);
        gameOver();
        break;
    }
}

void guardEncounter() {
    printf("\n\nYou encounter a guard. Unfortunately, you’re turned back to the fork in the path.\n\n");
    Sleep(2000);
}

void gameOver() {
    int playAgain;

    printf("Game Over! Try again next time.\n\n");
    Sleep(2000);
    printf("Do you want to play again?\n");
    printf("  (1) Yes\n");
    printf("  (2) No\n");
    printf("\nYour choice: ");

    // Validate input for play again choice
    int attempts = 0; // Counter for invalid attempts
    while (1) {
        scanf("%d", &playAgain);
        if (playAgain == 1 || playAgain == 2) {
            break; // Exit loop if valid choice
        }
        attempts++;
        if (attempts >= 3) {
            exit(0); // Exit the game after 3 invalid attempts
        }
        printf("\n\nInvalid choice! Please choose again:\n");
        printf("  (1) Yes\n");
        printf("  (2) No\n");
        printf("\nYour choice: ");
    }
    printf("\n");

    if (playAgain == 1) {
        resetGame(); // Reset game state if the player wants to play again
        startGame(); // Restart the game from the beginning
    } else {
        exit(0); // Exit the game if the player does not choose to restart
    }
}

void resetGame() {
    mistyRiverVisited = 0; // Reset Misty River visit tracking
    returnedToFork = 0;    // Reset return-to-fork flag
    printf("\n\nRestarting the game...\n\n");
    Sleep(2000);
}

