//
//  MenuScene.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#ifndef MenuScene_h
#define MenuScene_h

#include "cocos2d.h"

class MenuScene : public NS_CC::Scene
{
public:
    CREATE_FUNC(MenuScene);
    bool init() override;
    
    void onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
    void onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
};

#endif /* MenuScene_h */
