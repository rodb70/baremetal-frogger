/*
 * game.c
 *
 */
#include "game.h"

// A function to set pixel (r, c) to the color passed in.
void setPixel( int r, int c, uint16_t color )
{
    videoBuffer[ OFFSET( r, c, SCREENWIDTH )] = color;
}

void drawChar(int r, int c, char ch, unsigned short color)
{
    for( int i = 0; i < 8; i++ )
    {
        for( int j = 0; j < 6; j++ )
        {
            if(fontdata_6x8[ OFFSET( i, j, 6 ) + ch * 48 ])
            {
                setPixel( r + i, c + j, color );
            }
        }
    }
}

void drawString(int r, int c, char *str, unsigned short color)
{
    while( *str )
    {
        drawChar( r, c, *str++, color );
        c += 6;
    }
}

//Checks to see if two objects collide
int isCollision(int row1, int col1, int row2, int col2, int rowDiff, int colDiff)
{
    if( (row1 - row2 < rowDiff && row1 - row2 > -rowDiff)
            && (col1 - col2 < colDiff && col1 - col2 > -colDiff) )
    {

        return 1;
    }
    return 0;
}


