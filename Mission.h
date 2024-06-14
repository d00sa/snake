#ifndef __Mission__
#define __Mission__

#include <bits/stdc++.h>
using namespace std;

class Mission {

    public:
        string pathToMission = "";
        int objectives[4];

        Mission() {};
        Mission(int level);

        void fetchMission();
        int getScoreObjective();
        int getGrowObjective();
        int getPoisonObjective();
        int getGateObjective();

};

#endif