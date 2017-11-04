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
    bool normalizedDirection;
    
    CREATE_FUNC(Ball);
    bool init() override;
    void update(float dt) override;
};

#endif /* Ball_h */
