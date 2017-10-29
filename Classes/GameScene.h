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

USING_NS_CC;

class GameScene : public cocos2d::Scene
{
private:
    static const int BRICK_COUNT_X = 8;
    static const int BRICK_COUNT_Y = 5;
    static const int BRICK_GAP = 10;
    static const int BRICK_SCALE_X = 65;
    static const int BRICK_SCALE_Y = 30;
    static const int BRICK_OFFSET_X = 55;
    static const int BRICK_OFFSET_Y = 35;
    
    int width;
    int height;
    bool leftKeyDown;
    bool rightKeyDown;
    bool ballReleased;
    Paddle* paddle;
    Ball* ball;
    NS_CC::Vec2 ballOffset;
    GameNode* bricks[BRICK_COUNT_X][BRICK_COUNT_Y];
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static NS_CC::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void update(float dt);
    void onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
    void onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    static GameScene* create(int width, int height);
};

#endif /* GameScene_h */
