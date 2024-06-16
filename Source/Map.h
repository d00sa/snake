#ifndef MAP_H
#define MAP_H
#pragma once

#include <iostream>
#include <utility>
#include <string>
#include <fstream>
using namespace std;
class Map {
private:
    int _mapRows;
    int _mapCols;
    int** _map;
    string _mapPath;
public:
    Map();
    Map(int stage); //���� �� �� �ҷ�����
    inline int GetMapRows() { return _mapRows; }
    inline int GetMapCols() { return _mapCols; }
    inline int GetMapValue(int r ,int c) { return _map[r][c]; }
    inline void SetMapValue(int r ,int c, int value) { _map[r][c] = value; }
    void LoadMap();
};
#endif