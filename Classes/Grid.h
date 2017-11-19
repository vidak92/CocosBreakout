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
#include "Matrix.h"

class Grid : public NS_CC::Node
{
private:
    LevelData levelData;
    Matrix<Brick*, BRICK_ROWS, BRICK_COLUMNS> bricks;
    
public:
    static Grid* create(LevelData levelData);
    bool init() override;
    void reset();
    std::vector<Brick*>::const_iterator begin() { return bricks.begin(); }
    std::vector<Brick*>::const_iterator end() { return bricks.end(); }
};

#endif /* Grid_h */
