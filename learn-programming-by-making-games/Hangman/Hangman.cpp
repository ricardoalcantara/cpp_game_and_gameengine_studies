#include <iostream>
#include <cstring>

void PlayGame();
bool WantToPlayAgain();

const char* GetSecretPhrase();
char* MakeHiddenPhrase(const char* secretPhrase);
char GetGuess();
void UpdateBoard(char guess, const char* secretPhrase, char* hiddenPhrase, int* numberOfGuessesLeft);
void DrawBoard(const char* hiddenPhrase, int numberOfGuessesLeft);
bool GameIsOver(const char* secretPhrase,const char* hiddenPhrase, int numberOfGuessesLeft);
void DisplayResult(const char* secretPhrase, int numberOfGuessesLeft);


int main(int argc, char const *argv[])
{
    // we need a way of storing the secret phrase
    // we need a way of storing the hidden phrase
    // we need a variable that holds the numver of guesses left (set to 8 intially)
    do {
        PlayGame();

    } while(WantToPlayAgain());

    return 0;
}

void PlayGame() 
{
    const int numberOfGuessesLeft = 6;
    const char* _opSecretPhrase = GetSecretPhrase();
    char* _opHhiddenPhrase = MakeHiddenPhrase(_opSecretPhrase);

    DrawBoard(_opHhiddenPhrase, numberOfGuessesLeft);
    char guess;
    do 
    {
        guess = GetGuess();
        UpdateBoard(guess, _opSecretPhrase, _opHhiddenPhrase, &numberOfGuessesLeft);
        DrawBoard(_opHhiddenPhrase, numberOfGuessesLeft);
    } while (!GameIsOver(_opSecretPhrase, _opHhiddenPhrase, numberOfGuessesLeft));

    DisplayResult(_opSecretPhrase, numberOfGuessesLeft);

    delete _opSecretPhrase;
    delete _opHhiddenPhrase;
}

bool WantToPlayAgain()
{
    char want[4];
    std::cout << "Want to play again? [(y)es/(n)o]" << std::endl;
    std::cin >> want;
    return want == "yes" || want[0] == 'y';
}

const char* GetSecretPhrase()
{
    char* word = new char;

    std::cout << "Type the secret word " << std::endl;
    std::cin >> word;

    return word;
}

char* MakeHiddenPhrase(const char* secretPhrase)
{
    int length = strlen(secretPhrase);
    char* hidden = new char[length];
    for (int i = 0; i < length; i++)
    {
        hidden[i] = '_';
    }

    hidden[length] = '\0';
    return hidden;
}

char GetGuess()
{
    char c;
    std::cout << "Type a letter" << std::endl;
    std::cin >> c;
    return c;
}

void UpdateBoard(char guess, const char* secretPhrase,char* hiddenPhrase, int* numberOfGuessesLeft)
{
    int length = strlen(secretPhrase);
    bool wasAGoodGuess = false;
    for (int i = 0; i < length; i++)
    {
        if (secretPhrase[i] == guess)
        {
            wasAGoodGuess = true;
            hiddenPhrase[i] = guess;
        }
    }

    if (!wasAGoodGuess)
    {
        *numberOfGuessesLeft -= 1;
    }
}

void DrawBoard(const char* hiddenPhrase, int numberOfGuessesLeft)
{
    std::cout << "\t" << " +---+" << std::endl;
    std::cout << "\t" << " |" << std::endl;
    std::cout << "\t" << " |" << std::endl;
    std::cout << "\t" << " |" << std::endl;
    std::cout << "\t" << " |" << std::endl;
    std::cout << "\t" << "-+-" << std::endl ;
    std::cout << "You have " << numberOfGuessesLeft << " letter left" << std::endl ;
    
    int length = strlen(hiddenPhrase);
    for (int i = 0; i < length; i++)
    {
        std::cout << hiddenPhrase[i] << " ";
    }
    
    std::cout << "\n" << std::endl ;
}

bool GameIsOver(const char* secretPhrase, const char* hiddenPhrase, int numberOfGuessesLeft)
{
    bool hasDash = false;
    for (int i = strlen(hiddenPhrase) - 1; i >= 0; i--)
    {
        if (hiddenPhrase[i] == '_')
        {
            hasDash = true;
            break;
        }
    }
    
    return !hasDash || numberOfGuessesLeft == 0;
}

void DisplayResult(const char* secretPhrase, int numberOfGuessesLeft)
{
    if (numberOfGuessesLeft > 0)
    {
        std::cout << "Contrats" << std::endl;
    }
    else
    {
        std::cout << "Looser" << std::endl;
    }

    std::cout << "The secret phrase is " << secretPhrase << std::endl;
}
