#include <stdio.h>

#include "playground.h"

NBL = NBL_DEFAULT;
NBC = NBC_DEFAULT;

char **tab_malloc(){
    char **tab_ = (char**)malloc(NBL * sizeof(char*)); // "Les lignes"

    for(int l=0; l<NBL; l++)
        tab_[l] = (char*)malloc(NBC * sizeof(char));     // Les colonnes sont "attachées" à =tab[l]=
    return tab_;
}

void initTab(){
    tab = tab_malloc();
    for (int l=0; l<NBL; l++) {
        for (int c=0; c<NBC; c++) {
	        tab[l][c] = '.';
        }
    }
}

void printGame(){
    for (int l=0; l<NBL; l++) {
        for (int c=0; c<NBC; c++) {
            printf("%c", tab[l][c]);
        }
    }
}


