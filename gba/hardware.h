/*
 * hardware.h
 *
 *  Created on: 7 Nov 2020
 *      Author: rod
 */

#ifndef GBA_HARDWARE_H_
#define GBA_HARDWARE_H_
#include "mylib.h"

static inline void hardware_video_init( void )
{
    REG_DISPCNT = MODE3 | BG2_ENABLE;
}




#endif /* GBA_HARDWARE_H_ */
