#include "player.hpp"
#include "constants.hpp"

#include <conio.h>
#include <iostream>
#include <bits/stdc++.h>

Player::Player() {
    this->pos = PLAYER_START;
    this->prevPos = PLAYER_START;
    this->missiles = NULL;
    this->count = SPAWN_DELAY;
    this->playerHit = false;

    this->asteroids = new Asteroid();
}

void Player::Shot() {
    if (missiles == NULL)
    {
        this->missiles = new Missile();
        this->missiles->Init(this->pos);
    } else {
        this->missiles->AddMissile(this->pos);
    }
}

bool Player::GetInput() {
    if (kbhit()) {
        char key = getch();
        
        if (int(key) == KEY_UP && this->pos > 0) {
            this->Move(false);
            return true;

        } else if (int(key) == KEY_DOWN && this->pos < NBL_DEFAULT-1) {
            this->Move(true);
            return true;

        } else if (int(key) == SPACE_BAR) { this->Shot(); }
    }

    return false;
}

void Player::Move(bool down) { 
    if (down){
        this->pos++;
        this->prevPos = pos-1;
    } else {
        this->pos--;
        this->prevPos = pos+1;
    }

    //Missile limit
    if (missiles != NULL) {
        this->missiles->Move();
        std::cout << "Missile: " << missiles->GetPosC() << std::endl;

        if (this->missiles->GetPosC() == this->asteroids->GetPosC() && this->missiles->GetPosL() == this->asteroids->GetPosL()) {
            this->missiles = this->missiles->GetNext();
            this->asteroids = this->asteroids->GetNext();

            std::cout << "ASTEROID HIT" << std::endl;

        } else if (this->missiles->GetPosC()+1 > NBC_DEFAULT){
            this->missiles = this->missiles->GetNext();
        }
    }

    // Asteroid Spawn Behavior
    count--;
    if (count == 0) { 
        count = SPAWN_DELAY; 

        if (asteroids == NULL) {
            asteroids = new Asteroid();

        } else { asteroids->AddAsteroid(); }
    }

    //Asteroid limit
    if (asteroids != NULL) {
        this->asteroids->Move();
        std::cout << "Asteroid: " << asteroids->GetPosC() << std::endl;

        if (asteroids->GetPosC() == 0 && asteroids->GetPosL() == this->GetPos()) {
            this->playerHit = true;
        }
        
        if (this->asteroids->GetPosC() == 0) {
            this->asteroids = this->asteroids->GetNext();
        }
    }
}

bool Player::IsPlayerHit() { return playerHit; }
int Player::GetPos() { return pos; }
int Player::GetPrevPos() { return prevPos; }
Missile *Player::GetMissiles() { return missiles; }
Asteroid *Player::GetAsteroids() { return asteroids; }