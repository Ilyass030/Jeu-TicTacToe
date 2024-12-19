#include <iostream>
#include <string>
#include <array>
#include "fonction_mega.hpp"
#include "random.hpp"


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
                        if (mega_tab[3*a+i][3*b+j]!=' ')
                        {
                            std::cout<<"| "<<3*a+i<<','<<mega_tab[3*a+i][3*b+j]<<" ";
                        }
                        else {std::cout<<"|  "<<mega_tab[3*a+i][3*b+j]<<"  ";}
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

bool one_case(std::array <char,9>& validation,int last_position)
{
    if (validation[last_position%10]==' ')
    {return true;}
    else {return false;}
}

void screen_mega(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab,int last_position,std::array <char,9>& validation)
{
    terminal_ctrl::clear_screen();

    std::cout<<"case restante:"<<std::endl;
    
    std::array <std::array<char,9>,9> copy{};
    if (one_case(validation,last_position))
    {
        for (int i=0;i<9;i++)
        {
            copy[last_position%10][i]=mega_croquis[last_position%10][i];
        }
        draw_mega_morpion(copy,1);
        std::cout<<std::endl;
    }
    else 
    {
        draw_mega_morpion(mega_croquis,1);
        std::cout<<std::endl;
    }
    
    

    draw_mega_morpion(mega_tab,0);
    std::cout<<std::endl;
}

int rand(std::array <std::array <char,9>,9>& mega_croquis, int last_position,std::array <char,9>& verification)
{
    int rand_unite=random_int(0,8);
    int rand_dixaine=last_position/10;
    while (mega_croquis[rand_dixaine][rand_unite]==' ' && verification[rand_dixaine]!=' ')
    {
        rand_unite=random_int(0,8);
        if (verification[last_position/10]!=' ')
        {
            rand_unite=random_int(0,8)*10;
        }
    }
    return rand_unite+rand_dixaine;
}

bool do_win(std::array <char,9>& tab,int last_position)
{
    int y = last_position /3; //ligne
    int x = last_position %3; //col
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    for (int i=0;i<3;i++)
    {
        if (tab[3*i+x]==tab[3*y+x])//row
            {
                a++;
                if (a==3)
                {return true;}
            }
        if (tab[3*y+i]==tab[3*y+x])//lig
            {
                b++;
                if (b==3)
                {return true;}
            }
        if (tab[3*i+i]==tab[3*y+x])//diag descendant 
            {
                c++;
                if (c==3)
                {return true;}
            }
        if (tab[3*i+(2-i)]==tab[3*y+x])//diag montant /
            {
                d++;
                if (d==3)
                {return true;}
            }
    }

}

void fill(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab, int choice, char symbol)
{
    while (mega_croquis[choice/10][choice%10]==' ')
    {
        std::cout<<"cette case est deja prise, changez : ";
        std::cin>>choice;
    }
    mega_tab[choice/10][choice%10]=symbol;
    mega_croquis[choice/10][choice%10]=' ';
}

bool is_play_end(std::array <char,9>& validation)//bcp de copier coller, est ce que je peux faire autrement?
{
    for (char c:validation)
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

int play(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab, int choice, Player player)
{
    std::cout<<"tour de " <<player.name<<std::endl;
    std::cout<<"Veillez choisir une case restante: ";
    std::cin>>choice;//choisir sa case
    std::cout<<std::endl;
    fill(mega_croquis,mega_tab,choice,player.symbol);//remplir la grille avec le symbole
    return choice;//equivalent a last_position

}


void play_2x2(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab,Player player1,Player player2,std::array <char,9>& validation)
{
    int i=0;
    int last_position{};
    while (!is_play_end(validation) || i>82)
    {
        if (i%2==0)
        {
            last_position=play(mega_croquis,mega_tab,last_position,player1);
        }
        else
        {
            int last_position=play(mega_croquis,mega_tab,last_position,player2);
        }
        i++;
        screen_mega(mega_croquis,mega_tab,last_position,validation);
    }
    if (i==81)
    {
        std::cout<<"MATCH NULLLLLL, MERCI POUR VOTRE PARTICIPATION";
    }
}


void play_IA(std::array <std::array <char,9>,9>& mega_croquis,std::array <std::array <char,9>,9>& mega_tab,Player player,Player player_ia,std::array <char,9>& validation)
{
    int i=0;
    int last_position=0;
    while (!is_play_end(mega_croquis) || i>10)
    {
        if (i%2==0)
        {
            last_position=play(mega_croquis,mega_tab,last_position,player1);
            // if(do_win(tab, last_position))
            // {
            //     screen(croquis,tab);
            //     std::cout<<player.name<<" a gagné, felicitation !!!";
                
            //     break;
            // }
        }
        else
        {
            int position=rand(mega_croquis,last_position,validation);
            }
            std::cout<<"tour de " <<player_ia.name<<std::endl;
            std::cout<<std::endl;
            fill(mega_croquis,mega_tab,last_position,player.symbol);

            if(do_win(tab, position))
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