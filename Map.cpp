#include "Map.h"

Map::Map() {}

Map::Map(int stage){
    _mapPath = "../MapData/"s + "Level_" + to_string(stage) + ".txt";
    LoadMap();
}

void Map::LoadMap(){
    fstream fs; 
    fs.open(_mapPath);
    fs >> _mapRows >> _mapCols;
    _map = new int*[_mapRows];
    for (int i = 0; i < _mapRows; i++) {
        _map[i] = new int [_mapCols];
        for (int j = 0; j < _mapCols; j++) {
            fs >> _map[i][j];
        }
    }
}