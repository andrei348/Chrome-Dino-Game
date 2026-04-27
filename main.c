#include "dino.h"

int main() {
    int y = DINO_Y_START, cactusX = 80, score = 0;
    int cactusWidth = 1, cactusHeight = 1;
    int isJumping = 0, jumpStage = 0;
    int currentDelay = INITIAL_DELAY;

    srand(time(NULL));
    initscr(); noecho(); curs_set(FALSE);
    nodelay(stdscr, TRUE); keypad(stdscr, TRUE);

    while (1) {
        drawGame(y, cactusX, cactusWidth, cactusHeight, score);
        handleInput(&isJumping, &jumpStage);
        updateJump(&y, &isJumping, &jumpStage);
        updateObstacle(&cactusX, &cactusWidth, &cactusHeight, &score);
        updateSpeed(score, &currentDelay);

        if (checkCollision(y, cactusX, cactusWidth, cactusHeight)) {
            mvprintw(10, 30, "GAME OVER! Scor: %d", score);
            refresh();
            usleep(2000000);
            break;
        }
        usleep(currentDelay);
    }

    endwin();
    return 0;
}