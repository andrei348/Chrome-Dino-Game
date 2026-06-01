#include "dino.h"

// Texturile masive anterioare pentru Dino normal
Texture2D GenerateDinoLeft(void) {
    static const unsigned char pixels[47][44] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    Image img = GenImageColor(44, 47, BLANK);
    for (int y = 0; y < 47; y++) {
        for (int x = 0; x < 44; x++) {
            if (pixels[y][x] == 1) ImageDrawPixel(&img, x, y, GetColor(0x535353FF));
        }
    }
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

Texture2D GenerateDinoRight(void) {
    return GenerateDinoLeft(); // Folosim aceeași matrice, picioarele se schimbă prin logica din draw
}

// Generăm texturi pentru Dinozaurul Aplecat (Duck) - Frame 1
Texture2D GenerateDuckLeft(void) {
    Image img = GenImageColor(55, 30, BLANK);
    // Corp lung și aplatizat la sol
    ImageDrawRectangle(&img, 0, 10, 45, 16, GetColor(0x535353FF)); 
    ImageDrawRectangle(&img, 30, 2, 25, 12, GetColor(0x535353FF)); // Capul extins în față
    ImageDrawPixel(&img, 48, 5, RAYWHITE); // Ochiul
    // Picioare aplecate
    ImageDrawRectangle(&img, 10, 26, 4, 4, GetColor(0x535353FF));
    ImageDrawRectangle(&img, 25, 26, 4, 2, GetColor(0x535353FF));
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

// Dinozaurul Aplecat - Frame 2
Texture2D GenerateDuckRight(void) {
    Image img = GenImageColor(55, 30, BLANK);
    ImageDrawRectangle(&img, 0, 10, 45, 16, GetColor(0x535353FF)); 
    ImageDrawRectangle(&img, 30, 2, 25, 12, GetColor(0x535353FF));
    ImageDrawPixel(&img, 48, 5, RAYWHITE);
    // Picioarele alternat
    ImageDrawRectangle(&img, 10, 26, 4, 2, GetColor(0x535353FF));
    ImageDrawRectangle(&img, 25, 26, 4, 4, GetColor(0x535353FF));
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

// Cactus simplu din pixeli
Texture2D GenerateCactusTexture(void) {
    Image img = GenImageColor(25, 50, BLANK);
    ImageDrawRectangle(&img, 9, 0, 7, 50, GetColor(0x535353FF));
    ImageDrawRectangle(&img, 2, 14, 7, 6, GetColor(0x535353FF));
    ImageDrawRectangle(&img, 2, 6, 5, 12, GetColor(0x535353FF));
    ImageDrawRectangle(&img, 16, 20, 7, 6, GetColor(0x535353FF));
    ImageDrawRectangle(&img, 18, 10, 5, 14, GetColor(0x535353FF));
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

// Pasăre (Pterodactyl) din pixeli
Texture2D GenerateBirdTexture(void) {
    Image img = GenImageColor(42, 36, BLANK);
    ImageDrawRectangle(&img, 12, 12, 20, 10, GetColor(0x535353FF)); // Corp
    ImageDrawRectangle(&img, 32, 8, 10, 8, GetColor(0x535353FF));  // Cap + Cioc
    ImageDrawRectangle(&img, 18, 0, 6, 12, GetColor(0x535353FF));  // Aripa de sus
    ImageDrawRectangle(&img, 6, 14, 6, 4, GetColor(0x535353FF));   // Coadă
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chrome Dino - Birds, Ducking & Random Cactus Groups");
    SetTargetFPS(60); 
    srand(time(NULL));

    Texture2D dinoLeft = GenerateDinoLeft();
    Texture2D dinoRight = GenerateDinoRight();
    Texture2D duckLeft = GenerateDuckLeft();
    Texture2D duckRight = GenerateDuckRight();
    Texture2D cactusTex = GenerateCactusTexture();
    Texture2D birdTex = GenerateBirdTexture();

    SetTextureFilter(dinoLeft, TEXTURE_FILTER_POINT);
    SetTextureFilter(duckLeft, TEXTURE_FILTER_POINT);
    SetTextureFilter(cactusTex, TEXTURE_FILTER_POINT);
    SetTextureFilter(birdTex, TEXTURE_FILTER_POINT);

    float y = DINO_Y_START;
    
    // Proprietăți Obstacol curent
    float obsX = SCREEN_WIDTH + 100;
    float obsY = GROUND_Y - CACTUS_HEIGHT;
    ObstacleType obsType = OBSTACLE_CACTUS;
    int cactusCount = 1;

    float exactScore = 0.0f; 
    int displayScore = 0;
    int highScore = 0;       
    int lastMilestone = 0; 

    bool isJumping = false;
    bool isDucking = false;
    float jumpVelocity = 0.0f;
    float gameSpeed = INITIAL_SPEED;
    
    bool inMenu = true;
    bool gameOver = false;

    while (!WindowShouldClose()) { 
        
        if (inMenu) {
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) inMenu = false;
            drawGame(y, isDucking, obsX, obsY, obsType, cactusCount, displayScore, highScore, dinoLeft, dinoRight, duckLeft, duckRight, cactusTex, birdTex, inMenu, isJumping);
        } 
        else if (!gameOver) {
            handleInput(&isJumping, &jumpVelocity, &isDucking);
            updateJump(&y, &isJumping, &jumpVelocity, isDucking);
            updateObstacle(&obsX, &obsY, &obsType, &cactusCount, gameSpeed);

            exactScore += GetFrameTime() * 20.0f;
            displayScore = (int)exactScore;

            if (displayScore > highScore) highScore = displayScore;

            if (displayScore / 150 > lastMilestone) {
                lastMilestone = displayScore / 150;
                gameSpeed += 0.8f; 
                if (gameSpeed > MAX_SPEED) gameSpeed = MAX_SPEED;
            }

            if (checkCollision(y, isDucking, obsX, obsY, obsType, cactusCount)) {
                gameOver = true;
            }

            drawGame(y, isDucking, obsX, obsY, obsType, cactusCount, displayScore, highScore, dinoLeft, dinoRight, duckLeft, duckRight, cactusTex, birdTex, inMenu, isJumping);
        } 
        else {
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_ENTER)) {
                y = DINO_Y_START;
                obsX = SCREEN_WIDTH + 100;
                obsType = OBSTACLE_CACTUS;
                cactusCount = 1;
                obsY = GROUND_Y - CACTUS_HEIGHT;
                exactScore = 0.0f;
                displayScore = 0;
                lastMilestone = 0;
                gameSpeed = INITIAL_SPEED;
                isJumping = false;
                isDucking = false;
                jumpVelocity = 0.0f;
                gameOver = false;
            }

            drawGame(y, isDucking, obsX, obsY, obsType, cactusCount, displayScore, highScore, dinoLeft, dinoRight, duckLeft, duckRight, cactusTex, birdTex, inMenu, isJumping);
            
            BeginDrawing();
            DrawText("G A M E   O V E R", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 - 30, 30, RED);
            DrawText("Apasa SPACE pentru a juca iar", SCREEN_WIDTH / 2 - 145, SCREEN_HEIGHT / 2 + 15, 18, DARKGRAY);
            EndDrawing();
        }
    }

    UnloadTexture(dinoLeft); UnloadTexture(dinoRight);
    UnloadTexture(duckLeft); UnloadTexture(duckRight);
    UnloadTexture(cactusTex); UnloadTexture(birdTex);
    CloseWindow();

    return 0;
}