//
//  EditorScene.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#ifndef EditorScene_h
#define EditorScene_h

#include "cocos2d.h"
#include "Grid.h"

class EditorScene : public cocos2d::Scene
{
private:
    Grid* grid;
    cocos2d::EventListenerMouse* mouseListener;
    cocos2d::EventListenerKeyboard* keyboardListener;
public:
    CREATE_FUNC(EditorScene);
    bool init() override;
    
    void onMouseUp(cocos2d::Event* event);
    void onMouseDown(cocos2d::Event* event);
    void onMouseMove(cocos2d::Event* event);
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
};

#endif /* EditorScene_h */
