#ifndef DINO_H
#define DINO_H

#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define GROUND_Y 320          

// Dimensiuni Dino normal
#define DINO_WIDTH 44
#define DINO_HEIGHT 47
// Dimensiuni Dino aplecat (Duck)
#define DINO_DUCK_WIDTH 55
#define DINO_DUCK_HEIGHT 30

#define CACTUS_WIDTH 25
#define CACTUS_HEIGHT 50
#define BIRD_WIDTH 42
#define BIRD_HEIGHT 36

#define DINO_X 100            
#define DINO_Y_START (GROUND_Y - DINO_HEIGHT) 
#define DINO_Y_DUCK_START (GROUND_Y - DINO_DUCK_HEIGHT)

#define INITIAL_SPEED 5.0f       
#define MAX_SPEED 18.0f

typedef enum { OBSTACLE_CACTUS, OBSTACLE_BIRD } ObstacleType;

void handleInput(bool *isJumping, float *jumpVelocity, bool *isDucking);
void updateJump(float *y, bool *isJumping, float *jumpVelocity, bool isDucking);
void updateObstacle(float *obsX, float *obsY, ObstacleType *type, int *cactusCount, float gameSpeed);
bool checkCollision(float dinoY, bool isDucking, float obsX, float obsY, ObstacleType type, int cactusCount);

void drawGame(float dinoY, bool isDucking, float obsX, float obsY, ObstacleType type, int cactusCount,
              int score, int highScore, Texture2D dinoLeft, Texture2D dinoRight, 
              Texture2D duckLeft, Texture2D duckRight, Texture2D cactusTex, Texture2D birdTex, 
              bool inMenu, bool isJumping);

#endif