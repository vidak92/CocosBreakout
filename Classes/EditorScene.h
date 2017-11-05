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

class EditorScene : public NS_CC::Scene
{
private:
    Grid* grid;
    NS_CC::EventListenerMouse* mouseListener;
    NS_CC::EventListenerKeyboard* keyboardListener;
public:
    CREATE_FUNC(EditorScene);
    bool init() override;
    
    void onMouseUp(NS_CC::Event* event);
    void onMouseDown(NS_CC::Event* event);
    void onMouseMove(NS_CC::Event* event);
    
    void onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
    void onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
};

#endif /* EditorScene_h */
