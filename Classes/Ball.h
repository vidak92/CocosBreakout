//
//  Ball.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/13/17.
//

#ifndef Ball_h
#define Ball_h

#include "cocos2d.h"
#include "GameNode.h"

class Ball : public GameNode
{
public:
    CREATE_FUNC(Ball);
    void update(float dt) override;
};

#endif /* Ball_h */