//
//  Grid.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/4/17.
//

#ifndef Grid_h
#define Grid_h

#include "cocos2d.h"
#include "Brick.h"

class Grid : public NS_CC::Node
{
public:
    static const int MAX_BRICK_COUNT_X = 8;
    static const int MAX_BRICK_COUNT_Y = 5;

private:
    static const int BRICK_GAP = 10;
    static const int BRICK_SCALE_X = 65;
    static const int BRICK_SCALE_Y = 30;
    static const int BRICK_OFFSET_X = 55;
    static const int BRICK_OFFSET_Y = 35;
    
    int screenWidth;
    int screenHeight;
    
    Brick* bricks[MAX_BRICK_COUNT_X][MAX_BRICK_COUNT_Y];
    
public:
    CREATE_FUNC(Grid);
    static Grid* create(int width, int height);
    bool init() override;
    void reset();
    Brick* getBrick(int i, int j);
};

#endif /* Grid_h */
