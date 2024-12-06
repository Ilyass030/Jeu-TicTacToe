#pragma once

Player create_player ();


void draw_game_board(std::array <char,9>& tab);

bool do_win(std::array <char,9>& tab, int& last_position);

void fill(std::array <char,9>& croquis,std::array <char,9>& tab,char default_char, int i, char symbol);

bool is_play_end(std::array <char,9>& croquis);

void screen(std::array <char,9>& croquis,std::array <char,9>& tab);

void play_2x2(std::array <char,9>& croquis,std::array <char,9>& tab,Player player1,Player player2);

void play_IA(std::array <char,9>& croquis,std::array <char,9>& tab,Player player,Player player_ia);

