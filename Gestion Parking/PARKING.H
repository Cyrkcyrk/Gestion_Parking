#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define PLACE_PARKING 500

typedef struct Date t_date;
struct Date
{
    int jour;
    int mois;
    int annee;
    int nombre;
};

typedef struct Personne t_personne;
struct Personne
{
    char immatriculation[7];
    t_date date;
    int numero;
    float prix_location;
};

void echanger(t_personne **tableau, int a, int b);


#endif // PARKING_H_INCLUDED
