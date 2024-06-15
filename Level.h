#ifndef LEVEL_H
#define LEVEL_H

#include "Map.h"
#include "Mission.h"

class Level {

    public:
        Map mapArray[4];
        Mission missionList[4];
        bool isCompleted[4];
        int nowLevel;

        Level();

        int getNowLevel();
        void increaseLevel();
        
        void buildMap();
        void markCompleted(bool status);
        bool checkCompleted();

        Map getNowMap();
        Mission getMission();

};


#endif