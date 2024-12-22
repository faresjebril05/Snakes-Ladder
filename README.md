# Snakes and Ladders Game

## Installation
To run this game on your local machine, follow these steps:
1. Clone this repository:
  git clone https://github.com/yourusername/snakes-and-ladders.git
2. Navigate into the project directory:
  cd snakes-and-ladders
3. Compile the C++ code using your preferred compiler. For example, with g++:
  g++ -o snakes_and_ladders main.cpp
4. Run the compiled program:
  ./snakes_and_ladders

## Code Structure
**main.cpp**: Contains the core game logic, including the dice roll simulation, checking for ladders and snakes, and handling player turns.
**gameData struct**: Stores game-related information like current player and positions of ladders and snakes.
**playersData struct**: Stores data about each player, such as their name, current position, and stats (ladders climbed and snakes eaten).

## Contributing
1. Fork the repository.
2. Create a new branch (git checkout -b feature-name).
3. Make changes and commit (git commit -am 'Add new feature').
4. Push to the branch (git push origin feature-name).
5. Create a new pull request.

## License
This project is open-source and available under the MIT License. You can freely modify, distribute, and use it for personal or commercial purposes.

## Acknowledgments
This game is based on the traditional Snakes and Ladders board game.
Thanks to the C++ programming language for making the implementation of this game possible.

## Description

This project is a console-based **Snakes and Ladders** game implemented in C++. The game simulates a two-player experience where each player takes turns to roll a dice, moving across a game board. Players can climb ladders to advance quickly or slide down snakes, making their progress slower. The first player to reach the last cell of the board (cell 100) wins the game.

## Features

- Two-player game mode
- Dice roll simulation
- Ladders and snakes functionality
- Game summary with best player

## Requirements

- C++11 or higher
- A C++ compiler (e.g., GCC, Clang)
- Standard C++ library

## How to Play

1. The game will ask each player to input their name (maximum of 6 characters).
2. Players will take turns rolling a dice to move across the board.
3. If a player lands on a ladder, they will climb to a higher position.
4. If a player lands on a snake, they will slide down to a lower position.
5. The first player to reach position 100 wins the game.
6. After the game ends, the program will display a summary of the game, showing the best player and how many ladders and snakes they encountered.

## Gameplay Example

```bash
Please enter the first player name shortcut (Maximum 6 characters): Alice
Please enter the second player name shortcut (Maximum 6 characters): Bob

Welcome Alice & Bob to SNAKES & LADDER!

[Player 1]: Alice it's your turn! Press [ENTER] to roll the dice.
Dice rolled: 3
Alice is now at position 3.

[Player 2]: Bob it's your turn! Press [ENTER] to roll the dice.
Dice rolled: 5
Bob is now at position 5.

...

Game Summary:
- Best Player: Alice
- Ladders climbed: 2
- Snakes eaten: 1
