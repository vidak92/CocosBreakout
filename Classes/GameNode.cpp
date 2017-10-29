//
//  GameNode.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/14/17.
//

#include "GameNode.h"

bool GameNode::init()
{
    if (!Node::init())
    {
        return false;
    }
    
    drawNode = NS_CC::DrawNode::create();
    drawNode->setPosition(0, 0);
    addChild(drawNode);
    setDrawingColor(NS_CC::Color4F::WHITE);
    isActive = true;
    
//    scheduleUpdate();
    return true;
}

void GameNode::update(float dt)
{
    
}

NS_CC::Rect GameNode::getRect()
{
    return NS_CC::Rect(getPositionX() - getScaleX() / 2,
                       getPositionY() - getScaleY() / 2,
                       getScaleX(),
                       getScaleY());
}

void GameNode::setDrawingColor(const NS_CC::Color4F& color)
{
    drawNode->clear();
    drawNode->drawSolidRect(NS_CC::Vec2(-0.5, -0.5), NS_CC::Vec2(0.5, 0.5), color);
}

void GameNode::clear()
{
    drawNode->clear();
}
