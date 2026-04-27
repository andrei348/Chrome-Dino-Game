#ifndef DINO_H
#define DINO_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_DELAY 50000 
#define MIN_DELAY 15000 
#define GROUND_Y 16
#define DINO_Y_START 15
#define DINO_X 10

void handleInput(int *isJumping, int *jumpStage);
void updateJump(int *y, int *isJumping, int *jumpStage);
void updateObstacle(int *cactusX, int *cactusWidth, int *cactusHeight, int *score);
void updateSpeed(int score, int *currentDelay);
int checkCollision(int dinoY, int cactusX, int cactusWidth, int cactusHeight);
void drawGame(int dinoY, int cactusX, int cactusWidth, int cactusHeight, int score);

#endif