//
//  GameScene.cpp
//  Breakout-mobile
//
//  Created by Vidak Mijanovikj on 10/12/17.
//

#include "GameScene.h"
#include <iostream>

GameScene* GameScene::create(int width, int height)
{
    GameScene *pRet = new(std::nothrow) GameScene();
    if (pRet)
    {
        pRet->width = width;
        pRet->height = height;
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
    if (!NS_CC::Scene::init())
    {
        return false;
    }
    
    grid = Grid::create(width, height);
    this->addChild(grid);
    
    paddle = Paddle::create();
    paddle->setScale(120, 20);
    paddle->setPosition(100, 80);
    paddle->direction = NS_CC::Vec2::ZERO;
    paddle->velocity = 400;
    paddle->bounds = NS_CC::Rect(0, 0, width, height);
    paddle->scheduleUpdate();
    this->addChild(paddle);
    
    ball = Ball::create();
    ball->setScale(20);
    ballOffset = NS_CC::Vec2(0, paddle->getScaleY() / 2 + ball->getScaleY() / 2 + 5);
    ball->setPosition(paddle->getPosition() + ballOffset);
    ball->direction = NS_CC::Vec2(1, 1);
    ball->velocity = 300;
    ball->bounds = NS_CC::Rect(0, 0, width, height);
    ball->scheduleUpdate();
    this->addChild(ball);
    
    this->scheduleUpdate();
    auto listener = NS_CC::EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void GameScene::update(float dt)
{
    auto ballPosition = ball->getPosition();
    auto paddlePosition = paddle->getPosition();
    if (!ballReleased)
    {
        ball->setPosition(paddlePosition + ballOffset);
    }
    auto ballRect = ball->getRect();
    auto paddleRect = paddle->getRect();
    if (ballRect.intersectsRect(paddleRect))
    {
        ball->setDrawingColor(NS_CC::Color3B::RED);
        paddle->setDrawingColor(NS_CC::Color3B::GREEN);
        auto ballDirection = ball->direction;
        float xDiff = ballPosition.x - paddlePosition.x;
        float maxXDiff = ball->getScaleX() / 2 + paddle->getScaleX() / 2;
        float xDirection = xDiff / maxXDiff;
        ballDirection.x = xDirection;
        ballDirection.y = ballPosition.y < paddlePosition.y ? -1 : 1;
        ball->direction = ballDirection;
        std::cout << "bounce direction: " << ballDirection.x << ", "<< ballDirection.y << std::endl;
    }
    else
    {
        ball->setDrawingColor(NS_CC::Color3B::WHITE);
        paddle->setDrawingColor(NS_CC::Color3B::WHITE);
    }
    
    bool collisionDetected = false;
    for (int i = 0; i < grid->MAX_BRICK_COUNT_X; ++i)
    {
        if (collisionDetected)
        {
            break;
        }
        for (int j = 0; j < grid->MAX_BRICK_COUNT_Y; ++j)
        {
            Brick* brick = grid->getBrick(i, j);
            if (brick->getType() == BrickType::EMPTY)
            {
                continue;
            }
            if (ballRect.intersectsRect(brick->getRect()))
            {
                ball->setDrawingColor(NS_CC::Color3B::RED);
                brick->setDrawingColor(NS_CC::Color3B::BLUE);
                brick->clear();
                brick->setType(BrickType::EMPTY);
                auto ballDirection = ball->direction;
                auto brickPosition = brick->getPosition();
                float xDiff = (ballPosition.x - brickPosition.x) / (ball->getScaleX() / 2 + brick->getScaleX() / 2);
                float yDiff = (ballPosition.y - brickPosition.y) / (ball->getScaleY() / 2 + brick->getScaleY() / 2);
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
                ball->direction = ballDirection;
                std::cout << "ball dir: " << ballDirection.x << ", " << ballDirection.y << std::endl;
                collisionDetected = true;
                break;
            }
            else
            {
                brick->setDrawingColor(NS_CC::Color3B::WHITE);
            }
        }
    }
}

void GameScene::onKeyPressed(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event)
{
    switch (keyCode)
    {
        case NS_CC::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case NS_CC::EventKeyboard::KeyCode::KEY_A:
            leftKeyDown = true;
            paddle->direction.x = -1;
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case NS_CC::EventKeyboard::KeyCode::KEY_D:
            rightKeyDown = true;
            paddle->direction.x = 1;
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_SPACE:
            ballReleased = true;
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_R:
            // reset ball
            ballReleased = false;
            ball->direction = NS_CC::Vec2::ONE;
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_B:
            // reset board
            grid->reset();
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_N:
            ball->normalizedDirection = !ball->normalizedDirection;
            std::cout << "normalizedDirection: " << ball->normalizedDirection << std::endl;
            break;
        default:
            break;
    }
}

void GameScene::onKeyReleased(NS_CC::EventKeyboard::KeyCode keyCode, NS_CC::Event* event)
{
    switch (keyCode)
    {
        case NS_CC::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case NS_CC::EventKeyboard::KeyCode::KEY_A:
            leftKeyDown = false;
            if (rightKeyDown)
            {
                paddle->direction.x = 1;
            }
            else
            {
                paddle->direction.x = 0;
            }
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case NS_CC::EventKeyboard::KeyCode::KEY_D:
            rightKeyDown = false;
            if (leftKeyDown)
            {
                paddle->direction.x = -1;
            }
            else
            {
                paddle->direction.x = 0;
            }
            break;
        case NS_CC::EventKeyboard::KeyCode::KEY_ESCAPE:
            NS_CC::Director::getInstance()->end();
            break;
        default:
            break;
    }
}
