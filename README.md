# Game Project

## Overview
This project is a simple game developed in C using the SDL (Simple DirectMedia Layer) library. It features a player character that can move around the screen and an enemy character that moves autonomously. The objective of the game is to avoid collision with the enemy character while navigating the environment.

## Prerequisites
Before compiling and running the game, you need to ensure that you have the following prerequisites installed on your Ubuntu system:

- **GCC**: The GNU Compiler Collection is required for compiling the C source code.
- **Make**: The Make utility simplifies the build process by automating compilation and linking tasks.
- **SDL 1.2 Libraries**: Simple DirectMedia Layer libraries are needed for graphics, audio, and input handling.

## Installation
You can install GCC, Make, and SDL 1.2 libraries on Ubuntu using the following commands:

### Install GCC and Make

```bash
sudo apt update
sudo apt install build-essential

This will install GCC, Make, and other essential build tools.

Install SDL 1.2 Libraries
sudo apt install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev

This will install SDL 1.2 development libraries for graphics, image loading, audio, and TrueType font rendering.

Usage
Once you have installed the prerequisites, you can compile and run the game using the provided Makefile or by manually compiling the source code with GCC.

Compile with Makefile
Navigate to the project directory and run:

make

This will compile the source code and generate an executable named game.

Compile manually
If you prefer to compile manually, run the following command:

gcc -o game main.c ennemi.c personnage.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

To run the compiled executable, use the following command:

./game

File Structure
main.c: Contains the main game loop and event handling.
ennemi.h and ennemi.c: Define and implement the enemy character functionalities.
personnage.h and personnage.c: Define and implement the player character functionalities.
back.png: Background image for the game environment.
hero_spr.png: Sprite sheet for the enemy character.
perso1.png: Image for the player character.
README.md: Documentation file providing an overview of the project.
Credits
This project was developed by Chtioui Khaled.