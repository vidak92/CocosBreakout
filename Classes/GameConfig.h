//
//  GameConfig.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/4/17.
//

#ifndef GameConfig_h
#define GameConfig_h

#include "Brick.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BRICK_COUNT_X 8
#define BRICK_COUNT_Y 8

#define BRICK_SCALE_X 65
#define BRICK_SCALE_Y 30

#define BRICK_OFFSET_X 55
#define BRICK_OFFSET_Y 35

#define BRICK_GAP 10

#define LEVEL_DATA_0 LevelConfig::levelData[0]
#define LEVEL_DATA_1 LevelConfig::levelData[1]
#define LEVEL_DATA_EMPTY LevelConfig::emptyLevelData
#define LEVEL_DATA_SIZE sizeof(BrickType) * BRICK_COUNT_Y * BRICK_COUNT_X

namespace LevelConfig
{
    static constexpr BrickType emptyLevelData[BRICK_COUNT_Y][BRICK_COUNT_X] =
    {
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
    };
    
    static constexpr BrickType levelData[2][BRICK_COUNT_Y][BRICK_COUNT_X] =
    {
        // level 0
        {
            REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
            REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
            REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
            REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
            REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,
            EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
            EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
            EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,
        },
        // level 1
        {
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
            REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,
        }
    };
}

#endif /* GameConfig_h */
