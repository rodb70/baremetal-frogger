/*
 * game.h
 *
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_
#include <stdint.h>

#include "hardware.h"

#define SCREENHEIGHT 160
#define SCREENWIDTH 240

extern const unsigned char fontdata_6x8[12288];
extern uint16_t *videoBuffer;

//******************************************************************************
//Colors
//******************************************************************************
#define RGB(r, g, b)  ((r) | (g)<<5 | (b)<<10)
#define SKY RGB(24, 31, 31)
#define WHITE RGB(31, 31, 31)
#define GREEN RGB(0, 31, 0)
#define BLACK 0
#define BROWN RGB(13, 5, 2)
#define ORANGE RGB(31, 15, 0)
#define CYAN RGB(0, 31, 31)
#define MAGENTA RGB(31, 0, 31)
#define BLUE RGB(0, 0, 31)
#define RED RGB(31, 0, 0)
#define PURPLE RGB(31, 0, 26)
#define YELLOW RGB(31, 31, 0)

//******************************************************************************
//Buttons
//******************************************************************************
#define BUTTON_A            (1<<0)
#define BUTTON_B            (1<<1)
#define BUTTON_SELECT       (1<<2)
#define BUTTON_START        (1<<3)
#define BUTTON_RIGHT        (1<<4)
#define BUTTON_LEFT         (1<<5)
#define BUTTON_UP           (1<<6)
#define BUTTON_DOWN         (1<<7)
#define BUTTON_R            (1<<8)
#define BUTTON_L            (1<<9)

#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

#define OFFSET(r, c, rowlen) ((r) * (rowlen) + (c))

//******************************************************************************
//Struct
//******************************************************************************

typedef struct
{
    int row;
    int col;
    int lives;
    int oldrow;
    int oldcol;
}FROG;

typedef struct
{
    int row;
    int col;
    int oldrow;
    int oldcol;
    const uint16_t* image;

}CROC;

typedef struct
{
    int row;
    int col;
    int oldrow;
    int oldcol;

}SNAKE;

typedef struct
{
    int row;
    int col;
    int oldrow;
    int oldcol;

}LOG;

typedef struct
{
    int row;
    int col;
    int oldrow;
    int oldcol;

}HOME;




//******************************************************************************
//Prototypes
//******************************************************************************

void setPixel(int r, int c, uint16_t color);
void drawRect(int r, int c, int width, int height, uint16_t color);
void drawChar(int r, int c, char ch, unsigned short color);
void drawString(int r, int c, char *str, unsigned short color);
void waitForVblank(void);
void fillinScreen(volatile unsigned short color);
void drawImage3(int r, int c, int width, int height, const uint16_t* image);
int isCollision(int row1, int col1, int row2, int col2, int rowDiff, int colDiff);
void drawHollowRect(int r, int c, int width, int height, uint16_t color);
void delay(int n);




#endif /* SRC_GAME_H_ */
