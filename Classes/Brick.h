//
//  BrickNode.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/14/17.
//

#ifndef BrickNode_h
#define BrickNode_h

#include "cocos2d.h"

class Brick : public NS_CC::Node
{
private:
    NS_CC::Sprite* sprite;
public:
    NS_CC::Vec2 direction;
    float velocity;
    NS_CC::Rect bounds;
    bool isActive;
    
    CREATE_FUNC(Brick);
    virtual bool init() override;
    virtual void update(float dt) override;
    NS_CC::Rect getRect();
    void setDrawingColor(const NS_CC::Color3B& color);
    void clear();
};

#endif /* BrickNode_h */
