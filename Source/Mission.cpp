#include <bits/stdc++.h>
#include "Mission.h"
using namespace std;

Mission::Mission(int level) {

    pathToMission = "../Mission/Mission_" + to_string(level) + ".txt";
    fetchMission();

}

void Mission::fetchMission() {

    ifstream inFile(pathToMission);

    for (int i = 0; i < 4; i++) inFile >> objectives[i];
}

int Mission::getScoreObjective() { return objectives[0]; }
int Mission::getGrowObjective() { return objectives[1]; }
int Mission::getPoisonObjective() { return objectives[2]; }
int Mission::getGateObjective() { return objectives[3]; }