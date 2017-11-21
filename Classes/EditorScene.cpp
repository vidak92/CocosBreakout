//
//  EditorScene.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#include "EditorScene.h"
#include <iostream>
#include <sstream>
#include "LevelManager.h"

USING_NS_CC;

bool EditorScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    grid = Grid::create(LevelManager::getInstance()->getLevel(-1));
    addChild(grid);
    for (auto it = grid->begin(); it != grid->end(); ++it)
    {
        Brick* brick = *it;
        brick->setType(BrickType::EMPTY);
        brick->setDrawingColor(Color3B::WHITE);
        brick->setOpacity(0.2);
    }
    
    mouseListener = EventListenerMouse::create();
    mouseListener->onMouseUp = CC_CALLBACK_1(EditorScene::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(EditorScene::onMouseDown, this);
    mouseListener->onMouseMove = CC_CALLBACK_1(EditorScene::onMouseMove, this);
    getEventDispatcher()->addEventListenerWithFixedPriority(mouseListener, 1);
    
    keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(EditorScene::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(EditorScene::onKeyReleased, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    return true;
}

void EditorScene::onMouseUp(::cocos2d::Event *event)
{
    EventMouse* e = (EventMouse*)event;
    std::cout << "Mouse Down detected, Key: " << (int)e->getMouseButton() << std::endl;
}

void EditorScene::onMouseDown(::cocos2d::Event *event)
{
    EventMouse* e = (EventMouse*)event;
    std::cout << "Mouse Down detected, Key: " << (int)e->getMouseButton() << std::endl;
    int cursorX = e->getCursorX();
    int cursorY = e->getCursorY();
    for (auto it = grid->begin(); it != grid->end(); ++it)
    {
        Brick* brick = *it;
        if (brick->getRect().containsPoint(Vec2(cursorX, cursorY)))
        {
            if (brick->getType() == BrickType::EMPTY)
            {
                brick->setType(BrickType::REGULAR);
                brick->setOpacity(1.0);
            }
            else
            {
                brick->setType(BrickType::EMPTY);
                brick->setOpacity(0.5);
            }
        }
    }
}

void EditorScene::onMouseMove(::cocos2d::Event *event)
{
    EventMouse* e = (EventMouse*)event;
    std::cout << "MousePosition X: " << e->getCursorX() << " Y: " << e->getCursorY() << std::endl;
    int cursorX = e->getCursorX();
    int cursorY = e->getCursorY();
    for (auto it = grid->begin(); it != grid->end(); ++it)
    {
        Brick* brick = *it;
        if (brick->getType() != BrickType::EMPTY)
        {
            brick->setDrawingColor(Color3B::WHITE);
            brick->setOpacity(1.0);
        }
        else if (brick->getRect().containsPoint(Vec2(cursorX, cursorY)))
        {
            brick->setDrawingColor(Color3B::WHITE);
            brick->setOpacity(0.5);
        }
        else
        {
            brick->setDrawingColor(Color3B::WHITE);
            brick->setOpacity(0.2);
        }
    }
}

void EditorScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
    switch (keyCode)
    {
        default:
            break;
    }
}

void EditorScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
    switch (keyCode)
    {
        case EventKeyboard::KeyCode::KEY_ESCAPE:
            getEventDispatcher()->removeEventListener(mouseListener);
            getEventDispatcher()->removeEventListener(keyboardListener);
//            Director::getInstance()->end();
            Director::getInstance()->popScene();
            break;
        default:
            break;
    }
}
