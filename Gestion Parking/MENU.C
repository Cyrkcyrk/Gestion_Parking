#include "Parking.h"

void gotoligcol( int lig, int col )
{
     // ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


int menu_principal()
{
    system("cls");

    int choix_final;
    int nombre_lignes = 5;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "Gestion du parking.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Afficher les stats.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Chercher une voiture.");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Ajouter une voiture.");
    transfert_tableau(nombre_lignes, menu_prog, 4, "Supprimer une voiture.");
    transfert_tableau(nombre_lignes, menu_prog, 5, "Quitter.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}

void transfert_tableau(int nombre_de_lignes, char choix[nombre_de_lignes][50], int i, char choixvariable[])
{
    int j=0, k, remplir;
    while(choixvariable[j] != '.')
    {
        j++;
    }

    for(remplir=0; remplir < 50; remplir++)
        choix[i][remplir] = 0;

    for (k=0; k<j; k++)
    {
        choix[i][k] = choixvariable[k];
    }
    j=0;
}

void afficher_texte(char tab[][50], int selection_choix, int nombre_lignes)
{
    int i=0, j=0, k;

    for (k=0; k<nombre_lignes; k++)
    {
        while (tab[k][i] != '\0')
        {
            i++;
        }

        if (k == 0)
        {
            printf("     ----- ");
            printf("%s",tab[k]);
            printf(" -----   \n\n");
        }
        else
        {
            if(selection_choix == k)
                printf(" > %d - ",k);
            else
                printf("   %d - ",k);
            for (j=0; j<i; j++)
            {
                    printf("%c",tab[k][j]);
            }
        }
        i=0;
        printf("\n");
    }
}

/**
inspiré de https://www.youtube.com/watch?v=5npsbOCoN_c
https://stackoverflow.com/questions/10463201/getch-and-arrow-codes pour les fleches directionelles.
*/

int afficher_menu(char tab_menu[][50], int nombre_lignes, int coordx, int coordy)
{
    int numero_selection=1, fin=0;

    gotoligcol(coordx ,coordy);
    afficher_texte(tab_menu, numero_selection, nombre_lignes);
    //printf("\nVotre choix est: %d", numero_selection);

    char ch;
    while (!kbhit())
    {
        while (fin != 1)
        {
            ch=getch();

            if (ch == -32)
            {
                ch = getch();
                if (ch == 'H')
                {
                    //printf("HAUT\n");
                    numero_selection--;
                }
                if (ch == 'P')
                {
                    //printf("BAS\n");
                    numero_selection++;
                }

            }
            if (ch >=49 && ch <= 49+nombre_lignes)
            {
                numero_selection = ch-48;
            }

            if (ch == 13) ///ENTRER
            {
                fin = 1;
                break;
            }
            if(ch == 27) ///ECHAP
            {
                numero_selection = -1;
                fin=1;
                break;
            }
            if (numero_selection < 1)
                numero_selection=1;

            if (numero_selection > nombre_lignes-1)
                numero_selection = nombre_lignes-1;

            gotoligcol(coordx,coordy);
            afficher_texte(tab_menu, numero_selection, nombre_lignes);
        }
        break;
    }

    return numero_selection;
}

