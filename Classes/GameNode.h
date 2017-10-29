//
//  GameNode.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/14/17.
//

#ifndef GameNode_h
#define GameNode_h

#include "cocos2d.h"

class GameNode : public NS_CC::Node
{
private:
    NS_CC::Sprite* sprite;
public:
    NS_CC::Vec2 direction;
    float velocity;
    NS_CC::Rect bounds;
    bool isActive;
    
    CREATE_FUNC(GameNode);
    bool init() override;
    void update(float dt) override;
    NS_CC::Rect getRect();
    void setDrawingColor(const NS_CC::Color3B& color);
    void clear();
};

#endif /* GameNode_h */

