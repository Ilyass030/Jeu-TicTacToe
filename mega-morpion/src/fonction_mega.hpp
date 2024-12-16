#pragma once

#include <string>


// struct Player
// {
//     std::string name {};
//     char symbol {};
// };

// Player create_player ();

void screen_mega(std::array <char,9>& croquis,std::array <char,9>& tab);

void draw_mega_morpion (std::array <std::array <char,9>,9>& mega_tab);

// int rand(std::array <char,9>& croquis);