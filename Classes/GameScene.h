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
    bool _leftKeyDown;
    bool _rightKeyDown;
    bool _ballReleased;
    Paddle* _paddle;
    Ball* _ball;
    cocos2d::Vec2 _ballOffset;
    Grid* _grid;
    int _currentLevel;
    bool _levelFinished;
    
    void resetLevel();
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void update(float dt);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    // implement the "static create()" method manually
//    CREATE_FUNC(GameScene);
    /*:
     @param levelIndex - use -1 for empty level index
     */
    static GameScene* createWithLevel(int levelIndex);
};

#endif /* GameScene_h */
