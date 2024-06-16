#include "Gate.h"
#include "Map.h"
#include <bits/stdc++.h>
using namespace std;

Gate::Gate (Map& _map) { setGatePos(_map); }

void Gate::setGatePos(Map& _map) {
    
    srand((unsigned int)time(NULL));

    int x1 = rand() % _map.GetMapCols();
    int y1 = rand() % _map.GetMapRows();
    int x2 = rand() % _map.GetMapCols();
    int y2 = rand() % _map.GetMapRows();

    if (_map.GetMapValue(y1,x1) == 1) posA = make_pair(y1, x1);
    else {
        while (_map.GetMapValue(y1,x1) != 1) {
            x1 = rand() % _map.GetMapCols();
            y1 = rand() % _map.GetMapRows();
            posA = make_pair(y1, x1);
        }
    }

    if ((_map.GetMapValue(y2,x2) == 1) && (x1 != x2 || y1 != y2) && isGateEntranceShared(x1, y1, x2, y2)) {
        posB = make_pair(y2, x2);
    }
    else {
        while (true) {
            if ((_map.GetMapValue(y2,x2) == 1) && (x1 != x2 || y1 != y2) && isGateEntranceShared(x1, y1, x2, y2)) {
                break;
            }
            x2 = rand() % _map.GetMapCols();
            y2 = rand() % _map.GetMapRows();
            posB = make_pair(y2, x2);
        }
    }

    setDirections(_map);

}

void Gate::setDirections(Map& _map) {

    int r = _map.GetMapRows();  // height
    int c = _map.GetMapCols();  // width

    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (int i = 0; i < 4; i++) {
        int newY = posA.first + directions[i][0];
        int newX = posA.second + directions[i][1];
        if ((0 <= newY && newY < r) && (0 <= newX && newX < c)) {
            posA_Directions[i] = _map.GetMapValue(newY, newX);
        }
        else posA_Directions[i] = -1;
    }

    for (int i = 0; i < 4; i++) {
        int newY = posB.first + directions[i][0];
        int newX = posB.second + directions[i][1];
        if ((0 <= newY && newY < r) && (0 <= newX && newX < c)) {
            posB_Directions[i] = _map.GetMapValue(newY, newX);
        }
        else posB_Directions[i] = -1;
    }

}

int Gate::getDirections(int gateNum, int index) {

    return (gateNum == 1 ? posA_Directions[index] : posB_Directions[index]);

}

pair <int, int> Gate::getGatePos(int gateNum) {

    return (gateNum == 1 ? posA : posB);

}

pair <int, int> Gate::getOtherGatePos(pair <int, int> pos) {

    if (pos == posA) return posB;
    else if (pos == posB) return posA;

}

bool Gate::isGateEntranceShared(int x1, int y1, int x2, int y2) {

    int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
    bool ret = true;

    for (int i = 0; i < 8; i++) {
        if ((y2 == (y1 + dir[i][0])) && (x2 == (x1 + dir[i][1]))){
            ret = false;
            return ret;
        }
    }
    return ret;
}