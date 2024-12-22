#include <iostream>
#include <string>
using namespace std;

string names[100];

struct playersData {
    string playerName;
    int playerPosition = 1;
    int laddersClimbed = 0;
    int snakesEaten = 0;
};

struct gameData {
    int currentPlayer = 1;
    int ladders[8] = {4, 12, 21, 28, 36, 51, 71, 80};
    int snakes[9] = {16, 47, 49, 62, 64, 87, 93, 95, 98};
};

int getDiceRandom();
int getLadderEnd(int ladderStart);
int getSnakesStart(int snakeEnd);
bool checkLadder(gameData currentGameData, int playerPosition);
bool checkSnake(gameData currentGameData, int playerPosition);

void assignNames(playersData playerOne, playersData playerTwo);
void sendGameCell();
playersData getTopPlayer(playersData playerOne, playersData playerTwo);
void sendGameSummary(playersData playerOne, playersData playerTwo);

int main() {
    srand(time(0));

    playersData playerOne, playerTwo;
    gameData currentGameData;

    int diceNumber;
    cout << endl << endl << "\t\tWelcome to the SNAKES & LADDER game!" << endl << endl;

    do {
        cout << "Please enter the first player name shortcut (Maximum 6 characters): ";
        cin >> playerOne.playerName;
    } while (playerOne.playerName.length() > 6);

    do {
        cout << "Please enter the second player name shortcut (Maximum 6 characters): ";
        cin >> playerTwo.playerName;
    } while (playerTwo.playerName.length() > 6);
    cin.ignore();

    cout << endl << endl << "\t\tWelcome " << playerOne.playerName << " & " << playerTwo.playerName << " to SNAKES & LADDER!" << endl << endl;

    do {
        assignNames(playerOne, playerTwo);
        sendGameCell();

        switch (currentGameData.currentPlayer) {
            case 1: {
                cout << "[Player 1]: " << playerOne.playerName << " it's your turn! Press [ENTER] to roll the dice.";
                cin.ignore();

                diceNumber = getDiceRandom();
                playerOne.playerPosition += diceNumber;

                if (checkLadder(currentGameData, playerOne.playerPosition)) {
                    cout << "Nice! " << playerOne.playerName << " rolled " << diceNumber << " and is now on " << playerOne.playerPosition << " with a ladder!" << endl;
                    playerOne.playerPosition = getLadderEnd(playerOne.playerPosition);
                    cout << playerOne.playerName << " climbs the ladder to " << playerOne.playerPosition << endl;
                    playerOne.laddersClimbed++;
                } else if (checkSnake(currentGameData, playerOne.playerPosition)) {
                    cout << "Oops! " << playerOne.playerName << " rolled " << diceNumber << " and landed on a snake at " << playerOne.playerPosition << "." << endl;
                    playerOne.playerPosition = getSnakesStart(playerOne.playerPosition);
                    cout << playerOne.playerName << " slides down to " << playerOne.playerPosition << endl;
                    playerOne.snakesEaten++;
                } else {
                    cout << "Nice! " << playerOne.playerName << " rolled " << diceNumber << " and is now on " << playerOne.playerPosition << "." << endl;
                }

                currentGameData.currentPlayer = 2;
                break;
            }

            case 2: {
                cout << "[Player 2]: " << playerTwo.playerName << " it's your turn! Press [ENTER] to roll the dice.";
                cin.ignore();

                diceNumber = getDiceRandom();
                playerTwo.playerPosition += diceNumber;

                if (checkLadder(currentGameData, playerTwo.playerPosition)) {
                    cout << "Nice! " << playerTwo.playerName << " rolled " << diceNumber << " and is now on " << playerTwo.playerPosition << " with a ladder!" << endl;
                    playerTwo.playerPosition = getLadderEnd(playerTwo.playerPosition);
                    cout << playerTwo.playerName << " climbs the ladder to " << playerTwo.playerPosition << endl;
                    playerTwo.laddersClimbed++;
                } else if (checkSnake(currentGameData, playerTwo.playerPosition)) {
                    cout << "Oops! " << playerTwo.playerName << " rolled " << diceNumber << " and landed on a snake at " << playerTwo.playerPosition << "." << endl;
                    playerTwo.playerPosition = getSnakesStart(playerTwo.playerPosition);
                    cout << playerTwo.playerName << " slides down to " << playerTwo.playerPosition << endl;
                    playerTwo.snakesEaten++;
                } else {
                    cout << "Nice! " << playerTwo.playerName << " rolled " << diceNumber << " and is now on " << playerTwo.playerPosition << "." << endl;
                }

                currentGameData.currentPlayer = 1;
                break;
            }
        }
    } while (playerOne.playerPosition < 100 && playerTwo.playerPosition < 100);

    sendGameSummary(playerOne, playerTwo);

    system("pause");
    return 0;
}

int getLadderEnd(int ladderStart) {
    switch (ladderStart) {
        case 4: return 14;
        case 12: return 31;
        case 21: return 42;
        case 28: return 84;
        case 36: return 57;
        case 51: return 67;
        case 71: return 91;
        case 80: return 100;
        default: return ladderStart;
    }
}

int getSnakesStart(int snakeEnd) {
    switch (snakeEnd) {
        case 16: return 6;
        case 47: return 26;
        case 49: return 11;
        case 62: return 19;
        case 64: return 60;
        case 87: return 24;
        case 93: return 73;
        case 95: return 53;
        case 98: return 78;
        default: return snakeEnd;
    }
}

bool checkLadder(gameData currentGameData, int playerPosition) {
    for (int i = 0; i < 8; i++) {
        if (currentGameData.ladders[i] == playerPosition) return true;
    }
    return false;
}

bool checkSnake(gameData currentGameData, int playerPosition) {
    for (int i = 0; i < 9; i++) {
        if (currentGameData.snakes[i] == playerPosition) return true;
    }
    return false;
}

int getDiceRandom() {
    return (rand() % 6) + 1;
}

void sendGameCell() {
    cout << endl << endl << "\t\t\tHere is the game cell:" << endl;
    cout << "_______________________________________________________________________________" << endl;
    for (int i = 99; i >= 0; i--) {
        if (i % 10 == 9) cout << "| " << names[i] << " |" << endl;
        else cout << "| " << names[i] << " ";
    }
    cout << "_______________________________________________________________________________" << endl << endl;
}

void assignNames(playersData playerOne, playersData playerTwo) {
    for (int i = 0; i < 100; i++) names[i] = "";
    if (playerOne.playerPosition == playerTwo.playerPosition) {
        names[playerOne.playerPosition - 1] = playerOne.playerName + " & " + playerTwo.playerName + " (" + to_string(playerOne.playerPosition) + ")";
    } else {
        names[playerOne.playerPosition - 1] = playerOne.playerName;
        names[playerTwo.playerPosition - 1] = playerTwo.playerName;
    }
}

playersData getTopPlayer(playersData playerOne, playersData playerTwo) {
    return (playerOne.laddersClimbed > playerTwo.laddersClimbed) ? playerOne : playerTwo;
}

void sendGameSummary(playersData playerOne, playersData playerTwo) {
    cout << "\n\n\t\tGame Summary!" << endl;

    if (playerOne.laddersClimbed == playerTwo.laddersClimbed) {
        if (playerOne.snakesEaten > playerTwo.snakesEaten) {
            cout << "\t" << playerTwo.playerName << " is the best player!" << endl;
            cout << "\tWith: " << playerTwo.laddersClimbed << " ladders climbed!" << endl;
        } else {
            cout << "\t" << playerOne.playerName << " is the best player!" << endl;
            cout << "\tWith: " << playerOne.laddersClimbed << " ladders climbed!" << endl;
        }
    } else {
        playersData winner = (playerOne.laddersClimbed > playerTwo.laddersClimbed) ? playerOne : playerTwo;
        cout << "\t" << winner.playerName << " is the best player!" << endl;
        cout << "\tWith: " << winner.laddersClimbed << " ladders climbed!" << endl;
    }

    cout << "\n\n\t\tGame Summary!" << endl << endl;
}
