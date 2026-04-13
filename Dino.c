#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 10, y = 15;
    int cactusX = 60;
    int cactusWidth = 1;
    int cactusHeight = 1;
    int score = 0;
    int isJumping = 0;
    int jumpStage = 0;
    
    // Viteza inițială (microsecunde)
    int currentDelay = 50000; 

    srand(time(NULL));

    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    while (1) {
        clear();
        
        // Desenăm solul
        mvhline(16, 0, '_', 80);
        
        int ch = getch();
        if ((ch == ' ' || ch == KEY_UP) && !isJumping) {
            isJumping = 1;
            jumpStage = 0;
        }

        if (isJumping) {
            if (jumpStage < 7) y--; 
            else if (jumpStage < 14) y++; 
            else {
                isJumping = 0;
                y = 15;
            }
            jumpStage++;
        }

        cactusX--;

        if (cactusX < 0) {
            cactusX = 75;
            cactusWidth = (rand() % 3) + 1;
            cactusHeight = (rand() % 3) + 1;
            score++;

            // --- LOGICA PENTRU VITEZĂ ---
            // Scădem delay-ul la fiecare punct, dar nu sub o limită minimă
            // (altfel jocul devine imposibil de rapid)
            if (currentDelay > 15000) {
                currentDelay -= 1000; // Crește viteza cu fiecare punct
            }
        }

        // Desenare Dino
        mvprintw(y, x, "D"); 

        // Desenare Cactus
        for (int h = 0; h < cactusHeight; h++) {
            for (int w = 0; w < cactusWidth; w++) {
                mvaddch(15 - h, cactusX + w, '#');
            }
        }

        // Afișare Info
        mvprintw(1, 2, "Scor: %d", score);
        mvprintw(2, 2, "Viteza (Delay): %d ms", currentDelay / 1000);
        mvprintw(2, 30, "SARI PESTE OBSTACOLE!");

        // Verificare coliziune
        if (x >= cactusX && x < cactusX + cactusWidth) {
            if (y >= 15 - (cactusHeight - 1)) { 
                mvprintw(10, 30, "GAME OVER! Scor final: %d", score);
                refresh();
                usleep(2000000);
                break;
            }
        }

        refresh();
        usleep(currentDelay); // Folosim variabila în loc de constantă
    }

    endwin();
    return 0;
}