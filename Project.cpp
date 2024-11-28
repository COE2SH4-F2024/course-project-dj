#include <iostream>
#include "MacUILib.h" 

using namespace std;

#define DELAY_CONST 100000

struct Pos {
    int x, y;
};

class objPos {
public:
    Pos* pos;
    char symbol;

    objPos() {
        pos = new Pos;
        pos->x = 0;
        pos->y = 0;
        symbol = '*';
    }

    objPos(int xPos, int yPos, char sym) {
        pos = new Pos;
        pos->x = xPos;
        pos->y = yPos;
        symbol = sym;
    }

    ~objPos() {
        delete pos;
    }

    objPos(const objPos& other) {
        pos = new Pos;
        pos->x = other.pos->x;
        pos->y = other.pos->y;
        symbol = other.symbol;
    }

    void setObjPos(int xPos, int yPos, char sym) {
        pos->x = xPos;
        pos->y = yPos;
        symbol = sym;
    }

    objPos getObjPos() const {
        return *this;
    }

    char getSymbol() const {
        return symbol;
    }
};

class GameMechs {
public:
    int boardWidth;
    int boardHeight;

    GameMechs(int width, int height) : boardWidth(width), boardHeight(height) {}

    int getBoardSizeX() const { return boardWidth; }
    int getBoardSizeY() const { return boardHeight; }

    char getInput() {
        return MacUILib_getChar();
    }

    void clearInput() {
    }
};

class Player {
public:
    enum Dir { UP, DOWN, LEFT, RIGHT, STOP };

    Player(GameMechs* thisGMRef) {
        mainGameMechsRef = thisGMRef;
        myDir = STOP;
        int boardCenterX = mainGameMechsRef->getBoardSizeX() / 2;
        int boardCenterY = mainGameMechsRef->getBoardSizeY() / 2;
        playerPos.setObjPos(boardCenterX, boardCenterY, '*');
    }

    ~Player() {}

    objPos getPlayerPos() const { return playerPos; }

    void updatePlayerDir() {
        char input = mainGameMechsRef->getInput();
        switch(input) {
            case ' ':
                myDir = STOP;
                break;
            case 'w':
                if (myDir != DOWN) myDir = UP;
                break;
            case 's':
                if (myDir != UP) myDir = DOWN;
                break;
            case 'a':
                if (myDir != RIGHT) myDir = LEFT;
                break;
            case 'd':
                if (myDir != LEFT) myDir = RIGHT;
                break;
            default:
                break;
        }
        mainGameMechsRef->clearInput();
    }

    void movePlayer() {
        if(myDir == STOP) return;

        int x = playerPos.getObjPos().pos->x;
        int y = playerPos.getObjPos().pos->y;
        int boardWidth = mainGameMechsRef->getBoardSizeX();
        int boardHeight = mainGameMechsRef->getBoardSizeY();

        switch(myDir) {
            case UP:
                y = (y - 1 + boardHeight) % boardHeight;
                break;
            case DOWN:
                y = (y + 1) % boardHeight;
                break;
            case LEFT:
                x = (x - 1 + boardWidth) % boardWidth;
                break;
            case RIGHT:
                x = (x + 1) % boardWidth;
                break;
            default:
                break;
        }

        playerPos.setObjPos(x, y, '*');
    }

private:
    objPos playerPos;
    Dir myDir;
    GameMechs* mainGameMechsRef;
};

bool exitFlag;
Player* playerPtr = nullptr; 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void) {
    Initialize();

    while(exitFlag == false) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void) {
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
    int boardWidth = 20;
    int boardHeight = 10;
    GameMechs* gameMechs = new GameMechs(boardWidth, boardHeight);
    playerPtr = new Player(gameMechs);
}

void GetInput(void) {
}

void RunLogic(void) {
    playerPtr->updatePlayerDir();
    playerPtr->movePlayer();
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    int i, j;
    int boardWidth = 20;
    int boardHeight = 10;
    
    for (j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");

    objPos playerPos = playerPtr->getPlayerPos();
    int playerX = playerPos.getObjPos().pos->x;
    int playerY = playerPos.getObjPos().pos->y;
    char playerSymbol = playerPos.getSymbol();
    
    objPos randomcharone(5, 5, 'A');
    objPos randomchartwo(2, 7, 'C');
    
    for (i = 0; i < boardHeight; i++) {
        MacUILib_printf("#");
        for (j = 0; j < boardWidth; j++) {
            if (i == playerY && j == playerX) {
                MacUILib_printf("%c", playerSymbol);
            } else if (i == randomcharone.getObjPos().pos->y && j == randomcharone.getObjPos().pos->x) {
                MacUILib_printf("%c", randomcharone.getSymbol());
            } else if (i == randomchartwo.getObjPos().pos->y && j == randomchartwo.getObjPos().pos->x) {
                MacUILib_printf("%c", randomchartwo.getSymbol());
            } else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("#\n");
    }

    for (j = 0; j < boardWidth + 2; j++) {
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
}

void LoopDelay(void) {
    MacUILib_Delay(DELAY_CONST);  
}

void CleanUp(void) {
    MacUILib_clearScreen();
    MacUILib_uninit();
}