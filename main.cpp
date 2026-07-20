#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

string getChoiceName(int choice)
{
    if (choice == 1)
        return "Rock";
    else if (choice == 2)
        return "Paper";
    else
        return "Scissors";
}

string findWinner(int player, int computer)
{
    if (player == computer)
        return "It's a Draw!";

    if ((player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2))
        return "You Win!";

    return "Computer Wins!";
}

struct Match
{
    string playerMove;
    string computerMove;
    string result;
};

int main()
{
    srand(time(0));

    int playerScore = 0;
    int computerScore = 0;
    int drawScore = 0;

    Match history[100];
    int matchCount = 0;

    int playerChoice;
    char playAgain;
    ofstream file("history.txt");
    if (!file)
{
    cout << "Error: Could not create history.txt" << endl;
    return 1;
}

    do
{

    cout << "=============================\n";
    cout << " ROCK PAPER SCISSORS GAME\n";
    cout << "=============================\n";

    cout << "\nChoose:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";



    int computerChoice = rand() % 3 + 1;

    cout << "\nYou selected: " << getChoiceName(playerChoice) << endl;
    cout << "Computer selected: " << getChoiceName(computerChoice) << endl;

    cout << "\nEnter your choice: ";

while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > 3)
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Invalid choice! Please enter 1, 2, or 3: ";
}

 string result = findWinner(playerChoice, computerChoice);

cout << "\nResult: " << result << endl;

history[matchCount].playerMove = getChoiceName(playerChoice);
history[matchCount].computerMove = getChoiceName(computerChoice);
history[matchCount].result = result;

matchCount++;

file << "Match " << matchCount << endl;
file << "Player   : " << getChoiceName(playerChoice) << endl;
file << "Computer : " << getChoiceName(computerChoice) << endl;
file << "Result   : " << result << endl;
file << "--------------------------" << endl;


if (result == "You Win!")
{
    playerScore++;
}
else if (result == "Computer Wins!")
{
    computerScore++;
}
else
{
    drawScore++;
}
cout << "\n=============================\n";
cout << "        SCORE BOARD\n";
cout << "=============================\n";
cout << "Player Wins   : " << playerScore << endl;
cout << "Computer Wins : " << computerScore << endl;
cout << "Draws         : " << drawScore << endl;
cout << "\n========== MATCH HISTORY ==========\n";

for (int i = 0; i < matchCount; i++)
{
    cout << "\nMatch " << i + 1 << endl;
    cout << "Player Choice   : " << history[i].playerMove << endl;
    cout << "Computer Choice : " << history[i].computerMove << endl;
    cout << "Result          : " << history[i].result << endl;
}

cout << "===================================\n";

cout << "\nPlay Again? (Y/N): ";
cin >> playAgain;

} while (playAgain == 'Y' || playAgain == 'y');

file.close();

return 0;
}