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
    LevelData emptyLevel;
    std::vector<LevelData> levels;
    std::vector<LevelData> customLevels;
    
    static LevelManager* sharedInstance;
    LevelManager();
    
public:
    static LevelManager* getInstance();
    static void destroyInstance();
    LevelData getLevel(int levelIndex);
    int getLevelCount() { return levels.size(); }
};

#endif /* LevelManager_h */
