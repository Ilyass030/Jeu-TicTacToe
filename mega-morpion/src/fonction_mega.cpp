#include <iostream>
#include <string>
#include <array>
#include "Player.hpp"
#include "terminal_ctrl.hpp"
#include "random.hpp"

// Player create_player ()
// {
    
//     std::cout<<"veuillez écrire votre nom / pseudo :" ;
//     std::string nom;
//     std::cin>>nom;
//     // Player player.name=nom;
//     std::cout<<std::endl;
//     std::cout<<"veuillez choisir votre symbol :" ;
//     char symbole;
//     std::cin>>symbole;
//     // Player player;
//     // player.symbol = symbole;
//     // Player player.symbol=symbole; version fausse
//     std::cout<<std::endl;
//     return Player {nom,symbole};
//     //  Player{nom,symbole};
// }

void draw_mega_morpion (std::array <std::array <char,9>,9>& mega_tab)
{
    for ( int i=0;i<9;i++)
    {
        for ( int j=0;j<9;j++)
        {
            if(j==3 || j==6 )
            {std::cout<<"|  ";};
            std::cout<<"| "<<mega_tab[i][3*i+j]<<" ";
        }
        
        std::cout<<"|"<<std::endl;
        if(i==2 || i==5)
            {
                std::cout<<std::endl;
            }
    }
}

void screen_mega(std::array <std::array <char,9>,9>& croquis,std::array <std::array <char,9>,9>& tab)
{
    terminal_ctrl::clear_screen();

    std::cout<<"case restante:"<<std::endl;
    draw_mega_morpion(croquis);
    std::cout<<std::endl;

    draw_mega_morpion(tab);
    std::cout<<std::endl;
}

// int rand(std::array <char,9>& croquis)
// {
//     int rand_position=random_int(0,8);
//     while (croquis[rand_position]==' ')
//     {
//         rand_position=random_int(0,8);
//     }
//     return rand_position;
// }

// void fill(std::array <char,9>& croquis,std::array <char,9>& tab,char default_char, int last_choice, char symbol)//permet de remplir le tableau avec le symbole necessaire
// {
//     while (croquis[last_choice]==' ')
//     {
//         std::cout<<"cette case est deja prise, changez : ";
//         std::cin>>last_choice;
//     }
//     tab[last_choice]=symbol;
//     croquis[last_choice]=' ';
// }