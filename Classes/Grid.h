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
#include "GameConfig.h"

class Grid : public NS_CC::Node
{
private:
    BrickType bricksConfig[BRICK_COUNT_Y][BRICK_COUNT_X];
    
    int screenWidth;
    int screenHeight;
    
    Brick* bricks[BRICK_COUNT_X][BRICK_COUNT_Y];
    
public:
    static Grid* create(int width, int height, const BrickType levelData[BRICK_COUNT_Y][BRICK_COUNT_X]);
    bool init() override;
    void reset();
    Brick* getBrick(int i, int j);
};

#endif /* Grid_h */
