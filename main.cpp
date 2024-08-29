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

    while (running){
        playerMove(spaces, player);
        drawBoard(spaces);
    }

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
    int number;
    do
    {
        std::cout << "Enter a spot to place your marker (1-9)";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }

    }while (!number > 0 || !number < 8);


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
