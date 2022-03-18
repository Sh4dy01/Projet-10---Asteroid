#include "missile.hpp"
#include "constants.hpp"

#include <stdlib.h>
#include <iostream>

Missile::Missile() {
    this->posL = 0;
    this->posC = 1;
    this->next = NULL;
}

void Missile::Init(int l) {
    this->posL = l;
}

void Missile::AddMissile(int l) {
    if (next != NULL) {
        next->AddMissile(l);
    } else {
        Missile *temp = new Missile();
        next = temp;
        next->Init(l);
    }
}

void Missile::Move() {
    if (posC < NBC_DEFAULT) { this->posC++; }

    if (next != NULL) {
        next->Move();
    }
}


int Missile::GetPosL(){ return this->posL; }
int Missile::GetPosC(){ return this->posC; }
Missile *Missile::GetNext(){ return this->next; }