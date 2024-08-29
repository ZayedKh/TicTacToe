#include <iostream>
#include <ctime>
#include <wchar.h>

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

    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
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
    }
    while (!number > 0 || !number < 8);
}

void computerMove(char* spaces, char computer)
{
    int number;
    srand(time(nullptr) + getpid());

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            std::cout << "Computer chose: " << number + 1 << '\n';
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char* spaces, char player, char computer)
{
    // this loop will check each row
    for (int i = 0; i < 9; i += 3)
    {
        if (spaces[i] == 'X')
        {
            if (spaces[i] == spaces[i + 1] && spaces[i + 1] == spaces[i + 2])
            {
                return true;
            }
        }
        else if (spaces[i] == 'O')
        {
            if (spaces[i] == spaces[i + 1] && spaces[i + 1] == spaces[i + 2])
            {
                return true;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (spaces[i] == 'X')
        {
            if (spaces[i] == spaces[i + 3] && spaces[i+3] == spaces[i + 6])
            {
                return true;
            }
        }
        else if (spaces[i] == 'O')
        {
            if (spaces[i] == spaces[i + 3] && spaces[i+3] == spaces[i + 6])
            {
                return true;
            }
        }
    }


    return false;
}

bool checkTie(char* spaces)
{
    return false;
}
