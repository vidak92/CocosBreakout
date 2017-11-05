//
//  MenuScene.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/5/17.
//

#include "MenuScene.h"
#include "GameScene.h"
#include "EditorScene.h"

bool MenuScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    auto playLabel = NS_CC::Label::createWithSystemFont("Play", "Arial", 32);
    auto playMenuItem = NS_CC::MenuItemLabel::create(playLabel, [](cocos2d::Ref* sender)
    {
        NS_CC::Director::getInstance()->pushScene(GameScene::create(SCREEN_WIDTH, SCREEN_HEIGHT));
    });
    
    auto editorLabel = NS_CC::Label::createWithSystemFont("Editor", "Arial", 32);
    auto editorMenuItem = NS_CC::MenuItemLabel::create(editorLabel, [](cocos2d::Ref* sender)
    {
        NS_CC::Director::getInstance()->pushScene(EditorScene::create());
    });
    
    auto menu = NS_CC::Menu::create(playMenuItem, editorMenuItem, NULL);
    menu->alignItemsVertically();
    addChild(menu);
    
    auto keyboardListener = NS_CC::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(MenuScene::onKeyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(MenuScene::onKeyReleased, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    return true;
}

void MenuScene::onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event *event)
{
    switch (keyCode)
    {
        default:
            break;
    }
}

void MenuScene::onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event *event)
{
    switch (keyCode)
    {
        case NS_CC::EventKeyboard::KeyCode::KEY_ESCAPE:
            NS_CC::Director::getInstance()->end();
            break;
        default:
            break;
    }
}
