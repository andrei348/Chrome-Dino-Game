#include "dino.h"

void handleInput(int *isJumping, int *jumpStage) {
    int ch = getch();
    if ((ch == ' ' || ch == KEY_UP) && !(*isJumping)) {
        *isJumping = 1;
        *jumpStage = 0;
    }
}

void updateJump(int *y, int *isJumping, int *jumpStage) {
    if (*isJumping) {
        if (*jumpStage < 7) (*y)--; 
        else if (*jumpStage < 14) (*y)++; 
        else {
            *isJumping = 0;
            *y = DINO_Y_START;
        }
        (*jumpStage)++;
    }
}

void updateObstacle(int *cactusX, int *cactusWidth, int *cactusHeight, int *score) {
    (*cactusX)--;
    if (*cactusX < -5) {
        *cactusX = 80 + (rand() % 20);
        *cactusWidth = (rand() % 2) + 1;  
        *cactusHeight = (rand() % 3) + 1; 
        (*score)++;
    }
}

void updateSpeed(int score, int *currentDelay) {
    int newDelay = INITIAL_DELAY - (score * 1000);
    if (newDelay < MIN_DELAY) *currentDelay = MIN_DELAY;
    else *currentDelay = newDelay;
}

int checkCollision(int dinoY, int cactusX, int cactusWidth, int cactusHeight) {
    if (DINO_X >= cactusX && DINO_X < cactusX + cactusWidth) {
        if (dinoY > DINO_Y_START - cactusHeight) {
            return 1;
        }
    }
    return 0;
}

void drawGame(int dinoY, int cactusX, int cactusWidth, int cactusHeight, int score) {
    clear();
    mvhline(GROUND_Y, 0, '_', 80);
    mvprintw(1, 2, "Scor: %d | Taste: SPACE / UP", score);
    mvaddch(dinoY, DINO_X, 'D' | A_BOLD); 
    for (int h = 0; h < cactusHeight; h++) {
        for (int w = 0; w < cactusWidth; w++) {
            int px = cactusX + w;
            int py = DINO_Y_START - h;
            if (px >= 0 && px < 80) {
                mvaddch(py, px, '#' | A_BOLD);
            }
        }
    }
    refresh();
}