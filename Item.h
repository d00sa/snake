#ifndef ITEM_H
#define ITEM_H

#pragma once
#include "Map.h"
#include "Snake.h"

#include <bits/stdc++.h>
using namespace std;

class Item {

    public:
        Item() {};
        Item(Map _map, Snake _snake);
        
        int itemTypeCode;  // 0 : Growth // 1 : Poison
        pair <int, int> itemPos;
        pair <int, int> getItemPos();

        void setItemPos(Map _map);
        bool overlapWithSnake(Snake _snake);
        bool isGrowthItem();

        bool operator==(Item& i);

};
#endif