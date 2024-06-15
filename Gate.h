#ifndef __GATE__
#define __GATE__

#include "Map.h"
#include "Snake.h"
#include <bits/stdc++.h>
using namespace std;

class Gate {

    public:
        Gate() {};
        Gate(Map _map);

        pair <int, int> posA, posB;
        int posA_Directions[4], posB_Directions[4];

        void setGatePos(Map _map);
        void setDirections(Map _map);
        int getDirections(int gateNum, int index);

        pair <int, int> getGatePos(int gateNum);
        pair <int, int> getOtherGatePos(pair <int, int> pos);

        bool isGateEntranceShared(int x1, int y1, int x2, int y2);
        
};

#endif