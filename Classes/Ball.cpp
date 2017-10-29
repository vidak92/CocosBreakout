//
//  Ball.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/13/17.
//

#include "Ball.h"

void Ball::update(float dt)
{
    auto position = getPosition();
    position += direction * velocity * dt;
    if (position.x >= bounds.getMaxX() - getScaleX() / 2)
    {
        direction.x = -std::abs(direction.x);
    }
    if (position.x <= bounds.getMinX() + getScaleX() / 2)
    {
        direction.x = std::abs(direction.x);
    }
    if (position.y >= bounds.getMaxY() - getScaleY() / 2)
    {
        direction.y = -std::abs(direction.y);
    }
    if (position.y <= bounds.getMinY() + getScaleY() / 2)
    {
        direction.y = std::abs(direction.y);
    }
    this->setPosition(position);
}
