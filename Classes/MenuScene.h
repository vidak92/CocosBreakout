//
//  MenuScene.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#ifndef MenuScene_h
#define MenuScene_h

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(MenuScene);
    bool init() override;
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
};

#endif /* MenuScene_h */
