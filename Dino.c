#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 50000 

int main() {
    int x = 10, y = 15;       
    int cactusX = 60;         
    int score = 0;
    int isJumping = 0;
    int jumpStage = 0;

    initscr();      
    noecho();       
    curs_set(FALSE);   
    nodelay(stdscr, TRUE); 
    keypad(stdscr, TRUE);  

    while (1) {
        clear();
        
        
        mvhline(16, 0, '_', 80);
        
        
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

        
        cactusX--;
        if (cactusX < 0) {
            cactusX = 75;
            score++;
        }

        
        mvprintw(y, x, "D"); 
        mvprintw(15, cactusX, "###");

        
        mvprintw(2, 2, "Scor: %d", score);
        mvprintw(2, 30, "Apasă SPACE pentru săritură!");

        if (cactusX >= x && cactusX <= x + 1 && y == 15) {
            mvprintw(10, 30, "GAME OVER! Scor final: %d", score);
            refresh();
            usleep(2000000);
            break;
        }

        refresh();
        usleep(DELAY);
    }

    endwin();
    return 0;
}
