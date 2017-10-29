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
    
    sprite = NS_CC::Sprite::create("res/rect.png");
    sprite->setPosition(0, 0);
    sprite->setAnchorPoint(NS_CC::Vec2(0.5, 0.5));
    addChild(sprite);
    setDrawingColor(NS_CC::Color3B::WHITE);
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

void GameNode::setDrawingColor(const NS_CC::Color3B& color)
{
    sprite->setVisible(true);
    sprite->setColor(color);
}

void GameNode::clear()
{
    sprite->setVisible(false);
}
