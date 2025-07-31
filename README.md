# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg


## New Features Implemented

This project extends the original Snake game with the following new features:

1.  **High Score Saving**: Players can now enter their name at the end of the game, and their score will be saved to a `highscores.txt` file. The game loads existing high scores, adds the new score, sorts them in descending order, and keeps only the top 10 scores. This demonstrates file I/O and data processing.

2.  **Rule of 5 Implementation**: The `Game` class now explicitly implements the Rule of 5 (copy constructor, move constructor, copy assignment operator, move assignment operator, and destructor). This ensures proper resource management, especially with the use of `std::unique_ptr` for `Snake` and `SDL_Point` objects, fulfilling memory management requirements.

3.  **Smart Pointers**: `std::unique_ptr` is used for `Snake` and `SDL_Point` within the `Game` class, demonstrating modern C++ memory management practices and adherence to RAII (Resource Acquisition Is Initialization).

## Code Structure Overview

The project maintains its original modular structure, consisting of the following key classes:

*   **`main.cpp`**: The entry point of the application. It initializes the `Renderer`, `Controller`, and `Game` objects. It now also handles player name input, loads/saves high scores from/to `highscores.txt`, and displays the high score list.
*   **`Game` Class (`game.h`, `game.cpp`)**: Manages the game logic, including the snake's movement, food placement, score tracking, and game state. It now incorporates `std::unique_ptr` for `Snake` and `SDL_Point` and explicitly implements the Rule of 5.
*   **`Snake` Class (`snake.h`, `snake.cpp`)**: Represents the snake entity, handling its body segments, direction, and growth. No significant changes were made to its core logic for this submission, but it is now managed by a `std::unique_ptr` in the `Game` class.
*   **`Controller` Class (`controller.h`, `controller.cpp`)**: Handles user input (keyboard events) to control the snake's direction. No significant changes were made to this class.
*   **`Renderer` Class (`renderer.h`, `renderer.cpp`)**: Responsible for rendering the game elements (snake, food) on the screen using the SDL library. No significant changes were made to this class.

## Compiling and Running the Project

### Dependencies

*   `cmake` >= 3.7
*   `make` >= 4.1 (Linux, Mac), 3.81 (Windows)
*   `SDL2` >= 2.0 (development libraries)
*   `gcc/g++` >= 5.4

**For Ubuntu/Debian-based systems, you can install the dependencies using:**
```bash
sudo apt-get update
sudo apt-get install -y cmake make libsdl2-dev g++
```

### Build Instructions

1.  Clone this repository.
2.  Navigate to the project root directory.
3.  Create a `build` directory and navigate into it:
    ```bash
    mkdir build && cd build
    ```
4.  Configure the CMake project:
    ```bash
    cmake ..
    ```
5.  Compile the project:
    ```bash
    make
    ```

### Running the Game

After successful compilation, run the executable from the `build` directory:

```bash
./SnakeGame
```

**Note**: This game requires a graphical environment to run. It cannot be executed directly in a headless terminal or a sandbox environment without display capabilities.

## Rubric Points Addressed

This project addresses the following rubric points:

### Compiling and Testing
*   **The submission must compile and run without errors on the Udacity project workspace.**
    *   The project successfully compiles using CMake and Make. While direct execution is not possible in the headless sandbox, the build process completes without errors, indicating readiness for a graphical environment.

### Loops, Functions, I/O
*   **The project reads data from a file and processes the data, or the program writes data to a file.**
    *   `main.cpp` now reads high scores from `highscores.txt` and writes updated high scores back to the same file, demonstrating file I/O operations.
*   **The project accepts user input and processes the input.**
    *   `main.cpp` accepts user input for the player's name to save their high score.

### Object Oriented Programming
*   **One or more classes are added to the project with appropriate access specifiers for class members.**
    *   The `HighScore` struct is added in `main.cpp` with public members and an overloaded `<` operator for sorting.
*   **Class constructors utilize member initialization lists.**
    *   Existing classes (`Game`, `Renderer`, `Snake`) and the newly modified `Game` class constructors continue to use member initialization lists.

### Memory Management
*   **The project uses smart pointers instead of raw pointers.**
    *   `std::unique_ptr` is used in the `Game` class to manage `Snake` and `SDL_Point` objects, replacing potential raw pointer usage and ensuring automatic memory deallocation.
*   **The project follows the Rule of 5.**
    *   The `Game` class explicitly defines a copy constructor, move constructor, copy assignment operator, move assignment operator, and a destructor to properly handle resource management, especially for its `std::unique_ptr` members.





### Concurrency
*   **The project uses multithreading.**
    *   `std::async` is used in `main.cpp` to asynchronously load and save high scores, demonstrating multithreading.
*   **A mutex or lock is used in the project.**
    *   `std::mutex` and `std::lock_guard` are used in the `Game` class to protect the `score` variable during updates, ensuring thread safety.
*   **A promise and future is used in the project.**
    *   `std::future` is used in `main.cpp` to retrieve the result of the asynchronous high score loading operation.


