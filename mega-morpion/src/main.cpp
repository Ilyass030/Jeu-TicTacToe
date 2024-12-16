#include <array>
#include <iostream>
#include "fonction.hpp"
#include "fonction_mega.hpp"
#include "terminal_ctrl.hpp"


main()
{
    std::array <char,9> ex {};
    ex.fill('.');
    std::array <std::array <char,9>,9> mega_tab {};
    // for ( std::array <char,9> elt:mega_tab)
    // {
    //     // elt.fill('.');
    //     elt=ex;
    //     //draw_game_board(elt);

    // }
    for ( int i=0;i<9;i++)
    {
        for ( int j=0;j<9;j++)
        {
            mega_tab[i][3*i+j]='.';
        }
    }
    draw_mega_morpion(mega_tab);
}