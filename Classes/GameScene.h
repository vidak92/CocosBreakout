//
//  GameScene.hpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/12/17.
//

#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"
#include "Paddle.h"
#include "Ball.h"
#include "Grid.h"

class GameScene : public cocos2d::Scene
{
private:
    bool leftKeyDown;
    bool rightKeyDown;
    bool ballReleased;
    Paddle* paddle;
    Ball* ball;
    NS_CC::Vec2 ballOffset;
    Grid* grid;
    int _currentLevel;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static NS_CC::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void update(float dt);
    void onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
    void onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
    
    // implement the "static create()" method manually
//    CREATE_FUNC(GameScene);
    /*:
     @param levelIndex - use -1 for empty level index
     */
    static GameScene* createWithLevel(int levelIndex);
};

#endif /* GameScene_h */
