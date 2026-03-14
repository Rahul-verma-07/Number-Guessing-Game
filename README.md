# Number Guessing Game

Author: **Rahul Verma**  

A colorful <ins>**terminal-based Number Guessing Game written in C**</ins> with a clean CLI interface, difficulty levels, animations, and input validation.  

This project demonstrates <ins>**console UI design**</ins>, <ins>**game logic**</ins>, and <ins>**user interaction**</ins> using standard C and Windows console features.

## Features

- **Colored Terminal UI**
- **Interactive Guessing System**
- **Custom Terminal UI using `gotoxy()`**
- **Input Validation**
- **Spinner Animation for Number Selection**
- **Attempt Tracking**
- **Replay Option**

## Game Preview

```text
================================
|     Number Guessing Game     |
================================

Select a difficulty level
--------------------------

1. Easy (1-50)    - 5 attempts
2. Medium (1-100) - 10 attempts
3. Hard (1-500)   - 15 attempts

Enter difficulty level (1-3):

Selecting number... Complete!

==================================
Guess the number between 1 and 50!
==================================

=> Enter your guess:
```

## Technologies Used

- **C Programming Language.**
- **Windows Console API** `(windows.h)`
- **Standard C Libraries:**
  - `stdio.h`
  - `stdlib.h`
  - `time.h`
  - `string.h`
  - `ctype.h`

## Project Structure

```text
number-guess-game/  
│  
├── Project.c        # Main source code  
├── Project.exe      # Compiled executable  
├── README.md        # Project documentation
```

## How to Run

**`1` Clone the Repository**    
```bash
git clone https://github.com/YOUR_USERNAME/number-guessing-game.git
```

**`2` Navigate to the Folder**  
```bash
cd number-guessing-game
```

**`3` Compile**  
```bash
gcc Project.c -o Project
```

**`4` Run**
```bash
./Project
```

## Screenshots

### Game Start
![Game Start](Images/Img%201.png)

### Number Selection
![Selecting Number](Images/Img%202.png)

### Gameplay
![Gameplay](Images/Img%203.png)