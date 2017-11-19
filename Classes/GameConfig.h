//
//  GameConfig.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/4/17.
//

#ifndef GameConfig_h
#define GameConfig_h

#include "Brick.h"
#include "Matrix.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BRICK_ROWS      8
#define BRICK_COLUMNS   8

#define BRICK_SCALE_X   65
#define BRICK_SCALE_Y   30

#define BRICK_OFFSET_X  55
#define BRICK_OFFSET_Y  35

#define BRICK_GAP 10

typedef Matrix<BrickType, BRICK_ROWS, BRICK_COLUMNS> LevelData;

#endif /* GameConfig_h */
