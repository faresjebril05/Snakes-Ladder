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
	int ladders[8] = { 4,12,21,28,36,51,71,80 };
	int snakes[9] = { 16,47,49,62,64,87,93,95,98 };
};

int getDiceRandom(); //Function returns a random number between 1 and 6
int getLadderEnd(int ladderStart);//Function take the current player poision as a parameter and then return the ladder end position
int getSnakesStart(int snakeEnd);//Function take the current player poision as a parameter and then return the snake start position
int checkLadder(gameData currentGameData, int playerPosition);//Function take the current player poision as a parameter and then check if there's a ladder on this position or not
int checkSnake(gameData currentGameData, int playerPosition);//Function take the current player poision as a parameter and then check if there's a snake on this position or not

void assignNames(playersData playerOne, playersData playerTwo); //Function assigns the names into vector as the player position is
void sendGameCell(); //sending the Snakes & Ladder cell
playersData getTopPlayer(playersData playerOne, playersData playerTwo); //returning the best player!
void sendGameSummary(playersData playerOne, playersData playerTwo); //Sending the top player!

int main() {
	srand(time(0));

	playersData playerOne, playerTwo; //Players Data Structure
	gameData currentGameData; //The main game Data Structure

	int diceNumber;
	cout << endl << endl << "\t\tWelcome to the SNAKES & LADDER game!" << endl << endl;


	do {
		cout << "Please enter the first player name shortcut (Maximum 6 characters): ";
		cin >> playerOne.playerName;
	} while ((playerOne.playerName).length() > 6);

	do {
		cout << "Please enter the second player name shortcut (Maximum 6 characters): ";
		cin >> playerTwo.playerName;
	} while ((playerTwo.playerName).length() > 6);
	cin.ignore();

	cout << endl << endl << "\t\tWelcome " << playerOne.playerName << " & " << playerTwo.playerName << " to SNAKES & LADDER!" << endl << endl;
	do {
		assignNames(playerOne, playerTwo);
		sendGameCell();
		switch (currentGameData.currentPlayer) {

		case 1:

			cout << "[Player 1]: " << playerOne.playerName << " it's your turn!, you can drop the dice by pressing [ENTER]";
			cin.ignore();

			diceNumber = getDiceRandom();
			playerOne.playerPosition += diceNumber;

			if (checkLadder(currentGameData, playerOne.playerPosition)) {
				(playerOne.playerPosition < 100) ? cout << endl << "Nice!! " << playerOne.playerName << "'s got " << diceNumber << " points and he's now on " << playerOne.playerPosition << ", but this cell contains a ladder!!!! so he has climbed to " << getLadderEnd(playerOne.playerPosition) << endl : cout << "Nice!! " << playerOne.playerName << "'s got " << diceNumber << ", but this cell contains a ladder!! so he has climbed to " << getLadderEnd(playerOne.playerPosition) << ", and he's now on 100, GOOD GAME!!" << endl;
				playerOne.playerPosition = getLadderEnd(playerOne.playerPosition);
				playerOne.laddersClimbed++;
			}

			else if (checkSnake(currentGameData, playerOne.playerPosition)) {
				cout << endl << "Oops!! " << playerOne.playerName << "'s got " << diceNumber << " points and he's now on " << playerOne.playerPosition << ", but this cell contains a snake inside!!!! so he got dropped down to " << getSnakesStart(playerOne.playerPosition) << endl;
				playerOne.playerPosition = getSnakesStart(playerOne.playerPosition);
				playerOne.snakesEaten++;
			}

			else {
				(playerOne.playerPosition < 100) ? cout << endl << "Nice!! " << playerOne.playerName << "'s got " << diceNumber << " points and he's now on " << playerOne.playerPosition << " keep going!" << endl : cout << "Nice!! " << playerOne.playerName << "'s got " << diceNumber << " points and he's now on 100, GOOD GAME!!" << endl;
			}

			currentGameData.currentPlayer = 2;

			break;

		case 2:

			cout << "[Player 2]: " << playerTwo.playerName << " it's your turn!, you can drop the dice using [ENTER]";
			cin.ignore();

			diceNumber = getDiceRandom();
			playerTwo.playerPosition += diceNumber;

			if (checkLadder(currentGameData, playerTwo.playerPosition)) {
				(playerTwo.playerPosition < 100) ? cout << endl << "Nice!! " << playerTwo.playerName << "'s got " << diceNumber << " points and he's now on " << playerTwo.playerPosition << ", but this cell contains a ladder!!!! so he has climbed to " << getLadderEnd(playerTwo.playerPosition) << endl : cout << "Nice!! " << playerTwo.playerName << "'s got " << diceNumber << ", but this cell contains a ladder!! so he has climbed to " << getLadderEnd(playerTwo.playerPosition) << ", and he's now on 100, GOOD GAME!!" << endl;
				playerTwo.playerPosition = getLadderEnd(playerTwo.playerPosition);
				playerTwo.laddersClimbed++;
			}

			else if (checkSnake(currentGameData, playerTwo.playerPosition)) {
				cout << endl << "Oops!! " << playerTwo.playerName << "'s got " << diceNumber << " points and he's now on " << playerTwo.playerPosition << ", but this cell contains a snake inside!!!! so he got dropped down to " << getSnakesStart(playerTwo.playerPosition) << endl;
				playerTwo.playerPosition = getSnakesStart(playerTwo.playerPosition);
				playerTwo.snakesEaten++;
			}

			else {
				(playerTwo.playerPosition < 100) ? cout << endl << "Nice!! " << playerTwo.playerName << "'s got " << diceNumber << " points and he's now on " << playerTwo.playerPosition << " keep going!" << endl : cout << "Nice!! " << playerTwo.playerName << "'s got " << diceNumber << " points and he's now on 100, GOOD GAME!!" << endl;
			}

			currentGameData.currentPlayer = 1;

			break;
		}
	} while (playerOne.playerPosition < 100 && playerTwo.playerPosition < 100);

	sendGameSummary(playerOne, playerTwo);
	system("pause");
	return 0;
}

int getLadderEnd(int ladderStart) {
	switch (ladderStart) {
	case 4:
		return 14;
		break;
	case 12:
		return 31;
		break;
	case 21:
		return 42;
		break;
	case 28:
		return 84;
		break;
	case 36:
		return 57;
		break;
	case 51:
		return 67;
		break;
	case 71:
		return 91;
		break;
	case 80:
		return 100;
		break;
	}
	return 0;
}

int getSnakesStart(int snakeEnd) {
	switch (snakeEnd) {
	case 16:
		return 6;
		break;
	case 47:
		return 26;
		break;
	case 49:
		return 11;
		break;
	case 62:
		return 19;
		break;
	case 64:
		return 60;
		break;
	case 87:
		return 24;
		break;
	case 93:
		return 73;
		break;
	case 95:
		return 53;
		break;
	case 98:
		return 78;
		break;
	}
	return 0;
}

int checkLadder(gameData currentGameData, int playerPosition) {
	for (int i = 0; i < sizeof(currentGameData.ladders[0]); i++) {
		if (currentGameData.ladders[i] == playerPosition) return true;
		break;
	}
	return false;
}

int checkSnake(gameData currentGameData, int playerPosition) {
	for (int i = 0; i < sizeof(currentGameData.snakes[0]); i++) {
		if (currentGameData.snakes[i] == playerPosition) return true;
		break;
	}
	return false;
}

int getDiceRandom() {
	return (rand() % 6) + 1;
}

void sendGameCell() {
	cout << endl << endl << "\t\t\tHere you go the game cell" << endl;
	cout << "_______________________________________________________________________________" << endl;
	cout << "| 100\t| 99\t| 98\t| 97\t| 96\t| 95\t| 94\t| 93\t| 92\t| 91" << endl;
	for (int i = 99; i > 89; i--)
		cout << "| " << names[i] << "\t";
	cout << "\n| 81\t| 82\t| 83\t| 84\t| 85\t| 86\t| 87\t| 88\t| 89\t| 90" << endl;
	for (int i = 80; i < 90; i++)
		cout << "| " << names[i] << "\t";
	cout << "\n| 80\t| 79\t| 78\t| 77\t| 76\t| 75\t| 74\t| 73\t| 72\t| 71" << endl;
	for (int i = 79; i > 69; i--)
		cout << "| " << names[i] << "\t";
	cout << "\n| 61\t| 62\t| 63\t| 64\t| 65\t| 66\t| 67\t| 68\t| 69\t| 70" << endl;
	for (int i = 60; i < 70; i++)
		cout << "| " << names[i] << "\t";
	cout << "\n| 60\t| 59\t| 58\t| 57\t| 56\t| 55\t| 54\t| 53\t| 52\t| 51" << endl;
	for (int i = 59; i > 49; i--)
		cout << "| " << names[i] << "\t";
	cout << "\n| 41\t| 42\t| 43\t| 44\t| 45\t| 46\t| 47\t| 48\t| 49\t| 50" << endl;
	for (int i = 40; i < 50; i++)
		cout << "| " << names[i] << "\t";
	cout << "\n| 40\t| 39\t| 38\t| 37\t| 36\t| 35\t| 34\t| 33\t| 32\t| 31" << endl;
	for (int i = 39; i > 29; i--)
		cout << "| " << names[i] << "\t";
	cout << "\n| 21\t| 22\t| 23\t| 24\t| 25\t| 26\t| 27\t| 28\t| 29\t| 30" << endl;
	for (int i = 20; i < 30; i++)
		cout << "| " << names[i] << "\t";
	cout << "\n| 20\t| 19\t| 18\t| 17\t| 16\t| 15\t| 14\t| 13\t| 12\t| 11" << endl;
	for (int i = 19; i > 9; i--)
		cout << "| " << names[i] << "\t";
	cout << "\n| 1\t| 2\t| 3\t| 4\t| 5\t| 6\t| 7\t| 8\t| 9\t| 10" << endl;
	for (int i = 0; i < 10; i++)
		cout << "| " << names[i] << "\t";
	cout << "\n_______________________________________________________________________________" << endl << endl;
}

void assignNames(playersData playerOne, playersData playerTwo) {
	for (int i = 0; i < 100; i++) names[i] = "";
	if (playerOne.playerPosition == playerTwo.playerPosition) {
		names[playerOne.playerPosition - 1] = playerOne.playerName + " & " + playerTwo.playerName + " (" + to_string(playerOne.playerPosition) + ")";
	}
	else {
		names[playerOne.playerPosition - 1] = playerOne.playerName;
		names[playerTwo.playerPosition - 1] = playerTwo.playerName;
	}
}

playersData getTopPlayer(playersData playerOne, playersData playerTwo) {
	if(playerOne.laddersClimbed > playerTwo.laddersClimbed) return playerOne;
	else return playerTwo;
}

void sendGameSummary(playersData playerOne, playersData playerTwo) {
	if (playerOne.laddersClimbed == playerTwo.laddersClimbed) {
		if (playerOne.snakesEaten > playerTwo.snakesEaten) {
			cout << "\n\n\t\tGame Summary!" << endl;
			cout << "\n\t" << playerTwo.playerName << " is the best player!" << endl;
			cout << "\tWith: " << playerTwo.laddersClimbed << " ladders claimed!" << endl;
			cout << "\tAnd: " << playerTwo.snakesEaten << " snakes eaten!" << endl;
			cout << "\n\n\tBut " << playerOne.playerName << " got:" << endl;
			cout << "\t" << playerOne.laddersClimbed << " ladders claimed!" << endl;
			cout << "\tAnd: " << playerOne.snakesEaten << " snakes eaten!" << endl;
			cout << "\n\n\t\tGame Summary!" << endl << endl;
		}
		else if (playerOne.snakesEaten < playerTwo.snakesEaten) {
			cout << "\n\n\t\tGame Summary!" << endl;
			cout << "\n\t" << playerOne.playerName << " is the best player!" << endl;
			cout << "\tWith: " << playerOne.laddersClimbed << " ladders claimed!" << endl;
			cout << "\tAnd: " << playerOne.snakesEaten << " snakes eaten!" << endl;
			cout << "\n\n\tBut " << playerTwo.playerName << " got:" << endl;
			cout << "\t" << playerTwo.laddersClimbed << " ladders claimed!" << endl;
			cout << "\tAnd: " << playerTwo.snakesEaten << " snakes eaten!" << endl;
			cout << "\n\n\t\tGame Summary!" << endl << endl;
		}
		else {
			cout << "\n\n\t\tGame Summary!" << endl;
			cout << "\n\t" << playerOne.playerName << " & " << playerTwo.playerName << " have got the same statistics!" << endl;
			cout << "\tWith: " << playerOne.laddersClimbed << " ladders claimed!" << endl;
			cout << "\tAnd: " << playerOne.snakesEaten << " snakes eaten!" << endl;
			cout << "\n\n\t\tGame Summary!" << endl << endl;
		}
	}
	else {
		playersData topPlayer = getTopPlayer(playerOne, playerTwo);
		cout << "\n\n\t\tGame Summary!" << endl;
		cout << "\n\t" << topPlayer.playerName << " is the best player!" << endl;
		cout << "\tWith: " << topPlayer.laddersClimbed << " ladders claimed!" << endl;
		cout << "\tAnd: " << topPlayer.snakesEaten << " snakes eaten!" << endl;
		cout << "\n\n\t\tGame Summary!" << endl << endl;
	}
}