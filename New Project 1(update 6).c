#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h> //time er jonno windows e kaj kore amar jana mote

// Function declarations
void startGame();
void mistyRiver();
void guardEncounter();
void gameOver();
void resetGame();
void cityEncounter();
void mayorEncounter();
void scholarEncounter();
void shopkeeperEncounter();
void temple();
void toLowerCase(char str[]);
void enemyEncounter();
void ancientBeingEncounter();
void reachingHome();
int isValidAnswer(char *answer);


// Global variables to track game state
int mistyRiverVisited = 0; // ekhane hisab kore rakhtese je age kono bar river option dise naki
int returnedToFork = 0;    // ekhane dekhtese je abr prothome back asche naki
int gameWon=0;
int main()
{
    srand(time(NULL));//for random number
    startGame(); // Start the game initially
    return 0;
}

void startGame()
{
    int choice;

    while (1)   // Main game loop, starts fresh each time
        {

        // Check if the player is returning to the fork
        if (returnedToFork)
            {
            printf("\n\nYou have come back again. Now choose the correct path.\n\n");
            Sleep(1000);
            returnedToFork = 0; // Reset to avoid repeating the message
            }
        else
            {
            printf("\n\nGame starts. You find yourself lost in the woods.\n");
            Sleep(1000);
            printf("You see two paths: one towards a Misty River and another towards a Paved Road.\n\n");
            Sleep(1000);
            }

        printf("Choose your path:\n");
        printf("  (1) Misty River\n");
        printf("  (2) Paved Road\n");
        printf("\nYour choice: ");

        int attempts = 0;

        while (1)
            {
            // Check if the input is a valid integer
            if (scanf("%d", &choice) != 1)
                {
                // Clear the invalid input from the buffer
                while (getchar() != '\n'); // Discard invalid characters
                printf("\nInvalid input!");
                if (attempts>-1&&attempts<2)
                    printf("Please enter a valid number.\n");
                else printf("\n");
                attempts++;
                }
            else if (choice == 1 || choice == 2)
                {
                // If the choice is valid, break out of the loop
                break;
                }
            else
                {
                // Increment attempts if the input is an integer but not a valid choice (1 or 2)
                printf("\nInvalid choice!");
                if (attempts>-1&&attempts<2)
                    printf("Please choose 1 or 2.\n");
                else printf("\n");
                attempts++;
                }

            // End game if the player has exceeded 3 invalid attempts
            if (attempts >= 3)
                {
                gameOver();
                return;
                }

            printf("\nYour choice: ");
            }

        printf("\n");

        switch (choice)
            {
            case 1:
                if (mistyRiverVisited)
                    {
                    printf("\n\nYou've already visited the Misty River.\n\n");
                    Sleep(1000);
                    gameOver(); // Restart game if the Misty River is revisited
                    }
                else
                    {
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


void mistyRiver()
{
    printf("\n\nYou proceed towards the Misty River...\n\n");
    Sleep(1000);
    printf("The road is so slippery...\n\n");
    Sleep(1000);
    printf("Unfortunately, it's too dangerous to cross. You slipped and fell in the river.\n\n");
    Sleep(1000);
    printf("There is a log. Do you want to grab it and go back safely to the previous place?\n");

    int n;
    int attempts = 0;

    // Prompt the user to choose whether to grab the log or not
    printf("\nEnter your choice:\n");
    printf("  1. Yes\n");
    printf("  2. No\n");
    printf("\nYour choice: ");

    while (1)
        {
        // Validate integer input
        if (scanf("%d", &n) != 1)
            {
            // Clear invalid input
            while (getchar() != '\n');
            printf("\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            printf("\n");
            attempts++;
            }
        else if (n == 1 || n == 2)
            {
            break; // Exit loop if valid choice
            }
        else
            {
            printf("\n\nInvalid choice!");
            if (attempts>-1&&attempts<2)
                printf("Please choose 1 or 2.\n");
            else printf("\n");
            attempts++;
            }

        // Check if maximum attempts are reached
        if (attempts >= 3)
            {
            gameOver(); // End game after 3 invalid attempts
            return;
            }

        printf("\nYour choice: ");
        }

    printf("\n");

    switch (n)
        {
        case 1:
            {
            int choice;
            attempts = 0; // Reset attempts for the next choice

            printf("\nWhat do you want to do next?\n");
            printf("  (1) Try to cross again\n");
            printf("  (2) Go back to the fork in the path\n");
            printf("\nYour choice: ");

            while (1)
                {
                // Validate integer input for the next choice
                if (scanf("%d", &choice) != 1)
                    {
                    // Clear invalid input
                    while (getchar() != '\n');
                    printf("\nInvalid input!");
                    if (attempts>-1&&attempts<2)
                        printf("Please enter a valid number.\n");
                    printf("\n");
                    attempts++;
                    }
                else if (choice == 1 || choice == 2)
                    {
                    break; // Exit loop if valid choice
                    }
                else
                    {

                    printf("\n\nInvalid choice!\n");
                    if (attempts>-1&&attempts<2)
                        printf("Please choose 1 or 2.\n");
                    else printf("\n");
                    attempts++;
                    }

                // Check if maximum attempts are reached
                if (attempts >= 3)
                    {
                    gameOver(); // End game after 3 invalid attempts
                    return;
                    }

                printf("\nYour choice: ");
                }

            printf("\n");

            if (choice == 1)
                {
                printf("\n\nYou bravely attempt to cross again...\n\n");
                Sleep(1000);
                printf("You fell again!\n\n");
                Sleep(1000);
                gameOver();
                }
            else if (choice == 2)
                {
                printf("\n\nYou decided to go back to the fork in the path.\n\n");
                Sleep(1000);
                returnedToFork = 1; // Set flag for returning to fork
                return; // Return to the main game loop
                }
            break;
            }
        case 2:
            printf("\n\nYou chose not to grab the log and are swept away! Game Over.\n\n");
            Sleep(1000);
            gameOver();
            break;
        }
}




void guardEncounter()
{
    printf("\n\nYou encounter a guard blocking the path.\n\n");
    Sleep(1000);
    printf("Halt! To pass, you must answer my question correctly.\n\n");
    Sleep(1000);

    int answer;
    int attempts = 0;

    printf("I am a three-digit number. My tens digit is five more than my ones digit, and my hundreds digit is eight less than my tens digit. What number am I?\n");

    while (attempts < 3)
        {
        printf("\nEnter your answer: ");

        // Check if input is a valid integer
        if (scanf("%d", &answer) != 1)
            {
            // Clear invalid input from buffer
            while (getchar() != '\n');
            printf("\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;  // Increment attempts for invalid input

            }
        else if (answer == 194)
            {
            printf("\n\nCorrect! You may proceed.\n\n");
            Sleep(1000);
            printf("You walk past the guard and enter the city.\n");
            Sleep(1000);
            cityEncounter();
            return;

            }
        else
            {
            printf("\n\nIncorrect! ");
            if (attempts>-1&&attempts<2)
                printf("Try again\n");
            else printf("\n");
            attempts++;
            }
        }

    // If the player fails after 3 attempts
    printf("\nYou have failed too many times!\n");
    Sleep(1000);
    printf("\nThe guard finds you suspicious.\n");
    Sleep(1000);
    printf("\nThe guard attacks you!\n\n");
    gameOver();
}



void cityEncounter()
{
    printf("\n\nYou arrive at a bustling city. There are two people you can approach.\n");
    Sleep(1000);
    printf("One is a wise scholar, and the other is the mayor of the city.\n");
    Sleep(1000);

    int choice;
    int attempts = 0;

    printf("\nWho would you like to meet?\n");
    printf(" (1) The Mayor\n");
    printf(" (2) The Scholar\n");
    printf("\nYour choice: ");

    while (1)
        {
        // Check if input is an integer
        if (scanf("%d", &choice) != 1)
            {
            // Clear invalid input
            while (getchar() != '\n');
            printf("\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;
            }
        else if (choice == 1 || choice == 2)
            {
            // Valid choice, proceed to the encounter
            if (choice == 1)
                {
                printf("\n\nYou approach the mayor.\n");
                Sleep(1000);
                mayorEncounter(); // Call function for mayor encounter
                }
            else if (choice == 2)
                {
                printf("\nYou arrive at the entrance of a towering, ancient library.\n");
                Sleep(1000);
                printf("The vast stone steps lead up to grand doors etched with symbols from lost ages.\n");
                Sleep(1000);
                printf("Near the doors, a wise-looking scholar stands, as if waiting for you.\n");
                Sleep(1000);
                scholarEncounter(); // Call function for scholar encounter
                }
            break;
            }
        else
            {
            // Handle valid integer input, but incorrect choice
            printf("\nInvalid choice!\n");
            if (attempts>-1&&attempts<2)
                printf("Please choose 1 or 2.\n");
            else printf("\n");
            attempts++;
            }

        // Check if the maximum attempts are reached
        if (attempts >= 3)
            {
            printf("Too many invalid attempts!\n");
            Sleep(1000);
            printf("\nSuddenly you find yourself lost in a crowded place, with no way to return.\n\n");
            gameOver(); // Call gameOver to end the game
            return;
            }

        // Re-prompt user for input
        printf(" (1) The Mayor\n");
        printf(" (2) The Scholar\n");
        printf("\nYour choice: ");
        }
}


void mayorEncounter()
{
    printf("\n\nThe mayor greets you warmly.\n");
    Sleep(1000);
    printf("Mayor: 'Welcome traveler! I heard you passed the guard's challenge. Not many make it this far.'\n");
    Sleep(1000);
    printf("Mayor: 'I have a proposition for you. There's an old relic lost in the nearby forest.\n");
    Sleep(1000);
    printf("\tIf you retrieve it, I will reward you handsomely. Or if you have other questions, feel free to ask.'\n\n");
    Sleep(1000);

    int choice;
    int attempts = 0; // Count invalid attempts

    printf("What would you like to do?\n");
    printf(" (1) Accept the quest to find the relic\n");
    printf(" (2) Ask for directions to leave the city\n");
    printf(" (3) Politely decline and move on\n");
    printf("\nYour choice: ");

    while (1)
        {

        if (scanf("%d", &choice) != 1)
            {
            // Clear invalid input
            while (getchar() != '\n');
            printf("\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;
            }
        else if (choice == 1 || choice == 2 || choice == 3)
            {
            // Valid choices for the main decision
            if (choice == 1)
                {
                printf("\n\nYou accept the quest to find the relic. The mayor smiles approvingly.\n");
                Sleep(1000);
                printf("Mayor: 'Wonderful! Head towards the Eastern Forest, and look for a clearing with ancient stones.'\n");
                Sleep(1000);
                printf("\tBring the relic back to me, and you shall be rewarded.'\n\n");
                Sleep(1000);
                printf("\n\nYou follow the path to the forest, keeping an eye out for the relic.\n");
                Sleep(1000);
                printf("After a short search, you find a mysterious object hidden beneath some stones!\n");
                Sleep(1000);
                printf("It must be the relic. You take it and return to the city.\n\n");
                Sleep(1000);
                printf("\n\nYou return to the mayor with the relic in hand.\n");
                Sleep(1000);
                printf("Mayor: 'You did it! I knew I could trust you, brave traveler.'\n");
                Sleep(1000);
                printf("Mayor: 'Now, what do you plan to do next?'\n");
                Sleep(1000);
                printf("\n\nYou replied, 'I would like to leave the city.'\n\n");
                Sleep(1000);
                printf("Mayor: 'Very well. I suggest you seek guidance from one of two people:\n");
                Sleep(1000);
                printf("\tThe shopkeeper at the market or the wise scholar near the library.\n");
                Sleep(1000);
                printf("\tEach may provide a different path.'\n\n");
                Sleep(1000);

                int choice1;
                attempts = 0; // Reset attempts for the next choice

                printf("Who would you like to consult?\n");
                printf(" (1) The shopkeeper\n");
                printf(" (2) The Scholar\n");
                printf("\nYour choice: ");

                while (1)
                    {
                    if (scanf("%d", &choice1) != 1)
                        {
                        // Clear invalid input
                        while (getchar() != '\n');
                        printf("\nInvalid input!");
                        if (attempts>-1&&attempts<2)
                            printf("Please enter a valid number.\n");
                        else printf("\n");
                        attempts++;
                        }
                    else if (choice1 == 1 || choice1 == 2)
                        {
                        // Valid choice
                        if (choice1 == 1)
                            {
                            printf("\n\nSo you choose to go to the shopkeeper.\n");
                            Sleep(1000);
                            printf("\n\nThe shopkeeper was standing by a stall in the market.\n\n");
                            shopkeeperEncounter();
                            }
                        else
                            {
                            printf("\n\nSo you choose to go to the scholar.\n");
                            Sleep(1000);
                            printf("\n\nThe scholar was standing near the library as if he is waiting for you.\n\n");
                            scholarEncounter();
                            }
                        break;
                        }
                    else
                        {
                        // Invalid choice
                        attempts++;
                        if (attempts >= 3)
                            {
                            printf("\nToo many invalid attempts! The mayor looks disappointed.\n");
                            Sleep(1000);
                            printf("He dismisses you from the city.\n");
                            gameOver();
                            return;
                            }
                        printf("\nInvalid choice! Please choose again:\n");

                        }
                    if (attempts >= 3)
                        {
                        printf("\nToo many invalid attempts! The mayor looks disappointed.\n");
                        Sleep(1000);
                        printf("He dismisses you from the city.\n");
                        gameOver();
                        return;
                        }
                    printf(" (1) The shopkeeper\n");
                    printf(" (2) The Scholar\n");
                    printf("\nYour choice: ");
                    }
                }
            else if (choice == 2)
                {
                printf("\n\nYou ask the mayor for directions to leave the city.\n");
                Sleep(1000);
                printf("Mayor: 'If you are looking to leave, speak to the shopkeeper at the market square.\n");
                Sleep(1000);
                printf("\tHe is a wise man who knows the city's paths better than anyone else.'\n\n");
                printf("So you are going to meet the shopkeeper.\n\n");
                shopkeeperEncounter(); // Call shopkeeper function to continue the interaction
                }
            else if (choice == 3)
                {
                printf("\n\nYou politely decline the mayor's offer and decide to move on.\n");
                Sleep(1000);
                printf("The mayor nods and wishes you well on your journey.\n\n");

                int encounterChoice = rand() % 2; // Randomly choose 0 or 1 for shopkeeper or scholar

                if (encounterChoice == 0)
                    {
                    printf("\n\nAs you leave, you see a friendly shopkeeper standing by a stall in the market.\n");
                    Sleep(1000);
                    shopkeeperEncounter();
                    }
                else
                    {
                    printf("\n\nAs you leave, you notice a wise-looking scholar near the library.\n");
                    Sleep(1000);
                    scholarEncounter();
                    }
                }
            break; // Break out of the main choice loop if a valid choice was made
            }
        else
            {
            // Invalid choice within main options
            attempts++;
            if (attempts >= 3)
                {
                printf("\nToo many invalid attempts! The mayor looks disappointed.\n");
                Sleep(1000);
                printf("He dismisses you from the city.\n");
                gameOver();
                return;
                }
            printf("\nInvalid choice! Please choose again:\n");

            }
        if (attempts >= 3)
            {
            printf("\nToo many invalid attempts! The mayor looks disappointed.\n");
            Sleep(1000);
            printf("He dismisses you from the city.\n");
            gameOver();
            return;
            }
        printf(" (1) Accept the quest to find the relic\n");
        printf(" (2) Ask for directions to leave the city\n");
        printf(" (3) Politely decline and move on\n");
        printf("\nYour choice: ");
        }
}


// Function to check if input contains only alphabetic characters
int isValidAnswer(char *answer)
{
    for (int i = 0; answer[i] != '\0'; i++)
        {
        if (!isalpha(answer[i]))
            {
            return 0;  // Invalid if a non-alphabetic character is found
            }
        }
    return 1;
}
void scholarEncounter()
{
    printf("Scholar: 'Greetings, seeker. Not many make it here.\n\t  To have your answers, you must prove your intellect with riddles from this library's depths.'\n");
    Sleep(1000);
    printf("Scholar: 'Answer correctly, and I shall share secrets to aid your journey.'\n");

    // Riddle 1
    char answer[50];
    int attempts = 0;

    printf("\nThe scholar gestures toward the library's entrance and presents the first riddle:\n\n");
    printf("Riddle: What has to be broken before you can use it?\n");

    while (attempts < 3)
        {
        printf("\nYour answer: ");
        scanf("%s",&answer);

        // Remove newline character if present
        size_t len = strlen(answer);
        if (len > 0 && answer[len - 1] == '\n')
            {
            answer[len - 1] = '\0';
            }
        else
            {
            // If input was longer than buffer, clear remaining characters
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            }

        // If the answer is too long, reject it directly
        if (strlen(answer) > 20)
            {
            printf("\nScholar: 'Your answer is too long. Please give a meaningful answer using only letters and within five characters.'\n");
            attempts++;
            if (attempts < 3)
                {
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            else
                {
                printf("\nThe scholar shakes his head, disappointed in your failure.\n");
                gameOver();
                return;
                }
            continue;
            }


        toLowerCase(answer);

        if (!isValidAnswer(answer))
            {
            if (attempts<2)
                {
                printf("\nScholar: 'Please give a meaningful answer using only letters.'\n");
                attempts++;
                printf("Attempts remaining: %d\n", 3 - attempts);


                continue;  // Re-prompt for valid input
                }
            }

        if (strcmp(answer, "egg") == 0)
            {
            printf("\nScholar: 'Correct! A promising start, traveler.'\n");
            break;
            }
        else
            {
            attempts++;
            if (attempts < 3)
                {
                printf("\nScholar: 'Don't quit. Try once more.'\n");
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            }
        }

    if (attempts == 3)
        {
        printf("\nThe scholar shakes his head, disappointed in your failure.\n");
        gameOver();
        return;
        }

    // Riddle 2
    attempts = 0;
    printf("\nThe scholar opens a grand tome, flipping through ancient pages.\n");
    printf("Scholar: 'Your journey is far from over. Here is your next test.'\n");
    printf("\nRiddle: I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?\n");

    while (attempts < 3)
        {
        printf("\nYour answer: ");
        scanf("%s",&answer);




        // Remove newline character if present
        size_t len = strlen(answer);
        if (len > 0 && answer[len - 1] == '\n')
            {
            answer[len - 1] = '\0';
            }
        else
            {
            // If input was longer than buffer, clear remaining characters
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            }

        // If the answer is too long, reject it directly
        if (strlen(answer) > 20)
            {
            printf("\nScholar: 'Your answer is too long. Please give a meaningful answer using only letters and within five characters.'\n");
            attempts++;
            if (attempts < 3)
                {
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            else
                {
                printf("\nThe scholar sighs, closing his tome. 'Alas, knowledge is not for everyone.'\n");
                gameOver();
                return;
                }
            continue;
            }




        toLowerCase(answer);

        if (!isValidAnswer(answer))
            {
            if (attempts<2)
                {
                printf("\nScholar: 'Please give a meaningful answer using only letters.'\n");
                attempts++;
                printf("Attempts remaining: %d\n", 3 - attempts);


                continue;  // Re-prompt for valid input
                }
            }

        if (strcmp(answer, "echo") == 0)
            {
            printf("\nScholar: 'Impressive. Many struggle with that one.'\n");
            break;
            }
        else
            {
            attempts++;
            if (attempts < 3)
                {
                printf("\nScholar: 'Think carefully, for the answer lies in silence.'\n");
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            }
        }

    if (attempts == 3)
        {
        printf("\nThe scholar sighs, closing his tome. 'Alas, knowledge is not for everyone.'\n");
        gameOver();
        return;
        }

    // Final Riddle
    attempts = 0;
    printf("\nWith a gleam of approval, the scholar poses the final question:\n");
    printf("Scholar: 'Only the truly wise reach this point. Answer correctly, and you shall pass.'\n");
    printf("\nRiddle: I am light as a feather, yet the strongest man cannot hold me for much longer than a minute. What am I?\n");

    while (attempts < 3)
        {
        printf("\nYour answer: ");
        scanf("%s",&answer);




        // Remove newline character if present
        size_t len = strlen(answer);
        if (len > 0 && answer[len - 1] == '\n')
            {
            answer[len - 1] = '\0';
            }
        else
            {
            // If input was longer than buffer, clear remaining characters
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            }

        // If the answer is too long, reject it directly
        if (strlen(answer) > 20)
            {
            printf("\nScholar: 'Your answer is too long. Please give a meaningful answer using only letters and within five characters.'\n");
            attempts++;
            if (attempts < 3)
                {
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            else
                {
                printf("\nThe scholar looks at you solemnly. 'I'm afraid your journey ends here, for now.'\n");
                gameOver();
                return;
                }
            continue;
            }




        toLowerCase(answer);

        if (!isValidAnswer(answer))
            {
            if (attempts<2)
                {
                printf("\nScholar: 'Please give a meaningful answer using only letters.'\n");
                attempts++;
                printf("Attempts remaining: %d\n", 3 - attempts);


                continue;  // Re-prompt for valid input
                }
            }

        if (strcmp(answer, "breath") == 0)
            {
            printf("\nScholar: 'You truly are a seeker of wisdom, worthy of these halls.'\n");
            Sleep(1000);
            printf("\nThe scholar reaches into his robes and pulls out an old, leather-bound map.\n");
            Sleep(1000);
            printf("Scholar: 'Take this map, traveler. It will lead you to the temple and from there you can leave this city.'\n");
            Sleep(1000);
            printf("Scholar: 'Go south until you reach the old fountain.\n\t  Then, take the path that veers left through the dense forest.\n\t  The temple lies hidden in the mist beyond the ancient stones.'\n");
            Sleep(1000);
            printf("Scholar: 'Beware, for the journey is filled with traps and trials.'\n");
            break;
            }
        else
            {
            attempts++;
            if (attempts < 3)
                {
                printf("\nScholar: 'No, but do not give up so easily.'\n");
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            }
        }

    if (attempts == 3)
        {
        printf("\nThe scholar looks at you solemnly. 'I'm afraid your journey ends here, for now.'\n");
        gameOver();
        return;
        }

    printf("\nWith the ancient map and directions in mind, you leave the library,\nfeeling wiser and more prepared for the journey to the temple ahead.\n");
    temple();
}


void shopkeeperEncounter()
{
    printf("Shopkeeper: 'Ah, greetings, traveler! I see you have made your way here after speaking with the mayor.'\n");
    Sleep(1000);
    printf("Shopkeeper: 'I know the best routes to leave the city.\n\t     But before I give you directions, I could use your help with something.'\n");
    Sleep(1000);
    printf("Shopkeeper: 'There is a small delivery I need to make to the innkeeper at the west end of the city.\n\t     Would you be willing to help me with that?'\n");
    printf("\nWhat will you do?\n");
    printf("  (1) Yes, I will help you with the delivery.\n");
    printf("  (2) No, I just want directions to leave the city.\n");
    printf("\nYour choice: ");

    int choice;
    int attempts = 0; // Count invalid attempts

    while (1)
        {
        if (scanf("%d", &choice) != 1)
            {
            // Clear invalid input
            while (getchar() != '\n'); // Clear the buffer
            printf("\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;
            }
        else if (choice == 1)
            {
            printf("\n\nYou agree to help the shopkeeper with the delivery.\n\n");
            Sleep(1000);
            printf("Shopkeeper: 'Thank you! Take this package to the innkeeper at the west end of town.'\n");
            Sleep(1000);
            printf("\nYou take the package and head towards the inn.\n");
            printf("\nYou successfully deliver the package to the innkeeper.\n");
            Sleep(1000);
            printf("Innkeeper: 'Thank you for bringing this! I've been waiting for this delivery.'\n\n");
            Sleep(1000);
            printf("You return to the shopkeeper after completing the task.\n");
            Sleep(1000);
            printf("Shopkeeper: 'Thank you for your help. Now, as promised, I'll show you the way out of the city.\n\t     First of all you have to reach the temple...'\n");
            Sleep(1000);
            printf("Shopkeeper: 'To reach the temple, go south until you reach the old fountain.\n\t     From there, take the path that veers left through the dense forest.\n\t     The temple lies hidden in the mist beyond the ancient stones.'\n");
            Sleep(1000);
            printf("Shopkeeper: 'Once you've visited the temple, the path to leave the city will be revealed.'\n");
            Sleep(1000);
            printf("You now have directions to leave the city!\n\n");
            Sleep(1000);
            printf("\n\nYou leave the shop with the directions to the temple.\n\n");
            temple();
            break;
            }
        else if (choice == 2)
            {
            printf("\n\nYou decline to help the shopkeeper and simply ask for directions to leave the city.\n\n");
            Sleep(1000);
            printf("Shopkeeper: 'Alright, if you insist.\n\t     First of all you have to reach the temple...\n\t     To reach the temple, go south until you reach the old fountain.\n\t     Then, take the path that veers left through the dense forest.\n\t     The temple lies hidden in the mist beyond the ancient stones.'\n");
            Sleep(1000);
            printf("Shopkeeper: 'Once you've visited the temple, the path to leave the city will be revealed.'\n");
            Sleep(1000);
            printf("\nYou leave the shop with the directions to the temple.\n\n");
            temple();
            break;
            }
        else
            {
            // Invalid numeric choice
            attempts++;
            if (attempts >= 3)
                {
                printf("\nToo many invalid attempts! The shopkeeper is growing impatient.\n");
                Sleep(1000);
                printf("He dismisses you from the shop.\n");
                gameOver();
                return;
                }
            printf("\nInvalid choice! Please choose 1 or 2:\n");

            }
        if (attempts >= 3)
            {
            printf("\nToo many invalid attempts! The shopkeeper is growing impatient.\n");
            Sleep(1000);
            printf("He dismisses you from the shop.\n");
            gameOver();
            return;
            }
        printf("  (1) Yes, I'll help you with the delivery.\n");
        printf("  (2) No, I just want directions to leave the city.\n");
        printf("\nYour choice: ");
        }
}

void toLowerCase(char str[])
{
    for (int i=0; str[i]!='\0'; i++)
        {
        str[i]=tolower(str[i]);
        }
}



void temple()
{
    printf("\nYou reach the temple and find an ancient, mysterious doorway.\n");
    Sleep(1000);
    printf("The door has a strange symbol and seems to require solving a puzzle to open.\n");
    printf("\nSolve this puzzle to enter:\n");
    printf("\nPuzzle: I am a five-letter word. I get shorter when you add two letters to me. What am I?\n");
    printf("\nYour Answer: ");

    char puzzleAnswer[50];
    int attempts = 0;
    int solved = 0;

    // Puzzle Attempt Loop
    while (attempts < 3)
        {
        scanf("%s",&puzzleAnswer);

        // Remove newline character if present
        size_t len = strlen(puzzleAnswer);
        if (len > 0 && puzzleAnswer[len - 1] == '\n')
            {
            puzzleAnswer[len - 1] = '\0';
            }
        else
            {
            // If input was longer than buffer, clear remaining characters
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            }

        // If the answer is too long, reject it directly
        if (strlen(puzzleAnswer) > 20)
            {
            printf("\nScholar: 'Your answer is too long. Please give a meaningful answer using only letters and within five characters.'\n");
            attempts++;
            if (attempts < 3)
                {
                printf("Attempts remaining: %d\n", 3 - attempts);
                }
            else
                {
                printf("\nAfter three failed attempts, the door remains shut, and a dark silence surrounds you.\n");
                gameOver();
                return;
                }
            continue;
            }


        toLowerCase(puzzleAnswer);

        // Check if answer is only alphabetic
        if (!isValidAnswer(puzzleAnswer))
            {
            printf("\nScholar: 'Please give a meaningful answer using only letters.'\n");
            attempts++;
            if (attempts < 3)
                printf("Attempts remaining: %d\n\nYour Answer: ", 3 - attempts);
            else
                {
                printf("\nAfter three failed attempts, the door remains shut, and a dark silence surrounds you.\n");
                gameOver();  // End game if all attempts are used
                return;
                }
            continue;  // Re-prompt for valid input
            }

        // Check if answer is correct
        if (strcmp(puzzleAnswer, "short") == 0)
            {
            printf("\nCorrect! The ancient door trembles and slowly creaks open, inviting you inside.\n");
            solved = 1;
            break;  // Exit loop if puzzle is solved
            }
        else
            {
            attempts++;
            if (attempts < 3)
                {
                printf("\nIncorrect answer! You feel a cold shiver as the temple seems to judge your every move.\n");
                printf("You have %d attempt left.\n\nYour Answer: ", 3 - attempts);
                }
            else
                {
                printf("\nAfter three failed attempts, the door remains shut, and a dark silence surrounds you.\n");
                gameOver();  // End game if all attempts are used
                return;
                }
            }
        }

    // Proceed only if puzzle is solved
    if (solved)
        {
        printf("\nAs you step inside, dim torchlights illuminate a winding pathway filled with traps and narrow edges.\n\n");
        Sleep(1000);
        printf("You see two potential routes ahead:\n");
        Sleep(1000);
        printf("  (1) A risky but direct route that requires you to run and jump across a series of broken stone platforms.\n");
        Sleep(1000);
        printf("  (2) A safer, more cautious path with narrow ledges that you can carefully step across.\n\n");
        Sleep(1000);

        int parkourChoice;
        attempts = 0; // Reset attempts for parkour choice

        printf("What will you choose? (1 or 2): ");

        while (1)
            {
            if (scanf("%d", &parkourChoice) != 1)
                {
                // Clear invalid input
                while (getchar() != '\n'); // Clear the buffer
                printf("\nInvalid input!");
                if (attempts>-1&&attempts<2)
                    printf("Please enter a valid number.\n");
                else printf("\n");
                attempts++;

                }
            else if (parkourChoice == 1)
                {
                printf("\nYou decide to take the daring route and brace yourself for the first jump.\n");
                Sleep(1000);
                printf("You sprint towards the edge, take a leap of faith, and barely make it to the next platform.\n");
                Sleep(1000);
                printf("The ground beneath you is unstable, crumbling with each step, but you push forward.\n");
                Sleep(1000);
                printf("With one last, determined leap, you land on solid ground, panting but victorious.\n");
                break;
                }
            else if (parkourChoice == 2)
                {
                printf("\nChoosing the cautious path, you carefully balance on the narrow ledges, feeling the depth of the chasm below.\n");
                Sleep(1000);
                printf("Every step requires focus, as the ledges are slick with moss and uneven stone.\n");
                Sleep(1000);
                printf("Halfway across, you stumble but manage to regain your balance. A deep breath steadies you.\n");
                Sleep(1000);
                printf("After a tense few minutes, you reach the end of the path, relieved and grateful for your steady approach.\n");
                break;
                }
            else
                {
                printf("\nYou hesitate, unsure of what to do, and lose your footing...\n");
                Sleep(1000);
                printf("The ground crumbles beneath you, and you fall into the abyss below.\n");
                gameOver();  // End game invalid choice
                return;
                }
            if (attempts >= 3)
                {
                printf("\nToo many invalid attempts! You lose your footing and fall into the abyss below.\n");
                gameOver();
                return;
                }
            printf("What will you choose? (1 or 2): ");
            }

        printf("\nYou've successfully navigated through the temple's challenges, and the path ahead is now open.\n");
        Sleep(1000);
        printf("You step forward, ready to face whatever awaits you on the other side of the gate.\n\n");

        // Proceed to enemy encounter
        enemyEncounter();
        }
}



void enemyEncounter()
{
    printf("\nYou step through the gate and find yourself in an ancient courtyard surrounded by crumbling statues.\n");
    Sleep(1000);
    printf("The air feels thick with an oppressive silence as you take a few cautious steps forward.\n");
    Sleep(1000);
    printf("Suddenly, a towering figure clad in ancient armor appears.\n");
    Sleep(1000);
    printf("It's the Temple Warden, wielding a massive spear and shield.\n");
    Sleep(1000);
    printf("The Warden's eyes glow with a fierce light as it speaks, 'Only those deemed worthy may proceed.'\n");
    Sleep(1000);

    int choice;
    int attempts = 0;

    printf("\nYou have two options:\n");
    printf("1. Engage the Warden in combat, fighting with all your might.\n");
    printf("2. Observe the Warden, looking for any weakness.\n");
    printf("\nChoose your action (1 or 2): ");

    while (1)
        {
        if (scanf("%d", &choice) != 1)
            {
            // Clear invalid input
            while (getchar() != '\n'); // Clear the buffer
            printf("\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;

            }
        else if (choice == 1)
            {
            printf("\nYou charge at the Warden with all your strength, but it effortlessly deflects your attacks.\n");
            Sleep(1000);
            printf("With a swift counterattack, the Warden overpowers you, and you fall to the ground.\n");
            Sleep(1000);
            printf("You have met an unfortunate end.\n");
            gameOver();
            return;
            }
        else if (choice == 2)
            {
            printf("\nYou decide to study the Warden's movements, watching as it shifts its stance.\n");
            Sleep(1000);
            printf("After a few tense moments, you notice a gap in its armor near the shoulder.\n");
            Sleep(1000);
            printf("With precision and agility, you exploit the weakness, delivering a decisive blow!\n");
            Sleep(1000);
            printf("The Warden lets out a final roar, dropping its spear as it fades into the shadows, defeated.\n");
            Sleep(1000);
            printf("The path ahead is now clear.\n");
            Sleep(1000);
            ancientBeingEncounter();
            break;
            }
        else
            {
            printf("\nYour hesitation leaves you vulnerable, and the Warden seizes the opportunity.\n");
            Sleep(1000);
            printf("In a single, powerful strike, the Warden defeats you.\n");
            gameOver();  // End game if an invalid choice is made
            return;


            }
        if (attempts >= 3)
            {
            printf("\nToo many invalid attempts! Your hesitation leaves you vulnerable, and the Warden seizes the opportunity.\n");
            Sleep(1000);
            printf("In a single, powerful strike, the Warden defeats you.\n");
            gameOver();  // End game after too many invalid attempts
            return;
            }
        printf("\nChoose your action (1 or 2): ");
        }
}



void ancientBeingEncounter()
{
    printf("\nAs you move forward, the air grows still, and a mystical presence surrounds you.\n");
    Sleep(1000);
    printf("A towering figure shrouded in an ethereal light appears '' it's the Ancient Guardian of Knowledge.''\n");
    Sleep(1000);
    printf("The Guardian's voice echoes, 'Only those who possess wisdom may pass. Answer my riddles to proceed.'\n");
    Sleep(1000);

    //array oof questions and answers
    const char* questions[3] =
        {
        "I eat but am never full. I drink, yet I am always thirsty. What am I?",
        "I'm tall when I'm young, and I'm short when I'm old. What am I?",
        "The more of this there is, the less you see. What is it?"
        };
    const char* answers[3] = { "fire", "candle", "darkness" };

    int solved = 1;  // Flag to check if all riddles are solved
    char playerAnswer[50];
    int attempts;

    // Loop through each question
    for (int i = 0; i < 3; i++)
        {
        attempts = 0;
        printf("\nRiddle %d: %s\n", i + 1, questions[i]);

        // Loop for up to 3 attempts per riddle
        while (attempts < 3)
            {
            printf("\nYour Answer: ");
            scanf("%s",&playerAnswer);


            // Remove newline character if present
            size_t len = strlen(playerAnswer);
            if (len > 0 && playerAnswer[len - 1] == '\n')
                {
                playerAnswer[len - 1] = '\0';
                }
            else
                {
                // If input was longer than buffer, clear remaining characters
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                }

            // If the answer is too long, reject it directly
            if (strlen(playerAnswer) > 20)
                {
                printf("\nScholar: 'Your answer is too long. Please give a meaningful answer using only letters and within five characters.'\n");
                attempts++;
                if (attempts < 3)
                    {
                    printf("Attempts remaining: %d\n", 3 - attempts);
                    }
                else
                    {
                    printf("\nAfter three failed attempts, the door remains shut, and a dark silence surrounds you.\n");
                    gameOver();
                    return;
                    }
                continue;
                }

            toLowerCase(playerAnswer);

            if (strcmp(playerAnswer, answers[i]) == 0)
                {
                printf("\nCorrect!");
                if (i>-1&&i<2)
                    {
                    printf("Here your next riddel...\n");
                    }
                Sleep(1000);
                break;
                }
            else
                {
                attempts++;
                printf("\nIncorrect! You have %d attempt remaining.\n", 3 - attempts);
                }
            }

        if (attempts == 3)
            {
            solved = 0;
            printf("\nThe Guardian shakes its head in disappointment. 'You lack the wisdom to continue.'\n");
            gameOver();  // End the game if the player fails to answer the riddle
            return;
            }
        }

    // If all riddles are answered correctly
    if (solved)
        {
        printf("\n\nThe Guardian nods approvingly. 'You have answered wisely. Proceed to your destiny.'\n");
        Sleep(1000);
        printf("You feel a surge of energy as the Guardian fades, leaving the path clear for you.\n");
        Sleep(1000);
        gameWon=1;
        reachingHome();
        }

}
void reachingHome()
{
    printf("\nAfter overcoming every challenge, you find yourself at the edge of a dense forest.\n");
    Sleep(1000);
    printf("A warm light glows in the distance, and you realize it's your world, with the city waiting for your return.\n");
    Sleep(1000);
    printf("The familiar path feels different after your journey, each step filled with the knowledge and strength you've gained.\n");
    Sleep(1000);

    printf("\nAs you approach your city, people gather to welcome you back.\n");
    Sleep(1000);
    printf("Their faces light up with pride and joy, celebrating your courage and wisdom.\n");
    Sleep(1000);
    printf("You have completed your adventure and returned home as a hero.\n\n");
    Sleep(1000);

    printf("Congratulations! You have successfully completed the game and reached home. Well done!\n");
    gameOver();
}


void gameOver()
{
    int playAgain;
    int attempts = 0;

    if (gameWon == 1)
        {
        printf("\nThank You For Playing\n\n");
        printf("Game Over!\n\n");
        Sleep(1000);
        printf(".....................................................\n\n");
        printf("Do you want to play again?\n");
        printf("  (1) Yes\n");
        printf("  (2) No\n");
        printf("\nYour choice: ");
        }
    else
        {
        printf("Game Over! Try again next time.\n\n");
        Sleep(1000);
        printf("Do you want to play again?\n");
        printf("  (1) Yes\n");
        printf("  (2) No\n");
        printf("\nYour choice: ");
        }

    // Validate input for play again choice
    while (1)
        {
        if (scanf("%d", &playAgain) != 1)
            {
            while (getchar() != '\n'); // Clear buffer
            printf("\n\nInvalid input!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;
            }
        else if (playAgain == 1 || playAgain == 2)
            {
            break; // Exit loop if valid choice
            }
        else
            {
            printf("\nInvalid choice!");
            if (attempts>-1&&attempts<2)
                printf("Please enter a valid number.\n");
            else printf("\n");
            attempts++;
            }

        if (attempts >= 3)
            {
            printf("\nToo many invalid attempts. Exiting the game.\n");
            exit(0); // Exit the game after 3 invalid attempts
            }

        printf("  (1) Yes\n");
        printf("  (2) No\n");
        printf("\nYour choice: ");
        }

    printf("\n");

    if (playAgain == 1)
        {
        resetGame(); // Reset game state if the player wants to play again
        startGame(); // Restart the game from the beginning
        }
    else
        {
        exit(0); // Exit the game if the player does not choose to restart
        }
}


void resetGame()
{
    mistyRiverVisited = 0; // Reset Misty River visit tracking
    returnedToFork = 0;    // Reset return-to-fork flag
    gameWon=0;             //rest the game won to 0
    printf("\n\nRestarting the game...\n\n");
    Sleep(1000);
}

