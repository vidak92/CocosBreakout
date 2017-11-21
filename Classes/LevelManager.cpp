//
//  LevelManager.cpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/19/17.
//

#include "LevelManager.h"

LevelManager* LevelManager::_sharedInstance = nullptr;

LevelManager* LevelManager::getInstance()
{
    if (!_sharedInstance)
    {
        _sharedInstance = new (std::nothrow) LevelManager;
        CCASSERT(_sharedInstance, "LevelManager not initialized!");
    }
    return _sharedInstance;
}

void LevelManager::destroyInstance()
{
    if (_sharedInstance)
    {
        delete _sharedInstance;
        _sharedInstance = nullptr;
    }
}

LevelManager::LevelManager()
{
    _emptyLevel =
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
    
//    LevelData level0 =
//    {
//        { EMPTY,      EMPTY,      EMPTY,      REGULAR,    EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//        { EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY,      EMPTY },
//    };
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
    _levels.push_back(level0);
    
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
    _levels.push_back(level1);
    
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
    _levels.push_back(level2);
}

LevelData LevelManager::getLevel(int levelIndex)
{
    if (levelIndex >= 0 && levelIndex < _levels.size())
    {
        return _levels.at(levelIndex);
    }
    return _emptyLevel;
}
