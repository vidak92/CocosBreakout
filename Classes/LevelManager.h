//
//  LevelManager.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/19/17.
//

#ifndef LevelManager_h
#define LevelManager_h

#include "cocos2d.h"
#include "GameConfig.h"

class LevelManager
{
private:
    LevelData _emptyLevel;
    std::vector<LevelData> _levels;
    
    static LevelManager* _sharedInstance;
    LevelManager();
    
public:
    static LevelManager* getInstance();
    static void destroyInstance();
    LevelData getLevel(int levelIndex);
    int getLevelCount() { return _levels.size(); }
};

#endif /* LevelManager_h */
