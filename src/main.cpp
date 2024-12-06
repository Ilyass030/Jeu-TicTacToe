#include <array>
#include <iostream>
#include "Player.hpp"
#include "fonction.hpp"
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
    else
    {
        std::cout<<"Relancez et choisissez entre 1 et 2 .";
    }

    
    std::array <char,9> croquis {'0','1','2','3','4','5','6','7','8'};
    std::array <char,9> tab {};
    tab.fill('.');
    screen(croquis,tab);

    if (mode==2)
    {
        // std::cout<<"joueur 1, c'est à vous:"<<std::endl;
        // Player player1 {create_player()};
        // std::cout<<"joueur 2, c'est à vous:"<<std::endl;
        // Player player2 {create_player()};
        play_2x2(croquis,tab,player1,player2);
    }
    if (mode==1)
    {
        play_IA(croquis,tab,player,player_ia);
    }

}