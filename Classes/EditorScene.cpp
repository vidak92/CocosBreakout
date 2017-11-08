//
//  EditorScene.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#include "EditorScene.h"
#include <iostream>
#include <sstream>

bool EditorScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    grid = Grid::create(SCREEN_WIDTH, SCREEN_HEIGHT, LEVEL_DATA_EMPTY);
    addChild(grid);
    for (int i = 0; i < BRICK_COUNT_X; ++i)
    {
        for (int j = 0; j < BRICK_COUNT_Y; ++j)
        {
            Brick* brick = grid->getBrick(i, j);
            brick->setType(BrickType::EMPTY);
            brick->setDrawingColor(NS_CC::Color3B::WHITE);
            brick->setOpacity(0.2);
        }
    }
    
    mouseListener = NS_CC::EventListenerMouse::create();
    mouseListener->onMouseUp = CC_CALLBACK_1(EditorScene::onMouseUp, this);
    mouseListener->onMouseDown = CC_CALLBACK_1(EditorScene::onMouseDown, this);
    mouseListener->onMouseMove = CC_CALLBACK_1(EditorScene::onMouseMove, this);
    getEventDispatcher()->addEventListenerWithFixedPriority(mouseListener, 1);
    
    keyboardListener = NS_CC::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(EditorScene::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(EditorScene::onKeyReleased, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    return true;
}

void EditorScene::onMouseUp(::cocos2d::Event *event)
{
    NS_CC::EventMouse* e = (NS_CC::EventMouse*)event;
    std::cout << "Mouse Down detected, Key: " << (int)e->getMouseButton() << std::endl;
}

void EditorScene::onMouseDown(::cocos2d::Event *event)
{
    NS_CC::EventMouse* e = (NS_CC::EventMouse*)event;
    std::cout << "Mouse Down detected, Key: " << (int)e->getMouseButton() << std::endl;
    int cursorX = e->getCursorX();
    int cursorY = e->getCursorY();
    for (int i = 0; i < BRICK_COUNT_X; ++i)
    {
        for (int j = 0; j < BRICK_COUNT_Y; ++j)
        {
            Brick* brick = grid->getBrick(i, j);
            if (brick->getRect().containsPoint(NS_CC::Vec2(cursorX, cursorY)))
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
}

void EditorScene::onMouseMove(::cocos2d::Event *event)
{
    NS_CC::EventMouse* e = (NS_CC::EventMouse*)event;
    std::cout << "MousePosition X: " << e->getCursorX() << " Y: " << e->getCursorY() << std::endl;
    int cursorX = e->getCursorX();
    int cursorY = e->getCursorY();
    for (int i = 0; i < BRICK_COUNT_X; ++i)
    {
        for (int j = 0; j < BRICK_COUNT_Y; ++j)
        {
            Brick* brick = grid->getBrick(i, j);
            if (brick->getType() != BrickType::EMPTY)
            {
                brick->setDrawingColor(NS_CC::Color3B::WHITE);
                brick->setOpacity(1.0);
            }
            else if (brick->getRect().containsPoint(NS_CC::Vec2(cursorX, cursorY)))
            {
                brick->setDrawingColor(NS_CC::Color3B::WHITE);
                brick->setOpacity(0.5);
            }
            else
            {
                brick->setDrawingColor(NS_CC::Color3B::WHITE);
                brick->setOpacity(0.2);
            }
        }
    }
}

void EditorScene::onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event *event)
{
    switch (keyCode)
    {
        default:
            break;
    }
}

void EditorScene::onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event *event)
{
    switch (keyCode)
    {
        case NS_CC::EventKeyboard::KeyCode::KEY_ESCAPE:
            getEventDispatcher()->removeEventListener(mouseListener);
            getEventDispatcher()->removeEventListener(keyboardListener);
//            NS_CC::Director::getInstance()->end();
            NS_CC::Director::getInstance()->popScene();
            break;
        default:
            break;
    }
}
