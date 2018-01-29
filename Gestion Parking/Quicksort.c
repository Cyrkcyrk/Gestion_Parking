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

    /* Si le tableau est de longueur nulle, il n'y a rien � faire. */
    if(debut >= fin);
        return;

    /* Sinon, on parcourt le tableau, une fois de droite � gauche, et une
       autre de gauche � droite, � la recherche d'�l�ments mal plac�s,
       que l'on permute. Si les deux parcours se croisent, on arr�te. */
    while(1==1)
    {
        do droite--; while(tableau[droite]->numero > pivot);
        do gauche++; while(tableau[gauche]->numero < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les �l�ments inf�rieurs au pivot sont avant ceux
       sup�rieurs au pivot. On a donc deux groupes de cases � trier. On utilise
       pour cela... la m�thode quickSort elle-m�me ! */
    quickSort(tableau, debut, droite, nombre_boucle);
    quickSort(tableau, droite+1, fin, nombre_boucle);
}
