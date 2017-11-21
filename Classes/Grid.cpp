//
//  Grid.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/4/17.
//

#include "Grid.h"
#include <iostream>

USING_NS_CC;

Grid* Grid::create(LevelData levelData)
{
    Grid* pRet = new (std::nothrow) Grid;
    if (pRet)
    {
        pRet->_levelData = levelData;
        if (pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

bool Grid::init()
{
    if (!Node::init())
    {
        return false;
    }
    
    for (int i = 0; i < BRICK_ROWS; ++i)
    {
        for (int j = 0; j < BRICK_COLUMNS; ++j)
        {
            Brick* brick = Brick::create();
            brick->setType(_levelData.at(i, j));
            brick->setScale(BRICK_SCALE_X, BRICK_SCALE_Y);
            auto position = Vec2(j * (BRICK_SCALE_X + BRICK_GAP) + BRICK_OFFSET_X,
                                 SCREEN_HEIGHT - i * (BRICK_SCALE_Y + BRICK_GAP) - BRICK_OFFSET_Y);
            std::cout << "pos: " << position.x << ", " << position.y << std::endl;
            brick->setPosition(position);
            _bricks.at(i, j) = brick;
            this->addChild(brick);
        }
    }
    
    return true;
}

void Grid::reset()
{
    for (int i = 0; i < BRICK_ROWS; ++i)
    {
        for (int j = 0; j < BRICK_COLUMNS; ++j)
        {
            _bricks.at(i, j)->setType(_levelData.at(i, j));
        }
    }
}
