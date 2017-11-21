//
//  GameScene.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/12/17.
//

#include "GameScene.h"
#include "LevelManager.h"
#include <iostream>

USING_NS_CC;

GameScene* GameScene::createWithLevel(int levelIndex)
{
    GameScene *pRet = new(std::nothrow) GameScene();
    if (pRet)
    {
        pRet->_currentLevel = levelIndex;
        if (pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    _levelFinished = false;
    
    LevelData levelData = LevelManager::getInstance()->getLevel(_currentLevel);
    _grid = Grid::create(levelData);
    this->addChild(_grid);
    
    _paddle = Paddle::create();
    _paddle->setScale(120, 20);
    _paddle->setPosition(100, 40);
    _paddle->direction = Vec2::ZERO;
    _paddle->velocity = 400;
    _paddle->bounds = Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    _paddle->scheduleUpdate();
    this->addChild(_paddle);
    
    _ball = Ball::create();
    _ball->setScale(20);
    _ballOffset = Vec2(0, _paddle->getScaleY() / 2 + _ball->getScaleY() / 2 + 5);
    _ball->setPosition(_paddle->getPosition() + _ballOffset);
    _ball->direction = _ball->initialDirection;
    _ball->velocity = 300;
    _ball->bounds = Rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    _ball->scheduleUpdate();
    this->addChild(_ball);
    
    this->scheduleUpdate();
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void GameScene::update(float dt)
{
    if (_levelFinished)
    {
        return;
    }
    
    auto ballPosition = _ball->getPosition();
    auto paddlePosition = _paddle->getPosition();
    if (!_ballReleased)
    {
        _ball->setPosition(paddlePosition + _ballOffset);
    }
    
    // handle wall collisions
    auto ballRect = _ball->getRect();
    auto paddleRect = _paddle->getRect();
    if (ballRect.intersectsRect(paddleRect))
    {
        _ball->setDrawingColor(Color3B::RED);
        _paddle->setDrawingColor(Color3B::GREEN);
        auto ballDirection = _ball->direction;
        float xDiff = ballPosition.x - paddlePosition.x;
        float maxXDiff = _ball->getScaleX() / 2 + _paddle->getScaleX() / 2;
        float xDirection = xDiff / maxXDiff;
        ballDirection.x = xDirection;
        ballDirection.y = ballPosition.y < paddlePosition.y ? -1 : 1;
        _ball->direction = ballDirection;
        std::cout << "bounce direction: " << ballDirection.x << ", "<< ballDirection.y << std::endl;
    }
    else
    {
        _ball->setDrawingColor(Color3B::WHITE);
        _paddle->setDrawingColor(Color3B::WHITE);
    }
    
    // handle brick collisions
    for (auto it = _grid->begin(); it != _grid->end(); ++it)
    {
        Brick* brick = *it;
        if (brick->getType() == BrickType::EMPTY)
        {
            continue;
        }
        if (ballRect.intersectsRect(brick->getRect()))
        {
            _ball->setDrawingColor(Color3B::RED);
            brick->setDrawingColor(Color3B::BLUE);
            if (brick->getType() == BrickType::REGULAR)
            {
                brick->setType(BrickType::EMPTY);
            }
            auto ballDirection = _ball->direction;
            auto brickPosition = brick->getPosition();
            float xDiff = (ballPosition.x - brickPosition.x) / (_ball->getScaleX() / 2 + brick->getScaleX() / 2);
            float yDiff = (ballPosition.y - brickPosition.y) / (_ball->getScaleY() / 2 + brick->getScaleY() / 2);
            std::cout << "x diff: " << xDiff << std::endl;
            std::cout << "y diff: " << yDiff << std::endl;
            if (abs(xDiff) >= 0.85 && abs(yDiff) >= 0.85)
            {
                float xSign = xDiff >= 0 ? 1 : -1;
                float ySign = yDiff >= 0 ? 1 : -1;
                ballDirection.x = abs(ballDirection.x) * xSign;
                ballDirection.y = abs(ballDirection.y) * ySign;
            }
            else if (abs(xDiff) > abs(yDiff))
            {
                ballDirection.x *= -1;
            }
            else
            {
                ballDirection.y *= -1;
            }
            _ball->direction = ballDirection;
            std::cout << "ball dir: " << ballDirection.x << ", " << ballDirection.y << std::endl;
            break;
        }
        else
        {
            brick->setDefaultDrawingColor();
        }
    }
    
    // check if level is finished
    _levelFinished = true;
    for (auto it = _grid->begin(); it != _grid->end(); ++it)
    {
        Brick* brick = *it;
        BrickType type = brick->getType();
        if (type != EMPTY && type != UNBREAKABLE)
        {
            _levelFinished = false;
            break;
        }
    }
    if (_levelFinished)
    {
        if (++_currentLevel == LevelManager::getInstance()->getLevelCount())
        {
            _currentLevel = 0;
        }
        _ball->direction = Vec2::ZERO;
        _ball->setDrawingColor(Color3B::WHITE);
        _paddle->direction = Vec2::ZERO;
        getEventDispatcher()->pauseEventListenersForTarget(this);
        auto delayAction = DelayTime::create(1.0f);
        auto callFuncAction = CallFunc::create(CC_CALLBACK_0(GameScene::resetLevel, this));
        runAction(Sequence::create(delayAction, callFuncAction, NULL));
    }
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            _leftKeyDown = true;
            _paddle->direction.x = -1;
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            _rightKeyDown = true;
            _paddle->direction.x = 1;
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
            _ballReleased = true;
            break;
        case EventKeyboard::KeyCode::KEY_B:
            // reset ball
            _ballReleased = false;
            _ball->direction = _ball->initialDirection;
            break;
        case EventKeyboard::KeyCode::KEY_G:
            // reset board
            _grid->reset();
            break;
        case EventKeyboard::KeyCode::KEY_R:
            resetLevel();
            break;
        case EventKeyboard::KeyCode::KEY_N:
            _ball->normalizedDirection = !_ball->normalizedDirection;
            std::cout << "normalizedDirection: " << _ball->normalizedDirection << std::endl;
            break;
        default:
            break;
    }
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode)
    {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            _leftKeyDown = false;
            if (_rightKeyDown)
            {
                _paddle->direction.x = 1;
            }
            else
            {
                _paddle->direction.x = 0;
            }
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            _rightKeyDown = false;
            if (_leftKeyDown)
            {
                _paddle->direction.x = -1;
            }
            else
            {
                _paddle->direction.x = 0;
            }
            break;
        case EventKeyboard::KeyCode::KEY_ESCAPE:
//            Director::getInstance()->end();
            Director::getInstance()->popScene();
            break;
        default:
            break;
    }
}

void GameScene::resetLevel()
{
    _levelFinished = false;
    _ballReleased = false;
    _ball->direction = _ball->initialDirection;
    LevelData levelData = LevelManager::getInstance()->getLevel(_currentLevel);
    _grid->setLevelData(levelData);
    _grid->reset();
    getEventDispatcher()->resumeEventListenersForTarget(this);
}
