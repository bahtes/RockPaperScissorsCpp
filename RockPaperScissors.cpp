// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>


enum string_code
{
    eRock,
    ePaper,
    eScrissors,
    eOther
};

string_code hashit(std::string const& inString)
{
    if (inString == "rock") return eRock;
    else if (inString == "paper") return ePaper;
    else if (inString == "scissors") return eScrissors;
    else return eOther;

}

int choose()
{
    std::string choiceS;
    std::cin >> choiceS;

    std::transform(choiceS.begin(), choiceS.end(), choiceS.begin(), [](unsigned char c)
        {
            return std::tolower(c); 
        }
    );

    switch (hashit(choiceS)) {
    case eRock:
        return 1;
        break;
    case ePaper:
        return 2;
        break;
    case eScrissors:
        return 3;
        break;
    default:
        std::cout << "\nIncorrect input try again\n\n";
        return choose();
        break;
    }

}

bool replay(std::string name)
{
    std::cout << "Enter 'Y' to replay or 'Q' to quit\n\n";
    char replayC;
    std::cin >> replayC;
    replayC = std::tolower(replayC);

    if (replayC == 'y')
    {
        std::cout << "\n";
        return true;
    }
    else if (replayC == 'q')
    {
        std::cout << "\nGoodbye " + name + "\n\n";
        return false;
    }
    else
    {
        std::cout << "\nIncorrect input, try again\n\n";
        replay(name);
    }
    return false;
}

void play(std::string name)
{
    std::cout << name + " enter your choice below: \n\n";

    int choiceI = choose();
    int Rchoice = rand() % 3 + 1;

    switch (Rchoice) {
    case 1:
        std::cout << "\nYour opponent has chosen: Rock";
        if (choiceI == 2)
        {
            std::cout << "\n\nWell done " + name + "! You have won.\n\n";
        }
        else if (choiceI == 3)
        {
            std::cout << "\n\nThough luck " + name + ". Your oppoent has won.\n\n";
        }
        else
        {
            std::cout << "\n\nA DRAW!\n\n";
        }
        break;
    case 2:
        std::cout << "\nYour opponent has chosen: Paper";
        if (choiceI == 3)
        {
            std::cout << "\n\nWell done " + name + "! You have won.\n\n";
        }
        else if (choiceI == 1)
        {
            std::cout << "\n\nThough luck " + name + ". Your oppoent has won.\n\n";
        }
        else
        {
            std::cout << "\n\nA DRAW!\n\n";
        }
        break;
    case 3:
        std::cout << "\nYour opponent has chosen: Scissors";
        if (choiceI == 1)
        {
            std::cout << "\n\nWell done " + name + "! You have won.\n\n";
        }
        else if (choiceI == 2)
        {
            std::cout << "\n\nThough luck " + name + ". Your oppoent has won.\n\n";
        }
        else
        {
            std::cout << "\n\nA DRAW!\n\n";
        }
        break;
    }
    
    if (replay(name))
    {
        play(name);
    }

}

int main()
{
    srand(time(0));
    std::string name;
    std::cout << "Welcome to Rock Paper Scissors, Enter your name to continue\n\n";
    std::cin >> name;
    std::cout << "\nHi ";

    play(name);
}
