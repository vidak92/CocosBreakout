//
//  Grid.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/4/17.
//

#include "Grid.h"
#include <iostream>

Grid* Grid::create(int width, int height)
{
    Grid* pRet = new (std::nothrow) Grid;
    if (pRet)
    {
        pRet->screenWidth = width;
        pRet->screenHeight = height;
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
    
    for (int i = 0; i < MAX_BRICK_COUNT_X; ++i)
    {
        for (int j = 0; j < MAX_BRICK_COUNT_Y; ++j)
        {
            Brick* brick = Brick::create();
            bricks[i][j] = brick;
            brick->setScale(BRICK_SCALE_X, BRICK_SCALE_Y);
            auto position = NS_CC::Vec2(i * (BRICK_SCALE_X + BRICK_GAP) + BRICK_OFFSET_X,
                                        screenHeight - j * (BRICK_SCALE_Y + BRICK_GAP) - BRICK_OFFSET_Y);
            std::cout << "pos: " << position.x << ", " << position.y << std::endl;
            brick->setPosition(position);
            this->addChild(brick);
        }
    }
    
    return true;
}

void Grid::reset()
{
    for (int i = 0; i < MAX_BRICK_COUNT_X; ++i)
    {
        for (int j = 0; j < MAX_BRICK_COUNT_Y; ++j)
        {
            bricks[i][j]->setDrawingColor(NS_CC::Color3B::WHITE);
            bricks[i][j]->isActive = true;
        }
    }
}

Brick* Grid::getBrick(int i, int j)
{
    return bricks[i][j];
}
