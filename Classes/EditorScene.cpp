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
    
    _grid = Grid::create(LevelManager::getInstance()->getLevel(-1));
    addChild(_grid);
    for (auto it = _grid->begin(); it != _grid->end(); ++it)
    {
        Brick* brick = *it;
        brick->setType(BrickType::EMPTY);
        brick->setDrawingColor(Color3B::WHITE);
        brick->setOpacity(0.2);
    }
    
    _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseUp = CC_CALLBACK_1(EditorScene::onMouseUp, this);
    _mouseListener->onMouseDown = CC_CALLBACK_1(EditorScene::onMouseDown, this);
    _mouseListener->onMouseMove = CC_CALLBACK_1(EditorScene::onMouseMove, this);
    getEventDispatcher()->addEventListenerWithFixedPriority(_mouseListener, 1);
    
    _keyboardListener = EventListenerKeyboard::create();
    _keyboardListener->onKeyPressed = CC_CALLBACK_2(EditorScene::onKeyPressed, this);
    _keyboardListener->onKeyReleased = CC_CALLBACK_2(EditorScene::onKeyReleased, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(_keyboardListener, this);
    
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
    for (auto it = _grid->begin(); it != _grid->end(); ++it)
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
    for (auto it = _grid->begin(); it != _grid->end(); ++it)
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
            getEventDispatcher()->removeEventListener(_mouseListener);
            getEventDispatcher()->removeEventListener(_keyboardListener);
//            Director::getInstance()->end();
            Director::getInstance()->popScene();
            break;
        default:
            break;
    }
}
