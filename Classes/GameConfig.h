//
//  GameConfig.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/4/17.
//

#ifndef GameConfig_h
#define GameConfig_h

#include "Brick.h"

#define BRICK_COUNT_X 8
#define BRICK_COUNT_Y 6

#define BRICK_SCALE_X 65
#define BRICK_SCALE_Y 30

#define BRICK_OFFSET_X 55
#define BRICK_OFFSET_Y 35

#define BRICK_GAP 10

struct LevelConfig
{
    const BrickType level0[BRICK_COUNT_Y][BRICK_COUNT_X] =
    {
        REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
        REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
        REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
        REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
        REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY
    };
    
    const BrickType level1[BRICK_COUNT_Y][BRICK_COUNT_X] =
    {
        REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
    };
    
    const BrickType levels[2][BRICK_COUNT_Y][BRICK_COUNT_X] =
    {
        // level 0
        {
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        },
        
        // level 1
        {
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        }
    };
};

#endif /* GameConfig_h */
