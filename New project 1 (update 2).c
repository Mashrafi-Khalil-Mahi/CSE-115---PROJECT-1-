
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //time er jonno windows e kaj kore amar jana mote

// Function declarations
void startGame();
void mistyRiver();
void guardEncounter();
void gameOver();
void resetGame();
void cityEncounter();
void mayorEncounter();
void shopkeeperEncounter();

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
    printf("\n\nYou encounter a guard blocking the path.\n\n");
    Sleep(2000); // Using Sleep instead of sleep
    printf("Halt! To pass, you must answer my question correctly.\n\n");
    Sleep(2000);

    int answer;
    printf("I am a three-digit number. My tens digit is five more than my ones digit, and my hundreds digit is eight less than my tens digit. What number am I?\n");
    printf("Enter your answer: ");

    int attempts = 0;
    while (1) {
        scanf("%d", &answer);
        if (answer == 194) {
            printf("\n\nCorrect! You may proceed.\n\n");
            Sleep(2000);
            printf("You walk past the guard and enter the city.\n");
            Sleep(2000);
            cityEncounter();
            break;
        } else {
            attempts++;
            if (attempts >= 3) {
                printf("\nYou have failed too many times!\n");
                Sleep(2000);
                printf("\nThe guard finds you suspicious.\n");
                Sleep(2000);
                printf("\nThe guard attacks you!\n\n");
                gameOver(); // Assuming gameOver() is a function to end the game
                return;
            }
            printf("\n\nIncorrect! Try again.\n");
            printf("Enter your answer: ");
        }
    }
}


void cityEncounter()
{
    printf("\n\nYou arrive at a bustling city. There are two people you can approach.\n");
    Sleep(2000);
    printf("One is a wise scholar, and the other is the mayor of the city.\n");
    Sleep(2000);

    int choice;
    printf("\nWho Would you like to meet?\n");
    printf(" (1) The Mayor\n");
    printf(" (2) The Scholar\n");
    printf("\nYour choice: ");
    int attempts=0;
    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\nYou approach the mayor.\n");
            Sleep(2000);
            mayorEncounter();//call function for mayor encounter
            break;
        }
        else if(choice==2)
        {
            printf("\n\nYou see the scholar in front of the library.\n")
            printf("You approach the scholar.\n");
            Sleep(2000);
            scholarEncounter();//call function for scholar encounter
            break;
        }
        else
        {
            attempts++;
            if(attempts>=3)
            {
                printf("Too many invalid attempts!\n");
                Sleep(2000);
                printf("\nsuddenly you find yourself lost in a crowded place and you have no way to return\n\n");
                gameOver(); // Assuming gameOver() is a function to end the game
                return;
            }
            printf("\n Invalid choice! Please choose again:\n");
            printf(" (1) The Mayor\n");
            printf(" (2) The Scholar\n");
            printf("\nYour choice: ");

        }

    }
}

void mayorEncounter()
{
    printf("\n\nThe mayor greets you warmly.\n");
    Sleep(2000);
    printf("Mayor: 'Welcome traveler! I heard you passed the guard's challenge. Not many make it this far.'\n");
    Sleep(2000);
    printf("Mayor: ' I have a proposition for you. There's an old relic lost in the nearby forest.\n");
    Sleep(2000);
    printf("If you retrieve it, I will reward you handsomely. Or if you have other questions, Feel free to ask.'\n\n");
    Sleep(2000);

    int choice;
    printf("What would you like to do?\n");
    printf(" (1) Accept the quest to find the relic\n");
    printf(" (2) Ask for directions to leave the city\n");
    printf(" (3) Politely decline and move on\n");
    printf("\nYour choice: ");


    int attempts=0;
    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n\nYou accept the quest to find the relic. The mayor smiles approvingly.\n");
            Sleep(2000);
            printf("Mayor: 'Wonderful! Head towards the Eastern Forest, and look for a clearing with ancient stones.'\n");
            Sleep(2000);
            printf("'Bring the relic back to me, and you shall be rewarded.'\n\n");
            Sleep(2000);
            printf("\n\nYou follow the path to the forest, keeping an eye out for the relic.\n");
            Sleep(2000);
            printf("After a short search, you find a mysterious object hidden beneath some stones!\n");
            Sleep(2000);
            printf("It must be the relic. You take it and return to the city.\n\n");
            Sleep(2000);
            printf("\n\nYou return to the mayor with the relic in hand.\n");
            Sleep(2000);
            printf("Mayor: 'You did it! I knew I could trust you, brave traveler.'\n");
            Sleep(2000);
            printf("Mayor: Now , What do you plan to do nect?'\n");
            Sleep(2000);
            printf("\n\nYou replied that ''I would like to leave the city.''\n\n");
            Sleep(2000);
            printf("Mayor: 'Very well. I suggest you seek quidance from one of two people:\n");
            Sleep(2000);
            printf("The shopkeeper at the market or the wise scholar near the library.\n");
            Sleep(2000);
            printf("Each may provide a different path.'\n\n");
            Sleep(2000);
            int choice1;
            printf("Who would you like to consult?\n");
            printf(" (1) The shopkeeper\n");
            printf(" (2)The Scholar\n");

            while(1)
            {
            scanf("%d",&choice1);
            if(choice1==1)
                shopkeeperEncounter();
            else if(choice1==2)
                scholarEncounter();
            else
    {
        attempts++;
        if(attempts>=3)
        {
            printf("\nToo many invalid attempts! The mayor looks disappointed.\n");
            Sleep(2000);
            printf("He dismisses you from the city.\n");
            gameOver();
            return;
        }
        printf("\nInvalid choice! Please choose again:\n");
        printf(" (1) The shopkeeper\n");
        printf(" (2)The Scholar\n");
        printf("\nYour choice: ");
    }

        }
        }

    else if(choice==2)
    {
        printf("\n\nYou ask the mayor for directions to leave the city.\n");
        Sleep(2000);
        printf("\n\nMayor: 'If you are looking to leave , speak to the shopkeeper at the market square.\n");
        Sleep(2000);
        printf("He is a wise man who knows the city is paths better than anyone else.'\n\nSo ");
        shopkeeperEncounter();//call shopkeper function to continue the interaction
        break;
    }
    else if (choice==3)
    {
        printf("\n\nYou politely decline the mayor's offer decide to move in.\n");
        Sleep(2000);
        printf("The mayor nods and wishes you well on your journey.\n\n ");



        //rendomly choose weather the meets the sopkeeper or the scholar
        int encounterchoice=rand()%2;// randomly choose 0 or 1

        if(encounterchoice==0)
        {
            //player meets the shopkeeper
            printf("\n\nAs you leave, );
            //call the shopkeeper function
            shopkeeperEncounter();
            break;
        }
        else
        {
            //player meets the scholar
            printf("\n\n As you leave, You notice a wise-looking scholar near the library.\n");
            Sleep(2000);
            printf("Scholar: 'Hello, traveler . You look like someone who seeks knowledge.'\n");
            Sleep(2000);
            //call the scholar function
            scholarEncounter();
            break;
        }


    }

    else
    {
        attempts++;
        if(attempts>=3)
        {
            printf("\nToo many invalid attempts! The mayor looks disappointed.\n");
            Sleep(2000);
            printf("He dismisses you from the city.\n");
            gameOver();
            return;
        }
        printf("\nInvalid choice! Please choose again:\n");
        printf(" (1) Accept the quest to find the relic\n");
        printf(" (2) Ask for directions to leave the city\n");
        printf(" (3) Politely decline and move on\n");
        printf("\nYour choice: ");
    }



    }

}

void scholarEncounter()
{


}

void shopkeeperEncounter()
{
    printf("You see a friendly shopkeeper standing by a stall in the market.");
    Sleep(2000);
    printf("Shopkeeper: 'Hello, traveler. Need any directions or supplies?'\n");
    Sleep(2000);
    printf("");
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

