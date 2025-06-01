# CODE BREAKER GAME / NUMBER GUESSING GAME
# C++ CONSOLE GAME 

**Secret Code Breaker** is a terminal-based C++ game where the player attempts to guess a randomly generated 4-digit code. The program provides feedback on each digit's correctness and position, challenging the player to deduce the code within a limited number of attempts based on the selected difficulty.
The game code does not involve any arrays and uses basic c++ functions.

## Game Modes

The game offers three difficulty levels:
- **Easy** – 20 attempts
- **Medium** – 15 attempts
- **Difficult** – 10 attempts

## Gameplay Overview

- The system generates a random 4-digit number between 1000 and 9999.
- The player enters guesses and receives feedback per digit:
  - **Correct and correct position**
  - **Correct but wrong position**
  - **Incorrect digit**
- After each guess, the user can choose to see all previous guesses.
- Random win/lose messages enhance the game experience.

## Features

- 4-digit random number generation
- Digit-by-digit feedback mechanism
- Difficulty selection (E, M, D)
- Optional display of previous guesses
- Randomized win/loss messages
- Input validation for guess format

## Technologies Used

- Language: **C++**
- Libraries: `<iostream>`, `<string>`, `<cstdlib>`

## How to Play

1. **Compile the code** using any C++ compiler:
(the game was made on Visual studio 2022)
2. **Choose a level**
3. **make a guess**
   
