#pragma once

class Asteroid {
public:
    Asteroid();

    void Init();
    void Move();
    void AddAsteroid();

    int GetPosL();
    int GetPosC();
    Asteroid *GetNext();

private:
    Asteroid *next;
    int posL, posC;
};