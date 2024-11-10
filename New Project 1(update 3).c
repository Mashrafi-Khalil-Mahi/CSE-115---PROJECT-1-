
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
void shopkeeperEncounter();
void temple();
void toLowerCase(char str[]);


// Global variables to track game state
int mistyRiverVisited = 0; // ekhane hisab kore rakhtese je age kono bar river option dise naki
int returnedToFork = 0;    // ekhane dekhtese je abr prothome back asche naki

int main() {
    srand(time(NULL));//for random number
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
    printf("\nEnter your answer: ");

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
                gameOver();
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
            printf("\nYou arrive at the entrance of a towering, ancient library.\n");
            Sleep(2000);
            printf("The vast stone steps lead up to grand doors etched with symbols from lost ages.\n");
            Sleep(2000);
            printf("Near the doors, a wise-looking scholar stands, as if waiting for you.\n");
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
    printf("Mayor: 'I have a proposition for you. There's an old relic lost in the nearby forest.\n");
    Sleep(2000);
    printf("\tIf you retrieve it, I will reward you handsomely. Or if you have other questions, Feel free to ask.'\n\n");
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
            printf("\tBring the relic back to me, and you shall be rewarded.'\n\n");
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
            printf("Mayor: 'Now , What do you plan to do next?'\n");
            Sleep(2000);
            printf("\n\nYou replied that ''I would like to leave the city.''\n\n");
            Sleep(2000);
            printf("Mayor: 'Very well. I suggest you seek guidance from one of two people:\n");
            Sleep(2000);
            printf("\tThe shopkeeper at the market or the wise scholar near the library.\n");
            Sleep(2000);
            printf("\tEach may provide a different path.'\n\n");
            Sleep(2000);
            int choice1;
            printf("Who would you like to consult?\n");
            printf(" (1) The shopkeeper\n");
            printf(" (2) The Scholar\n");
            printf("\nYour choice: ");

            while(1)
            {
            scanf("%d",&choice1);
            if(choice1==1){
                printf("\n\nSo you choose to go to the shopkeeper.\n");
                Sleep(2000);
                printf("\n\nThe shopkeeper was standing by a stall in the market.\n\n");
                shopkeeperEncounter();
            }
            else if(choice1==2){
                printf("\n\nSo you choose to go to the scholar.\n");
                Sleep(2000);
                printf("\n\n The scholar was standing near the library as if he is waiting for you.\n\n");
                scholarEncounter();
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
        printf(" (1) The shopkeeper\n");
        printf(" (2) The Scholar\n");
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
        printf("\tHe is a wise man who knows the city is paths better than anyone else.'\n\n");
        printf("So you are going to meet the shoopkeepr\n\n");
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
            printf("\n\nAs you leave,");
            printf("You see a friendly shopkeeper standing by a stall in the market.\n");
            Sleep(2000);
            //call the shopkeeper function
            shopkeeperEncounter();
            break;
        }
        else
        {
            //player meets the scholar");
            printf("\n\nAs you leave, You notice a wise-looking scholar near the library.\n");
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
    printf("Scholar: 'Greetings, seeker. Not many make it here.\n\t  To have your answers, you must prove your intellect with riddles from this library's depths.'\n");
    Sleep(2000);
    printf("Scholar: 'Answer correctly, and I shall share secrets to aid your journey.'\n");

    // Riddle 1
    char answer[10];
    int attempts = 0;

    printf("\nThe scholar gestures toward the library's entrance and presents the first riddle:\n");
    printf("Riddle: What has to be broken before you can use it?\n");

    while (attempts < 3) {
        printf("\nYour answer: ");
        scanf("%s", answer);
        toLowerCase(answer);

        if (strcmp(answer, "egg") == 0) {
            printf("\nScholar: 'Correct! A promising start, traveler.'\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("\nScholar: 'Don't quite. Try once more.'\n");
                printf("Attempts left: %d\n", 3 - attempts);
            }
        }
    }

    if (attempts == 3) {
        printf("\nThe scholar shakes his head, disappointed in your failure.\n");
        gameOver();
        return;
    }

    // Riddle 2
    attempts = 0;
    printf("\nThe scholar opens a grand tome, flipping through ancient pages.\n");
    printf("Scholar: 'Your journey is far from over. Here is your next test.'\n");
    printf("\nRiddle: I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?\n");

    while (attempts < 3) {
        printf("\nYour answer: ");
        scanf("%s", answer);
        toLowerCase(answer);

        if (strcmp(answer, "echo") == 0) {
            printf("\nScholar: 'Impressive. Many struggle with that one.'\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("\nScholar: 'Think carefully, for the answer lies in silence.'\n");
                printf("Attempts left: %d\n", 3 - attempts);
            }
        }
    }

    if (attempts == 3) {
        printf("\nThe scholar sighs, closing his tome. 'Alas, knowledge is not for everyone.'\n");
        gameOver();
        return;
    }

    // Final Riddle
    attempts = 0;
    printf("\nWith a gleam of approval, the scholar poses the final question:\n");
    printf("Scholar: 'Only the truly wise reach this point. Answer correctly, and you shall pass.'\n");
    printf("\nRiddle: I am light as a feather, yet the strongest man can not hold me for much longer than a minute. What am I?\n");

    while (attempts < 3) {
        printf("\nYour answer: ");
        scanf("%s", answer);
        toLowerCase(answer);

        if (strcmp(answer, "breath") == 0) {
            printf("\nScholar: 'You truly are a seeker of wisdom, worthy of these halls.'\n");
            Sleep(2000);
            printf("\nThe scholar reaches into his robes and pulls out an old, leather-bound map.\n");
            Sleep(2000);
            printf("Scholar: 'Take this map, traveler. It will lead you to the temple and from there you can leave this city.'\n");
            Sleep(2000);
            printf("Scholar: 'Go south until you reach the old fountain.\n\t     Then, take the path that veers left through the dense forest.\n\t     The temple lies hidden in the mist beyond the ancient stones.\n");
            Sleep(2000);
            printf("Scholar: 'Beware, for the journey is filled with traps and trials.'\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("\nScholar: 'No, but do not give up so easily.'\n");
                printf("Attempts left: %d\n", 3 - attempts);
            }
        }
    }

    if (attempts == 3) {
        printf("\nThe scholar looks at you solemnly. 'I'm afraid your journey ends here, for now.'\n");
        gameOver();
        return;
    }

        printf("\nWith the ancient map and directions in mind, you leave the library,/nfeeling wiser and more prepared for the journey to the temple ahead.\n");
        temple();

}

void shopkeeperEncounter()
{

    printf("Shopkeeper: 'Ah, greetings, traveler! I see you have made your way here after speaking with the mayor.'\n");
    Sleep(2000);
    printf("Shopkeeper: 'I know the best routes to leave the city.\n\t     But before I give you directions, I could use your help with something.'\n");
    Sleep(2000);
    printf("Shopkeeper: 'There is a small delivery I need to make to the innkeeper at the west end of the city.\n\t     Would you be willing to help me with that?'\n");
    printf("\nWhat will you do?\n");
    printf("  (1) Yes, I will help you with the delivery.\n");
    printf("  (2) No, I just want directions to leave the city.\n");
    printf("\nYour choice: ");

    int choice;
    int attempts = 0;
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\n\nYou agree to help the shopkeeper with the delivery.\n\n");
            Sleep(2000);
            printf("Shopkeeper: 'Thank you! Take this package to the innkeeper at the west end of town.'\n");
            Sleep(2000);
            printf("\nYou take the package and head towards the inn.\n");
            printf("\nYou successfully deliver the package to the innkeeper.\n");
            Sleep(2000);
            printf("Innkeeper: 'Thank you for bringing this! I've been waiting for this delivery.'\n\n");
            Sleep(2000);
            printf("You return to the shopkeeper after completing the task.\n");
            Sleep(2000);
            printf("Shopkeeper: 'Thank you for your help. Now, as promised, I'll show you the way out of the city.\n\tFirst of all you have to reach the temple...'\n");
            Sleep(2000);
            printf("Shopkeeper: 'To reach the temple, go south until you reach the old fountain.\n\t     From there, take the path that veers left through the dense forest.\n\t     The temple lies hidden in the mist beyond the ancient stones.'\n");
            Sleep(2000);
            printf("Shopkeeper: 'Once you've visited the temple, the path to leave the city will be revealed.'\n");
            Sleep(2000);
            printf("You now have directions to leave the city!\n\n");
            Sleep(2000);
            printf("\n\nYou leave the shop with the directions to the temple.\n\n");
            temple();
            break;
        } else if (choice == 2) {
            printf("\n\nYou decline to help the shopkeeper and simply ask for directions to leave the city.\n\n");
            Sleep(2000);
            printf("Shopkeeper: 'Alright, if you insist.\n\t     First of all you have to reach the temple...\n\t     To reach the temple, go south until you reach the old fountain.\n\t     Then, take the path that veers left through the dense forest.\n\t     The temple lies hidden in the mist beyond the ancient stones.'\n");
            Sleep(2000);
            printf("Shopkeeper: 'Once you've visited the temple, the path to leave the city will be revealed.'\n");
            Sleep(2000);
            printf("\nYou leave the shop with the directions to the temple.\n\n");
            temple();
            break;
        } else {
            attempts++;
            if (attempts >= 3) {
                printf("\nToo many invalid attempts! The shopkeeper is growing impatient.\n");
                Sleep(2000);
                printf("He dismisses you from the shop.\n");
                gameOver(); // Call game over functio
                return;
            }
            printf("\nInvalid choice! Please choose 1 or 2:\n");
            printf("  (1) Yes, I'll help you with the delivery.\n");
            printf("  (2) No, I just want directions to leave the city.\n");
            printf("\nYour choice: ");
        }
    }

}
void toLowerCase(char str[])
{
    for(int i=0; str[i];i++)
    {
        str[i]=tolower(str[i]);
    }
}



void temple()
{
    printf("\nYou reach the temple and find an ancient, mysterious doorway.\n");
    Sleep(2000);
    printf("The door has a strange symbol and seems to require solving a puzzle to open.\n");
    printf("\nSolve this puzzle to enter:\n");
    printf("\nPuzzle: I am a five-letter word. I get shorter when you add two letters to me. What am I?\n");
    printf("\nYour Answer: ");
    char puzzleAnswer[10];
    int attempts = 0;
    int solved=0;

    while(attempts<3)
    {
         scanf("%s", puzzleAnswer);
         toLowerCase(puzzleAnswer);
         if (strcmp(puzzleAnswer, "short") == 0)
            {
            printf("\nCorrect! The ancient door trembles and slowly creaks open, inviting you inside.\n");
            solved=1;
            break;  // Exit loop if puzzle is
            }
            else
            {
            attempts++;
            if (attempts < 3)
                {
                    printf("\nIncorrect answer! You feel a cold shiver as the temple seems to judge your every move.\n");
                    printf("You have %d attempt(s) left.\n", 3 - attempts);
                    printf("\nYour Answer: ");
                }
            }
    }
    if (!solved) {
        printf("\nAfter three failed attempts, the door remains shut, and a dark silence surrounds you.\n");
        gameOver();  // End game if all attempts are used
        return;
    }

     // Parkour Challenge
    printf("\nAs you step inside, dim torchlights illuminate a winding pathway filled with traps and narrow edges.\n\n");
    Sleep(2000);
    printf("You see two potential routes ahead:\n");
    Sleep(2000);
    printf("  (1) A risky but direct route that requires you to run and jump across a series of broken stone platforms.\n");
    Sleep(2000);
    printf("  (2) A safer, more cautious path with narrow ledges that you can carefully step across.\n\n");
    Sleep(2000);

    int parkourChoice;
    printf("What will you choose? ( 1 or 2): ");
    scanf("%d", &parkourChoice);

    if (parkourChoice == 1) {
        printf("\nYou decide to take the daring route and brace yourself for the first jump.\n");
        Sleep(2000);
        printf("You sprint towards the edge, take a leap of faith, and barely make it to the next platform.\n");
        Sleep(2000);
        printf("The ground beneath you is unstable, crumbling with each step, but you push forward.\n");
        Sleep(2000);
        printf("With one last, determined leap, you land on solid ground, panting but victorious.\n");
    } else if (parkourChoice == 2) {
        printf("\nChoosing the cautious path, you carefully balance on the narrow ledges, feeling the depth of the chasm below.\n");
        Sleep(2000);
        printf("Every step requires focus, as the ledges are slick with moss and uneven stone.\n");
        Sleep(2000);
        printf("Halfway across, you stumble but manage to regain your balance. A deep breath steadies you.\n");
        Sleep(2000);
        printf("After a tense few minutes, you reach the end of the path, relieved and grateful for your steady approach.\n");
    } else {
        printf("\nYou hesitate, unsure of what to do, and lose your footing...\n");
        Sleep(2000);
        printf("The ground crumbles beneath you, and you fall into the abyss below.\n");
        gameOver();  // End game if an invalid choice causes the player to fail
        return;
    }

    printf("\nYou've successfully navigated through the temple's challenges.\n");
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

