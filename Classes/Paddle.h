//
//  Paddle.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/12/17.
//

#ifndef Paddle_h
#define Paddle_h

#include "cocos2d.h"
#include "BrickNode.h"

class Paddle : public BrickNode
{
public:
    CREATE_FUNC(Paddle);
    void update(float dt) override;
};

#endif /* Paddle_h */
