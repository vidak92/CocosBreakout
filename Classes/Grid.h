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

class Grid : public cocos2d::Node
{
private:
    LevelData _levelData;
    Matrix<Brick*, BRICK_ROWS, BRICK_COLUMNS> _bricks;
    
public:
    static Grid* create(LevelData levelData);
    bool init() override;
    void reset();
    std::vector<Brick*>::iterator begin() { return _bricks.begin(); }
    std::vector<Brick*>::iterator end() { return _bricks.end(); }
    void setLevelData(LevelData levelData) { this->_levelData = levelData; }
};

#endif /* Grid_h */
