#include <bits/stdc++.h>
#include "Level.h"
using namespace std;

Level::Level() { nowLevel = 0; }

int Level::getNowLevel() { return nowLevel; }
void Level::increaseLevel() { nowLevel += 1; }

void Level::buildMap() {

    for (int i = 0; i < 4; i++) {
        mapArray[i] = Map(i);
        missionList[i] = Mission(i);
        isCompleted[i] = false;
    }

}
void Level::markCompleted(bool status) { isCompleted[nowLevel] = status; }
bool Level::checkCompleted() { return isCompleted[nowLevel]; }

Map Level::getNowMap() { return mapArray[nowLevel]; }
Mission Level::getMission() { return missionList[nowLevel]; }