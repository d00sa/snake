#include "Snake.h"
Snake::Snake(Map &map) {
    _direction = 'r';
    _snakeLength = 3;
    _maxSnakeLength = 3;
    _isDead = false;
    for (int i = 0; i < map.GetMapRows(); i++) {
        for (int j = 0; j < map.GetMapCols(); j++) {
            if (map.GetMapValue(i,j) == 3){
                _snakePos.push_back(make_pair(i,j));
                map.SetMapValue(i,j,0);
            }
            else if (map.GetMapValue(i,j) == 4){
                _snakePos.push_back(make_pair(i,j));
                _tail.push_back(make_pair(i,j));
                map.SetMapValue(i,j,0);
            }
        }        
    }        
}

void Snake::SetKeyDir() {
    int Key = getch();
    switch(Key) {
        case KEY_LEFT:
            if (_direction != 'r') {
                _direction = 'l';
                break;
            } else {
                _isDead = true;
                break;
            }
        case KEY_RIGHT:
            if (_direction != 'l') {
                _direction = 'r';
                break;
            } else {
                _isDead = true;
                break;
            }
        case KEY_UP:
            if (_direction != 'd') {
                _direction = 'u';
                break;
            } else {
                _isDead = true;
                break;
            }
        case KEY_DOWN:
            if (_direction != 'u') {
                _direction = 'd';
                break;
            } else {
                _isDead = true;
                break;
            }
    }
}

void Snake::SnakeUpdate() {
    if (_direction == 'l') {
        _snakePos.insert(_snakePos.begin(),make_pair(_snakePos[0].first,_snakePos[0].second - 1));    
    } else if (_direction == 'r') {
        _snakePos.insert(_snakePos.begin(),make_pair(_snakePos[0].first,_snakePos[0].second + 1));        
    } else if (_direction == 'u') {
        _snakePos.insert(_snakePos.begin(),make_pair(_snakePos[0].first - 1,_snakePos[0].second));        
    } else if (_direction == 'd') {
        _snakePos.insert(_snakePos.begin(),make_pair(_snakePos[0].first + 1,_snakePos[0].second));        
    }
    _tail.pop_back();
    _tail.push_back(make_pair(_snakePos[_snakePos.size()-1].first, _snakePos[_snakePos.size()-1].second));
    _snakePos.pop_back();

    // 스네이크 fail 체크
    CheckSnakeHeadPos();
    CheckSnakeLength();
}

void Snake::CheckSnakeHeadPos() {
    pair<int,int> _head = _snakePos[0];
    for(int i=1; i< _snakeLength; i++) {
        pair<int,int> _body = _snakePos[i];
        if(_body.first == _head.first && _body.second == _head.second) {
            _isDead = true;
            break;
        }
    }
}
