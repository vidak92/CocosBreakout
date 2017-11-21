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

class Brick : public cocos2d::Node
{
private:
    cocos2d::Sprite* _sprite;
    BrickType _type;
public:
    cocos2d::Vec2 direction;
    float velocity;
    cocos2d::Rect bounds;
    
    CREATE_FUNC(Brick);
    virtual bool init() override;
    virtual void update(float dt) override;

    cocos2d::Rect getRect();
    BrickType getType();
    
    void setDrawingColor(const cocos2d::Color3B& color);
    void setType(BrickType type);
    void setOpacity(float opacity);
    void clear();
};

#endif /* BrickNode_h */
