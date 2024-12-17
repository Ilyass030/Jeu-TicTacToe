#include <array>
#include <iostream>
#include "fonction_mega.hpp"
#include "terminal_ctrl.hpp"


int main()
{
    std::cout<<"Choisissez votre mode de jeu"<<std::endl;
    int mode {};
    std::cout<<"Tapez le 1 pour jouer contre une IA."<<std::endl;
    std::cout<<"Tapez le 2 pour une partie en multijoueur."<<std::endl;
    std::cin>>mode;

    Player player1 {};
    Player player2 {};

    if (mode==2)
    {
        std::cout<<"joueur 1, c'est à vous:"<<std::endl;
        player1 = create_player();
        std::cout<<"joueur 2, c'est à vous:"<<std::endl;
        player2 = {create_player()};
    }

    Player player {};
    Player player_ia {};

    if (mode==1)
    {
        player = {create_player()};
        player_ia.name="IA";
        std::cout<<"Choisissez un symbole pour l'IA : ";
        std::cin>>player_ia.symbol;
        std::cout<<std::endl;
    }


    std::array <char,9> croquis {'0','1','2','3','4','5','6','7','8'};
    std::array <std::array <char,9>,9> mega_croquis {};
    for (auto& elt:mega_croquis)
    {
        elt=croquis;
    }

    std::array <char,9> tab {};
    tab.fill('.');
    std::array <std::array <char,9>,9> mega_tab {};
    for (auto& elt:mega_tab)
    {
        elt=tab;
    }
    screen_mega(mega_croquis,mega_tab);
}