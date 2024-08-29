#include <iostream>
#include <ctime>

void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);


    return 0;
}

void drawBoard(char* spaces)
{
    std::cout << '\n';
    for (int i = 0; i < 9; i += 3)
    {
        std::cout << "     |     |     " << '\n';
        std::cout << "   " << spaces[i] << " |   " << spaces[i + 1] << " |   " << spaces[i + 2] << '\n';
        if (!(i > 3))
        {
            std::cout << "_____|_____|_____" << '\n';
        }
    }
    
    std::cout << '\n';
}

void playerMove(char* spaces, char player)
{
}

void computerMove(char* spaces, char computer)
{
}

bool checkWinner(char* spaces, char player, char computer)
{
    return 0;
}

bool checkTie(char* spaces)
{
    return 0;
}
