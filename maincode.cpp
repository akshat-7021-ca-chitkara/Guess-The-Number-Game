#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GuessTheNumberGame
{
private:
    int computerGeneratedNumber; // Stores the randomly generated number
    int userGuessedNumber; // Stores the user's guessed number
    int maxAttempts; // User-defined maximum allowed attempts

public:
    // Constructor: Initializes the game by generating a random number and getting user input for attempts
    GuessTheNumberGame()
    {
        srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
        generateRandomNumber(); // Generate a random number
        getUserAttempts(); // Get user-defined maximum attempts
    }

    // Generates a random number between 1 and 100
    void generateRandomNumber()
    {
        computerGeneratedNumber = rand() % 100 + 1;
    }

    // Gets the desired number of attempts from the user
    void getUserAttempts()
    {
        cout << "Enter the number of attempts you want: \n";
        cout << "At most of the time a user needs minimum of 6 attempts to won the game.\n";
        cin >> maxAttempts;
    }

    // Starts the game loop
    void startTheGame()
    {
        int attempts = 0; // Counter for attempts made by the user

        while (attempts < maxAttempts)
        {
            attempts++;
            cout << "Attempt " << attempts << ": Guess the number (between 1 and 100): \n";
            cin >> userGuessedNumber;

            if (userGuessedNumber < computerGeneratedNumber)
            {
                cout << "Guessed number is smaller than the computer-generated number.\n";
            }
            else if (userGuessedNumber > computerGeneratedNumber)
            {
                cout << "Guessed number is greater than the computer-generated number.\n";
            }
            else
            {
                cout << "Congratulations! You won the game in " << attempts << " attempts.\n";
                cout << "Your score is " << attempts << ".\n";
                return; // Exit the loop if the user guesses correctly
            }
        }

        cout << "You lose! The correct number was " << computerGeneratedNumber << ". Better luck next time!\n";
    }
};

int main()
{
    GuessTheNumberGame game; // Create an instance of the game
    game.startTheGame(); // Start the game loop
    return 0;
}
