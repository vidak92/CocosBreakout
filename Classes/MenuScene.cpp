//
//  MenuScene.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#include "MenuScene.h"
#include "GameScene.h"
#include "EditorScene.h"

USING_NS_CC;

bool MenuScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    auto playLabel = Label::createWithSystemFont("Play", "Arial", 32);
    auto playMenuItem = MenuItemLabel::create(playLabel, [](cocos2d::Ref* sender)
    {
        Director::getInstance()->pushScene(GameScene::createWithLevel(0));
    });
    
    auto editorLabel = Label::createWithSystemFont("Editor", "Arial", 32);
    auto editorMenuItem = MenuItemLabel::create(editorLabel, [](cocos2d::Ref* sender)
    {
        Director::getInstance()->pushScene(EditorScene::create());
    });
    
    auto menu = Menu::create(playMenuItem, editorMenuItem, NULL);
    menu->alignItemsVertically();
    addChild(menu);
    
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(MenuScene::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(MenuScene::onKeyReleased, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    return true;
}

void MenuScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{
    switch (keyCode)
    {
        default:
            break;
    }
}

void MenuScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
    switch (keyCode)
    {
        case EventKeyboard::KeyCode::KEY_ESCAPE:
            Director::getInstance()->end();
            break;
        default:
            break;
    }
}
