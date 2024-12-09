#include <iostream>
#include <string>
#include <array>
#include "Player.hpp"
#include "terminal_ctrl.hpp"
#include "random.hpp"



Player create_player ()
{
    
    std::cout<<"veuillez écrire votre nom / pseudo :" ;
    std::string nom;
    std::cin>>nom;
    // Player player.name=nom;
    std::cout<<std::endl;
    std::cout<<"veuillez choisir votre symbol :" ;
    char symbole;
    std::cin>>symbole;
    // Player player;
    // player.symbol = symbole;
    // Player player.symbol=symbole; version fausse
    std::cout<<std::endl;
    return Player {nom,symbole};
    //  Player{nom,symbole};
}

void draw_game_board(std::array <char,9>& tab)
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

void screen(std::array <char,9>& croquis,std::array <char,9>& tab)
{
    terminal_ctrl::clear_screen();

    std::cout<<"case restante:"<<std::endl;
    draw_game_board(croquis);
    std::cout<<std::endl;

    draw_game_board(tab);
    std::cout<<std::endl;
}

bool do_win(std::array <char,9>& tab, int& last_position)//permet de verifier s'il y a une verification de WIN, donc à verifier apres chaque tour, elle renvoie un bool, donc si verif du bool on renvoie un texte...
{
    
    int y = last_position /3; //ligne
    int x = last_position %3; //cologne avec formule:  3*y+x=i
    std::array<char,3> verif_row{false,false,false};
    std::array<char,3> verif_lig{false,false,false};
    std::array<char,3> verif_diag_up{false,false,false};
    std::array<char,3> verif_diag_down{false,false,false};
    for (int i=0;i<3;i++)
    {
        if (tab[3*i+x]==tab[3*y+x])//row
            {
                verif_row[i]= true;
            }
        if (tab[3*y+i]==tab[3*y+x])//lig
            {
                verif_lig[i]= true;
            }
        if (tab[3*i+i]==tab[3*y+x])//diag descendant 
            {
                verif_diag_down[i]= true;
            }
        if (tab[3*i+(2-i)]==tab[3*y+x])//diag montant /
            {
                verif_diag_up[i]= true;
            }  
    }
    if (verif_row==std::array <char,3> {true,true,true} || verif_lig==std::array <char,3> {true,true,true} || 
    verif_diag_down==std::array <char,3> {true,true,true}  || verif_diag_up==std::array <char,3> {true,true,true})
    {
        return true;
    }
}

void fill(std::array <char,9>& croquis,std::array <char,9>& tab,char default_char, int last_choice, char symbol)//permet de remplir le tableau avec le symbole necessaire
{
    // if (tab[last_choice]==default_char)
    // {
    //     tab[last_choice]=symbol;
    //     croquis[last_choice]=' ';
    // }
    // else{std::cout<<"cette case est deja prise";}
    while (croquis[last_choice]==' ')
    {
        std::cout<<"cette case est deja prise, changez : ";
        std::cin>>last_choice;
    }
    tab[last_choice]=symbol;
    croquis[last_choice]=' ';
}

bool is_play_end(std::array <char,9>& croquis)//permet de verifier si le jeu est fini
{
    //bool verif{};
    for (char c:croquis)
    {
        //verif= true;
        if (c!=' ')
        {
            //verif = false;
            return false;
        }
    }
    return true;//plus aucune case de dispo
}

int play(std::array <char,9>& croquis,std::array <char,9>& tab,Player player)
{
    int last_position{};
    std::cout<<"tour de " <<player.name<<std::endl;
    std::cout<<"Veillez choisir une case restante: ";
    std::cin>>last_position;//choisir sa case
    std::cout<<std::endl;
    fill(croquis,tab,'.',last_position,player.symbol);//remplir la grille avec le symbole
    return last_position;

}

void play_2x2(std::array <char,9>& croquis,std::array <char,9>& tab,Player player1,Player player2)
{
    int i=0;
    // int last_position{};
    while (!is_play_end(croquis) || i>10)
    {
        if (i%2==0)
        {
            int last_position=play(croquis,tab,player1);
            // std::cout<<"tour de " <<player1.name<<std::endl;
            // std::cout<<"Veillez choisir une case restante: ";
            // std::cin>>last_position;//choisir sa case
            // std::cout<<std::endl;
            // fill(croquis,tab,'.',last_position,player1.symbol);//remplir la grille avec le symbole
            if(do_win(tab, last_position))
            {
                screen(croquis,tab);
                std::cout<<player1.name<<" a gagné, felicitation !!!";
                
                break;
            }
        }
        else
        {
            int last_position=play(croquis,tab,player1);
            // std::cout<<"tour de " <<player2.name<<std::endl;
            // std::cout<<"Veillez choisir une case restante: ";
            // std::cin>>last_position;
            // std::cout<<std::endl;
            // fill(croquis,tab,'.',last_position,player2.symbol);//remplir la grille avec le symbole
            if(do_win(tab, last_position))
            {
                screen(croquis,tab);
                std::cout<<player2.name<<" a gagné, felicitation !!!";
                
                break;
            }
        }
        i++;
        screen(croquis,tab);
        // if (do_win(tab,last_position))
        // {
        //     continue;
        // };
        
    }
    if (i==9)
    {
        std::cout<<"MATCH NULLLLLL, MERCI POUR VOTRE PARTICIPATION";
    }
}

void play_IA(std::array <char,9>& croquis,std::array <char,9>& tab,Player player,Player player_ia)
{
    int i=0;
    while (!is_play_end(croquis) || i>10)
    {
        if (i%2==0)
        {
            int last_position=play(croquis,tab,player);
            if(do_win(tab, last_position))
            {
                screen(croquis,tab);
                std::cout<<player.name<<" a gagné, felicitation !!!";
                
                break;
            }
        }
        else
        {
            int rand_position=random_int(0,8);
            while (croquis[rand_position]==' ')
            {
                rand_position=random_int(0,8);
            }
            std::cout<<"tour de " <<player_ia.name<<std::endl;
            std::cout<<std::endl;
            fill(croquis,tab,'.',rand_position,player_ia.symbol);
            if(do_win(tab, rand_position))
            {
                screen(croquis,tab);
                std::cout<<player_ia.name<<" a gagné, felicitation !!!";
                
                break;
            }
        }
        i++;
        screen(croquis,tab);
        
    }
    if (i==9)
    {
        std::cout<<"MATCH NULLLLLL, MERCI POUR VOTRE PARTICIPATION";
    }

}

//MEGA morpion 

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



