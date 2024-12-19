#pragma once

#include <string>


struct Player
{
    std::string name {};
    char symbol {};
};

Player create_player ();

void draw_mega_morpion (std::array <std::array <char,9>,9>& mega_tab,bool affichage_complet);

bool one_case(std::array <char,9>& validation,int last_position);

void screen_mega(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab,int last_position,std::array <char,9>& validation);

//bool do_win(std::array <char,9>& tab,int last_position);

int play(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab, int choice, Player player);

void play_2x2(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab,Player player1,Player player2,std::array <char,9>& validation);

// int rand(std::array <char,9>& croquis);