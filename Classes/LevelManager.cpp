//
//  LevelManager.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/19/17.
//

#include "LevelManager.h"

LevelManager* LevelManager::sharedInstance = nullptr;

LevelManager* LevelManager::getInstance()
{
    if (!sharedInstance)
    {
        sharedInstance = new (std::nothrow) LevelManager;
        CCASSERT(sharedInstance, "LevelManager not initialized!");
    }
    return sharedInstance;
}

void LevelManager::destroyInstance()
{
    if (sharedInstance)
    {
        delete sharedInstance;
        sharedInstance = nullptr;
    }
}

LevelManager::LevelManager()
{
    emptyLevel =
    {
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
    };
    
    LevelData level0 =
    {
        { REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
    };
    levels.push_back(level0);
    
    LevelData level1 =
    {
        { EMPTY,    EMPTY,      EMPTY,      REGULAR,    REGULAR,    EMPTY,      EMPTY,      EMPTY },
        { EMPTY,    EMPTY,      REGULAR,    REGULAR,    REGULAR,    REGULAR,    EMPTY,      EMPTY },
        { EMPTY,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    EMPTY },
        { REGULAR,  REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR },
        { EMPTY,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    REGULAR,    EMPTY },
        { EMPTY,    EMPTY,      REGULAR,    REGULAR,    REGULAR,    REGULAR,    EMPTY,      EMPTY },
        { EMPTY,    EMPTY,      EMPTY,      REGULAR,    REGULAR,    EMPTY,      EMPTY,      EMPTY },
        { EMPTY,    EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
    };
    levels.push_back(level1);
    
    LevelData level2 =
    {
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
        { REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR,    EMPTY,  REGULAR,    REGULAR },
    };
    levels.push_back(level2);
}

LevelData LevelManager::getLevel(int levelIndex)
{
    if (levelIndex >= 0 && levelIndex < levels.size())
    {
        return levels.at(levelIndex);
    }
    return emptyLevel;
}
