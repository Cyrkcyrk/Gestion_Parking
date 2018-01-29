#include "Parking.h"

int main()
{
    srand(time(NULL));
    int i;

    t_personne** Parking = (t_personne**) malloc(PLACE_PARKING*sizeof(t_personne*));

    for (i=0; i<PLACE_PARKING; i++)
    {
        Parking[i] = NULL;
    }

    ouverture_parking(Parking);

    for (i=0; i<PLACE_PARKING; i++)
    {
        add_voiture_rand(Parking, i);
    }

    //int boucle_quicksort = 1;
    //quickSort(Parking, 0, PLACE_PARKING-1, &boucle_quicksort);

    triBulle_numero(Parking);

    system("cls");

    int fin = 0;
    while (fin != 1)
    {
        switch(menu_principal())
        {
        case 1:
            {
                Afficher_stat(Parking);
                break;
            }
        case 2:
            {
                chercher_voiture(Parking); // Pas au point
            }
        case 3:
            {
                add_voiture_rand(Parking);
                break;
            }
        case 4:
            {
                supprimer_voiture(Parking);
                break;
            }
        case 5:
            {
                fin = 1;
                break;
            }
        }
    }



    enregistrer_parking(Parking);

    for(i=0; i<PLACE_PARKING; i++)
    {
        free(Parking[i]);
    }
    free(Parking);

    return 0;
}

void triBulle_date(t_personne **Parking)
{
    int i, fin = 0;
    t_personne* buffer;

    while (fin != 1)
    {
        fin = 1;
        for (i=0; i<PLACE_PARKING-1; i++)
        {
            if (Parking[i]->date.nombre > Parking[i+1]->date.nombre)
            {
                fin = 0;
                buffer = Parking[i];
                Parking[i] = Parking[i+1];
                Parking[i+1] = buffer;
            }
        }
    }
}

void triBulle_numero(t_personne **Parking)
{
    int i, fin = 0;
    t_personne* buffer;

    while (fin != 1)
    {
        fin = 1;
        for (i=0; i<PLACE_PARKING-1; i++)
        {
            if (Parking[i]->numero > Parking[i+1]->numero)
            {
                fin = 0;
                buffer = Parking[i];
                Parking[i] = Parking[i+1];
                Parking[i+1] = buffer;
            }
        }
    }
}

void chercher_voiture(t_personne ** Parking)
{
    char voiture[8];
    int i, fin;

    printf("Immatriculation de la voiture ou numero de place: ");
    scanf("%s", voiture);

    if ((voiture[3] >= 'A' || voiture[3] >= 'a' ) && (voiture[3] <= 'Z' || voiture[3] <=  'z'))
    {
        fin = 0;
        for (i=0; i>PLACE_PARKING; i++)
        {
            if (strcmp(Parking[i]->immatriculation, voiture) == 0)
            {
                fin = 1;
            }
        }
    }
    else
    {
        int numero;
        int compteur = 1;
        i = 0;
        do
        {
            i++;
        }while (Parking[i] != '\0');


        for (i=i-1; i>=0; i--)
        {
            numero = numero + voiture[i]*puissance_de_10(compteur);
        }

        fin = 0;
        for (i=0; i>PLACE_PARKING; i++)
        {
            if (Parking[i]->numero == numero)
            {
                fin = 1;
            }
        }
    }
    printf("%d: %s %d %d/%d/%d %f", i, Parking[i]->immatriculation, Parking[i]->numero, Parking[i]->date.jour, Parking[i]->date.mois, Parking[i]->date.annee, Parking[i]->prix_location);
    system("pause");
}

int puissance_de_10(int compteur)
{
    int i;
    int puissance = 1;
    for (i=0; i<compteur; i++)
    {
        puissance = puissance * 10;
    }
    return puissance;
}

void supprimer_voiture(t_personne ** Parking)
{

}

void add_voiture_rand(t_personne ** Parking)
{
    int numero_voiture;
    int i, fin=0;
    for (i=0; i<PLACE_PARKING && fin != 1; i++)
    {
        if (Parking[i] == NULL)
        {
            numero_voiture = i;
            fin = 1;
        }

    }

    if (fin == 0)
        printf("PARKING PLEIN! Impossible d'ajouter une nouvelle voiture!\n");

    else
    {
        t_personne* Client;
        Client = (t_personne*) malloc(sizeof(t_personne));


        printf("Immatriculation de la voiture: ");
        Client->immatriculation[0] = rand()%26+65;
        Client->immatriculation[1] = rand()%26+65;
        Client->immatriculation[2] = rand()%10+48;
        Client->immatriculation[3] = rand()%10+48;
        Client->immatriculation[4] = rand()%10+48;
        Client->immatriculation[5] = rand()%26+65;
        Client->immatriculation[6] = rand()%26+65;
        Client->immatriculation[7] = '\0';
        printf("%s\n", Client->immatriculation);

        printf("Numero de place: ");
        fin = 0;
        while(fin != 1 )
        {
            fin = 1;
            Client->numero = rand()%PLACE_PARKING+1;

            for (i=0; i<PLACE_PARKING && fin == 1; i++)
            {
                if (Parking[i] != NULL && Parking[i]->numero == Client->numero)
                {
                    printf("%d\n", Client->numero);
                    printf("Impossible: La place est deja prise...\n");
                    fin = 0;
                }
            }
        }



        printf("Date: ");
        Client->date.jour = (rand()%30)+1;
        Client->date.mois = (rand()%11)+1;
        Client->date.annee = rand()%50 + 2000;

        Client->date.nombre = (Client->date.jour) + (Client->date.mois*100) + (Client->date.annee*10000);


        printf("Prix: ");
        Client->prix_location = (rand()%503)+40;
        printf("%f\n", Client->prix_location);


        Parking[numero_voiture] = Client;
    }
}
