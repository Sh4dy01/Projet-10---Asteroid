#pragma once

#include "missile.hpp"
#include "asteroid.hpp"

class Player{
public:
    Player();

    void Spawn();
    bool GetInput();
    void Shot();
    void Move(bool);
    
    bool IsPlayerHit();
    int GetPos();
    int GetPrevPos();
    Missile *GetMissiles();
    Asteroid *GetAsteroids();
    
private:
    int pos;
    int prevPos;
    int count;
    bool playerHit;

    Missile *missiles;
    Asteroid *asteroids;
};

