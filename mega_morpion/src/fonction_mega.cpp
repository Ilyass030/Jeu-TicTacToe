#include <iostream>
#include <string>
#include <array>
#include "fonction_mega.hpp"
#include "terminal_ctrl.hpp"
//#include "random.hpp"

Player create_player ()
{
    
    std::cout<<"veuillez écrire votre nom / pseudo :" ;
    std::string nom;
    std::cin>>nom;
    std::cout<<std::endl;
    std::cout<<"veuillez choisir votre symbol :" ;
    char symbole;
    std::cin>>symbole;
    std::cout<<std::endl;
    return Player {nom,symbole};
}

void draw_mega_morpion (std::array <std::array <char,9>,9>& mega_tab,bool affichage_complet)
{
    for (int a=0;a<3;a++)
    {
        for (int b=0;b<3;b++)
        {
            for ( int i=0;i<3;i++)
            {
                for ( int j=0;j<3;j++)
                {
                    //if(3*j==3 || 3*j==6 ){std::cout<<"|  ";};
                    if(affichage_complet==1)
                    {
                        std::cout<<"| "<<3*a+i<<','<<mega_tab[3*a+i][3*b+j]<<" ";
                    }
                    else {std::cout<<"| "<<mega_tab[3*a+i][3*b+j]<<" ";}
                    
                }
                std::cout<<"|  ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
    }    
}

void screen_mega(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab)
{
    terminal_ctrl::clear_screen();

    std::cout<<"case restante:"<<std::endl;
    draw_mega_morpion(mega_croquis,1);
    std::cout<<std::endl;

    draw_mega_morpion(mega_tab,0);
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

void play_2x2(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab)
{
    
}