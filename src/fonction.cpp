#include <iostream>
#include <string>
#include <array>
#include "Player.hpp"


void create_player (Player &  plyer)
{
    std::cout<<"veuillez écrire votre nom / pseudo :" ;
    std::string name;
    std::cin>>name;
    plyer.name=name;
    std::cout<<std::endl;
    std::cout<<"veuillez choisir votre symbol :" ;
    // char symbol;
    std::cin>>plyer.symbol;
    std::cout<<std::endl;
}

void draw_game_board(std::array <char,9> tab)
{
    for (int i=0;i<3;i++)
    {
        std::cout<<"| ";
        for (int j=0;j<3;j++)
            {
                std::cout<<tab[3*i+j];
                if (j==2){std::cout<<" |";}
                else {std::cout<<" | ";}
            }
        std::cout<<std::endl;
    }
}