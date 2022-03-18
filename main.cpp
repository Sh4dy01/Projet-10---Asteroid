#include "playground.hpp"
#include "player.hpp"
#include "constants.hpp"

#include <iostream>

int main(){
    srand(time(NULL));

    Playground playground;
    Player player;

    playground.InitTab();
    playground.PrintGame(); 
    
    do
    {
        if(player.GetInput()) { 
            playground.UpdateTab(player);
        }
         
    } while (!player.IsPlayerHit());
}