//
//  Brick.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/14/17.
//

#include "Brick.h"

USING_NS_CC;

// TODO: initWithType
bool Brick::init()
{
    if (!Node::init())
    {
        return false;
    }
    
    _sprite = Sprite::create("rect.png");
    _sprite->setPosition(0, 0);
    _sprite->setAnchorPoint(Vec2(0.5, 0.5));
    addChild(_sprite);
    setType(BrickType::REGULAR);
    
    scheduleUpdate();
    return true;
}

void Brick::update(float dt)
{
    if (isColliding)
    {
        setDrawingColor(collisionColor);
    }
    else
    {
        setDefaultDrawingColor();
    }
}

Rect Brick::getRect()
{
    return Rect(getPositionX() - getScaleX() / 2,
                getPositionY() - getScaleY() / 2,
                getScaleX(),
                getScaleY());
}

BrickType Brick::getType()
{
    return _type;
}

void Brick::setDrawingColor(const Color3B& color)
{
    _sprite->setColor(color);
}

void Brick::setDefaultDrawingColor()
{
    if (_type == BrickType::UNBREAKABLE)
    {
        setDrawingColor(Color3B::GRAY);
    }
    else // REGULAR or EMPTY
    {
        setDrawingColor(Color3B::WHITE);
    }
}

void Brick::setType(BrickType type)
{
    _type = type;
    _sprite->setVisible(_alwaysVisible || _type != BrickType::EMPTY);
    setDefaultDrawingColor();
}

void Brick::setOpacity(float opacity)
{
    opacity = MIN(MAX(opacity, 0), 1);
    _sprite->setOpacity(255 * opacity);
}
