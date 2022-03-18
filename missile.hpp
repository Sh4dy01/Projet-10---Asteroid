#pragma once

class Missile {
public:
    Missile();

    void Init(int l);
    void Move();
    void AddMissile(int l);

    int GetIndex();
    int GetPosL();
    int GetPosC();
    Missile *GetNext();
private:
    Missile *next;
    int posL, posC;
};