//
//  Paddle.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/12/17.
//

#include "Paddle.h"

USING_NS_CC;

void Paddle::update(float dt)
{
    Brick::update(dt);
    
    auto position = getPosition();
    position += direction * velocity * dt;
    position.x = clampf(position.x, bounds.getMinX() + getScaleX() / 2, bounds.getMaxX() - getScaleX() / 2);
    this->setPosition(position);
}
