//
//  Ball.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/13/17.
//

#ifndef Ball_h
#define Ball_h

#include "cocos2d.h"
#include "Brick.h"

class Ball : public Brick
{
public:
    const NS_CC::Vec2 initialDirection = NS_CC::Vec2(0.66, 1);
    bool normalizedDirection;
    
    CREATE_FUNC(Ball);
    bool init() override;
    void update(float dt) override;
};

#endif /* Ball_h */
