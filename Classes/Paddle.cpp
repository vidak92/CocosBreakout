//
//  Paddle.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/12/17.
//

#include "Paddle.h"

void Paddle::update(float dt)
{
    auto position = getPosition();
    position += direction * velocity * dt;
    position.x = NS_CC::clampf(position.x, bounds.getMinX() + getScaleX() / 2, bounds.getMaxX() - getScaleX() / 2);
    this->setPosition(position);
}
