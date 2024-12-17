#pragma once

#include <string>


struct Player
{
    std::string name {};
    char symbol {};
};

Player create_player ();

void screen_mega(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab);

void draw_mega_morpion (std::array <std::array <char,9>,9>& mega_tab,bool affichage_complet);

// int rand(std::array <char,9>& croquis);