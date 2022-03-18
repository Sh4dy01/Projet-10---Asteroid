#include "asteroid.hpp"
#include "constants.hpp"

#include <stdlib.h>

Asteroid::Asteroid() {
    this->posL = 0;
    this->posC = NBC_DEFAULT;
    this->next = NULL;

    this->Init();
}

void Asteroid::Init() {
    int number = rand() % (NBL_DEFAULT);

    this->posL = number;
}

void Asteroid::AddAsteroid() {
    if (next != NULL)
    {
        next->AddAsteroid();
    } else {
        Asteroid *temp = new Asteroid();
        next = temp;
        next->Init();
    }
}

void Asteroid::Move() {
    if (posC > 0) { this->posC--; }

    if (next != NULL) {
        next->Move();
    }
}

int Asteroid::GetPosL(){ return this->posL; }
int Asteroid::GetPosC(){ return this->posC; }
Asteroid *Asteroid::GetNext(){ return this->next; }