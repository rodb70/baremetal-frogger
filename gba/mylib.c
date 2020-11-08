#include "mylib.h"

unsigned short *videoBuffer = (unsigned short*) 0x6000000;

//waitForVblank
void waitForVblank(void)
{
    while( SCANLINECOUNTER > 160 )
        ;
    while( SCANLINECOUNTER < 160 )
        ;
}
// A function to draw a FILLED rectangle starting at (r, c)
void drawRect(int r, int c, int width, int height, uint16_t color)
{
    for( int i = 0; i < height; ++i )
    {

        DMA[3].src = &color;
        DMA[3].dst = &videoBuffer[OFFSET( r + i, c, 240 )];
        DMA[3].cnt = DMA_ON | DMA_SOURCE_FIXED | width;

    }
}

void drawHollowRect(int r, int c, int width, int height, uint16_t color)
{
    for( int i = 0; i <= height; i++ )
    {
        setPixel( i + r, c, color );
        setPixel( i + r, c + width, color );
    }
    for( int j = 0; j <= width; j++ )
    {
        setPixel( r, j + c, color );
        setPixel( r + height, j + c, color );
    }
}
// A function to fill the entire screen with a given color
void fillinScreen(volatile unsigned short color)
{
    DMA[3].src = &color;
    DMA[3].dst = videoBuffer;
    DMA[3].cnt = (160 * 240) | DMA_SOURCE_FIXED | DMA_ON;
}

void drawImage3(int r, int c, int width, int height, const uint16_t *image)
{
    for( int i = 0; i < height; ++i )
    {
        DMA[3].src = &image[OFFSET( i, 0, width )];
        DMA[3].dst = &videoBuffer[OFFSET( r + i, c, 240 )];
        DMA[3].cnt = DMA_ON | width;
    }
}

void delay(int n)
{
    int i;
    volatile int x;
    for( i = 0; i < n * 10000; i++ )
    {
        x++;
    }
}

