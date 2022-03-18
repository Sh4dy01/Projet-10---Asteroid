#pragma once

#include "missile.hpp"
#include "player.hpp"

class Playground{
public:
    Playground();

    char **tab_malloc();
    void InitTab();
    void PrintGame();
    void UpdateTab(Player player);

private:
    char **tab;
    int NBL, NBC;
};