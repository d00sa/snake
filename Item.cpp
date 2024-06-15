#include "Item.h"
#include <bits/stdc++.h>
#define LoopCount 200
using namespace std;

Item::Item(Map _map, Snake _snake) {

    for (int i = 0; i < LoopCount; i++) {
        setItemPos(_map);
        if (overlapWithSnake(_snake)) continue;
        else break;
    }

}

void Item::setItemPos(Map _map) {

    srand((unsigned int)time(NULL));

    int x = (rand() % (_map.GetMapCols() - 1)) + 1;
    int y = (rand() % (_map.GetMapRows() - 1)) + 1;

    if (_map.GetMapValue(y, x) == 0) {
        itemPos = pair <int, int> (y, x);
        itemTypeCode = (rand() % 2 == 0 ? 1 : 0);
    }
    else {
        while (_map.GetMapValue(y, x) != 0) {
            int x = (rand() % (_map.GetMapCols() - 1)) + 1;
            int y = (rand() % (_map.GetMapRows() - 1)) + 1;
            if (_map.GetMapValue(y, x) == 0) {
                itemPos = pair <int, int> (y, x);
                itemTypeCode = (rand() % 2 == 0 ? 1 : 0);
                break;
            }
        }
    }

}

bool Item::overlapWithSnake(Snake _snake) {

    for (int i = 0; i < _snake.GetSnakeLength(); i++) {
        int nx = _snake.GetSnakePos()[i].second;
        int ny = _snake.GetSnakePos()[i].first;
        if ((ny == itemPos.first) || (nx == itemPos.second)) return true;
    }

    return false;

}

pair <int, int> Item::getItemPos() { return itemPos; }

bool Item::isGrowthItem() { return !itemTypeCode; }

bool Item::operator==(Item &i) {
    return (itemPos.first == i.itemPos.first) && (itemPos.second == i.itemPos.second);
}