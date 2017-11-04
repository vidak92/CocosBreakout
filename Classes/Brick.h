//
//  BrickNode.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/14/17.
//

#ifndef BrickNode_h
#define BrickNode_h

#include "cocos2d.h"

enum BrickType
{
    EMPTY,
    REGULAR,
    DOUBLE,
    UNBREAKABLE
};

class Brick : public NS_CC::Node
{
private:
    NS_CC::Sprite* sprite;
    BrickType type;
public:
    NS_CC::Vec2 direction;
    float velocity;
    NS_CC::Rect bounds;
    
    CREATE_FUNC(Brick);
    virtual bool init() override;
    virtual void update(float dt) override;
    NS_CC::Rect getRect();
    BrickType getType();
    void setDrawingColor(const NS_CC::Color3B& color);
    void setType(BrickType type);
    void clear();
};

#endif /* BrickNode_h */
