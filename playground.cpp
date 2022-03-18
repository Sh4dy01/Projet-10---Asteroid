#include "playground.hpp"
#include "player.hpp"
#include "missile.hpp"
#include "constants.hpp"

#include <stdlib.h>
#include <iostream>

Playground::Playground(){
    this->NBL = NBL_DEFAULT;
    this->NBC = NBC_DEFAULT;
    this->tab = NULL;
}

char** Playground::tab_malloc(){
    char **tab_ = (char**)malloc(NBL * sizeof(char*)); // "Les lignes"

    for(int l=0; l<NBL; l++)
        tab_[l] = (char*)malloc(NBC * sizeof(char));     // Les colonnes sont "attachées" à =tab[l]=
    return tab_;
}

void Playground::InitTab(){
    tab = tab_malloc();

    for (int l=0; l<NBL; l++) {
        for (int c=0; c<NBC; c++) {
            if (l == PLAYER_START && c == 0){
                tab[l][c] = PLAYER;
            } else {
	            tab[l][c] = EMPTY;
            }
        }
    }
}

void Playground::PrintGame(){
    for (int l=0; l<NBL; l++) {
        std::cout << l+1;
        
        for (int c=0; c<NBC; c++) {
            std::cout << tab[l][c];
        }
        std::cout << std::endl;
    }
}

void Playground::UpdateTab(Player player) {

    // --- MISSILES --- //
    if(player.GetMissiles() != NULL) {
        Missile *temp = player.GetMissiles();

        while(temp != NULL) {
            tab[temp->GetPosL()][temp->GetPosC()] = MISSILE;

            if (temp->GetPosC() > 1 && temp->GetPosC() < NBC_DEFAULT){
                tab[temp->GetPosL()][temp->GetPosC()-1] = EMPTY;
            } else if (temp->GetPosC() == NBC_DEFAULT) {
                tab[temp->GetPosL()][temp->GetPosC()-1] = EMPTY;
                tab[temp->GetPosL()][temp->GetPosC()] = EMPTY;
            }
            temp = temp->GetNext();
        }
    }

    // --- ASTEROIDES --- //
    if(player.GetAsteroids() != NULL) {
        Asteroid *temp = player.GetAsteroids();

        while(temp != NULL) {

            if (temp->GetPosC() < NBC_DEFAULT && temp->GetPosC() > 0){
                tab[temp->GetPosL()][temp->GetPosC()] = ASTEROID;
                tab[temp->GetPosL()][temp->GetPosC()+1] = EMPTY;

            } else if ((temp->GetPosC()-1) == 0) {
                tab[temp->GetPosL()][temp->GetPosC()] = EMPTY;
                tab[temp->GetPosL()][temp->GetPosC()+1] = EMPTY;
            }

            temp = temp->GetNext();
        }
    }

    // --- PLAYER --- //
    tab[player.GetPos()][0] = PLAYER;
    tab[player.GetPrevPos()][0] = EMPTY;

    PrintGame(); 
}