#include "Parking.h"

void echanger(t_personne **tableau, int a, int b)
{
    t_personne* temp;
    temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(t_personne** tableau, int debut, int fin, int* nombre_boucle)
{
    ///https://openclassrooms.com/courses/le-tri-rapide-qsort


    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = PLACE_PARKING/(*nombre_boucle);
    *nombre_boucle = (*nombre_boucle)*2;

    printf("%d %d\n", *nombre_boucle, pivot);

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin);
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1==1)
    {
        do droite--; while(tableau[droite]->numero > pivot);
        do gauche++; while(tableau[gauche]->numero < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite, nombre_boucle);
    quickSort(tableau, droite+1, fin, nombre_boucle);
}
