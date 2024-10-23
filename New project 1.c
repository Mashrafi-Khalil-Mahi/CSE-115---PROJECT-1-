#include <stdio.h>

// Global variable to track Misty River visit
int mistyRiverVisited = 0;

// Function declarations
void mistyRiver();
void guardEncounter();
void gameOver();

int main() {
    int choice;

    while (1) { // Game loop
        printf("Game starts. You find yourself lost in the woods.\n");
        printf("You see two paths: one towards a Misty River and another towards a Paved Road.\n");
        printf("Choose your path: (1) Misty River (2) Paved Road: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (mistyRiverVisited) {
                    printf("You've already visited the Misty River. Choose another path.\n");
                } else {
                    mistyRiver();
                    mistyRiverVisited = 1; // Mark as visited after the first encounter
                }
                break;
            case 2:
                guardEncounter();
                break;
            default:
                printf("Invalid choice! Game Over.\n");
                gameOver();
        }

        // Ask the player if they want to play again or exit
        printf("Do you want to play again? (1) Yes (2) No: ");
        scanf("%d", &choice);
        if (choice != 1) {
            break; // Exit the loop and end the game
        }
    }

    return 0;
}

void mistyRiver() {
    printf("You proceed towards the Misty River...\n\n");
    printf("The road is so slippery...\n");
    printf("Unfortunately, it's too dangerous to cross. You slipped and fell in the river.\n");
    printf("There is a log. Do you want to grab it and go back safely to the previous place?\n");

    int n;
    printf("Enter 1. Yes \n2. No: ");
    scanf("%d", &n);

    switch(n) {
        case 1: {
            int choice;
            printf("Do you want to (1) Try to cross again or (2) Go back to the fork in the path? ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You bravely attempt to cross again...\n");
                printf("You fell again! Game Over.\n");
                gameOver();
            } else if (choice == 2) {
                printf("You decided to go back to the fork in the path.\n");
                // Control flow will return to the main game loop
            } else {
                printf("Invalid choice! Game Over.\n");
                gameOver();
            }
            break;
        }
        case 2:
            printf("You chose not to grab the log and are swept away! Game Over.\n");
            gameOver();
            break;
        default:
            printf("Invalid choice! Game Over.\n");
            gameOver();
    }
}

void guardEncounter() {
    // Your guard encounter logic here...
}

void gameOver() {
    printf("Game Over! Try again next time.\n");
    // Optional: Reset game state or exit.
}
