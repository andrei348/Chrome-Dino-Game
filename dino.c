#include "dino.h"

const float GRAVITY = 0.62f;
const float JUMP_FORCE = -12.5f;

void handleInput(bool *isJumping, float *jumpVelocity, bool *isDucking) {
    
    if (!(*isJumping)) {
        if (IsKeyDown(KEY_DOWN)) {
            *isDucking = true;
        } else {
            *isDucking = false;
        }
    }

    
    if ((IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) && !(*isJumping) && !(*isDucking)) {
        *isJumping = true;
        *jumpVelocity = JUMP_FORCE;
    }
}

void updateJump(float *y, bool *isJumping, float *jumpVelocity, bool isDucking) {
    if (*isJumping) {
        *y += *jumpVelocity;     
        *jumpVelocity += GRAVITY; 

        if (*y >= DINO_Y_START) {
            *y = DINO_Y_START;
            *isJumping = false;
            *jumpVelocity = 0;
        }
    } else {
        
        *y = isDucking ? DINO_Y_DUCK_START : DINO_Y_START;
    }
}

void updateObstacle(float *obsX, float *obsY, ObstacleType *type, int *cactusCount, float gameSpeed) {
    *obsX -= gameSpeed; 

    if (*obsX < -80) { 
        *obsX = SCREEN_WIDTH + (rand() % 300);
        
        if (rand() % 100 < 70) {
            *type = OBSTACLE_CACTUS;
            *cactusCount = (rand() % 2) + 1; 
            *obsY = GROUND_Y - CACTUS_HEIGHT;
        } else {
            *type = OBSTACLE_BIRD;
            *cactusCount = 1;
            *obsY = (rand() % 2 == 0) ? (GROUND_Y - BIRD_HEIGHT - 25) : (GROUND_Y - BIRD_HEIGHT - 5);
        }
    }
}

bool checkCollision(float dinoY, bool isDucking, float obsX, float obsY, ObstacleType type, int cactusCount) {
    Rectangle dinoBox;
    if (isDucking) {
        dinoBox = (Rectangle){ DINO_X + 2, dinoY + 2, DINO_DUCK_WIDTH - 4, DINO_DUCK_HEIGHT - 4 };
    } else {
        dinoBox = (Rectangle){ DINO_X + 6, dinoY + 4, DINO_WIDTH - 12, DINO_HEIGHT - 6 };
    }

    if (type == OBSTACLE_CACTUS) {
        float totalWidth = cactusCount * CACTUS_WIDTH;
        Rectangle cactusBox = { obsX + 4, obsY, totalWidth - 8, CACTUS_HEIGHT };
        return CheckCollisionRecs(dinoBox, cactusBox);
    } else {
        Rectangle birdBox = { obsX + 4, obsY + 6, BIRD_WIDTH - 8, BIRD_HEIGHT - 12 };
        return CheckCollisionRecs(dinoBox, birdBox);
    }
}

void drawGame(float dinoY, bool isDucking, float obsX, float obsY, ObstacleType type, int cactusCount,
              int score, int highScore, Texture2D dinoLeft, Texture2D dinoRight, 
              Texture2D duckLeft, Texture2D duckRight, Texture2D cactusTex, Texture2D birdTex, 
              bool inMenu, bool isJumping) {
    BeginDrawing();
    ClearBackground(RAYWHITE); 

    DrawLine(0, GROUND_Y, SCREEN_WIDTH, GROUND_Y, DARKGRAY);

    if (inMenu) {
        DrawText("T-REX RUNNER", SCREEN_WIDTH / 2 - MeasureText("T-REX RUNNER", 32) / 2, SCREEN_HEIGHT / 3, 32, GetColor(0x535353FF));
        if ((int)(GetTime() * 2) % 2 == 0) {
            DrawText("APASA SPACE PENTRU A INCEPE", SCREEN_WIDTH / 2 - MeasureText("APASA SPACE PENTRU A INCEPE", 16) / 2, SCREEN_HEIGHT / 2 + 30, 16, GRAY);
        }
    } 
    else {
        
        Texture2D currentDino;
        bool step = ((int)(GetTime() * 10) % 2 == 0);

        if (isDucking) {
            currentDino = step ? duckLeft : duckRight;
        } else {
            currentDino = (isJumping || step) ? dinoLeft : dinoRight;
        }

        float w = isDucking ? DINO_DUCK_WIDTH : DINO_WIDTH;
        float h = isDucking ? DINO_DUCK_HEIGHT : DINO_HEIGHT;
        DrawTexturePro(currentDino, (Rectangle){0, 0, currentDino.width, currentDino.height}, (Rectangle){DINO_X, dinoY, w, h}, (Vector2){0,0}, 0.0f, WHITE);

        if (type == OBSTACLE_CACTUS) {
            for (int i = 0; i < cactusCount; i++) {
                DrawTexturePro(cactusTex, (Rectangle){0, 0, cactusTex.width, cactusTex.height}, 
                               (Rectangle){obsX + (i * CACTUS_WIDTH), obsY, CACTUS_WIDTH, CACTUS_HEIGHT}, (Vector2){0,0}, 0.0f, WHITE);
            }
        } else {
        
            bool wingUp = ((int)(GetTime() * 6) % 2 == 0);
            Rectangle birdSource = { 0, 0, (float)birdTex.width, (float)birdTex.height };
            if (wingUp) birdSource.height *= -1;
            
            DrawTexturePro(birdTex, birdSource, (Rectangle){obsX, obsY, BIRD_WIDTH, BIRD_HEIGHT}, (Vector2){0,0}, 0.0f, WHITE);
        }

        
        DrawText(TextFormat("SCOR: %05d  MAX: %05d", score, highScore), SCREEN_WIDTH - 280, 20, 20, GetColor(0x535353FF));
    }

    EndDrawing();
}