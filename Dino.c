#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 50000 // Viteza jocului

int main() {
    int x = 10, y = 15;       // Poziția Dino
    int cactusX = 60;         // Poziția Cactusului
    int score = 0;
    int isJumping = 0;
    int jumpStage = 0;

    initscr();              // Inițializează ecranul
    noecho();               // Nu afișa caracterele tastate
    curs_set(FALSE);        // Ascunde cursorul
    nodelay(stdscr, TRUE);  // Nu aștepta tasta (non-blocking)
    keypad(stdscr, TRUE);   // Permite tastele speciale

    while (1) {
        clear();
        
        // Desenăm solul
        mvhline(16, 0, '_', 80);
        
        // Logica săriturii
        int ch = getch();
        if ((ch == ' ' || ch == KEY_UP) && !isJumping) {
            isJumping = 1;
            jumpStage = 0;
        }

        if (isJumping) {
            if (jumpStage < 5) y--; // Urcă
            else if (jumpStage < 10) y++; // Coboară
            else {
                isJumping = 0;
                y = 15;
            }
            jumpStage++;
        }

        // Mișcare cactus
        cactusX--;
        if (cactusX < 0) {
            cactusX = 75;
            score++;
        }

        // Desenare Dino și Cactus
        mvprintw(y, x, "D"); 
        mvprintw(15, cactusX, "###");

        // Afișare scor
        mvprintw(2, 2, "Scor: %d", score);
        mvprintw(2, 30, "Apasă SPACE pentru săritură!");

        // Verificare coliziune
        if (cactusX >= x && cactusX <= x + 1 && y == 15) {
            mvprintw(10, 30, "GAME OVER! Scor final: %d", score);
            refresh();
            usleep(2000000);
            break;
        }

        refresh();
        usleep(DELAY);
    }

    endwin(); // Închide ncurses
    return 0;
}
