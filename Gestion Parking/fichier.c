#include "Parking.h"

void enregistrer_parking(t_personne** Parking)
{
    int i;
    FILE* fichier;
    fichier = fopen("parking.txt", "w");


    if (fichier != NULL)
    {
        for (i=0; i<PLACE_PARKING; i++)
        {
            if (Parking[i] != NULL)
            {
                if (i>0)
                {
                    fprintf(fichier, "\n");
                }
                //fprintf(fichier, "%s %d %d/%d/%d %f", Parking[i]->immatriculation, Parking[i]->numero, Parking[i]->date.jour, Parking[i]->date.mois, Parking[i]->date.annee, Parking[i]->prix_location);
                fprintf(fichier, "%s ", Parking[i]->immatriculation);

                if (Parking[i]->numero >=100)
                {
                    fprintf(fichier, "%d ", Parking[i]->numero);
                }
                else if (Parking[i]->numero < 10)
                {
                    fprintf(fichier, "00%d ", Parking[i]->numero);
                }
                else
                {
                    fprintf(fichier, "0%d ", Parking[i]->numero);
                }


                if (Parking[i]->date.jour >= 10)
                {
                    fprintf(fichier, "%d/", Parking[i]->date.jour);
                }
                else
                {
                    fprintf(fichier, "0%d/", Parking[i]->date.jour);
                }

                if (Parking[i]->date.mois >= 10)
                {
                    fprintf(fichier, "%d/", Parking[i]->date.mois);
                }
                else
                {
                    fprintf(fichier, "0%d/", Parking[i]->date.mois);
                }

                fprintf(fichier, "%d %3f", Parking[i]->date.annee, Parking[i]->prix_location);



            }
        }
    }
    fclose(fichier);
}


void ouverture_parking(t_personne **Parking)
{
    int i, fin;
    int numero;
    char buffer;

    FILE* fichier;
    fichier = fopen("parking.txt", "r");

    if (fichier != NULL)
    {
        fin = 0;
        for (i=0; i<PLACE_PARKING && fin!=1; i++)
        {
            if (feof(fichier))
            {
                fin = 1;
            }
            else
            {
                t_personne* Client = (t_personne*) malloc(sizeof(t_personne));

                fscanf(fichier, "%s %d %d/%d/%d %f", Client->immatriculation, &Client->numero, &Client->date.jour, &Client->date.mois, &Client->date.annee, &Client->prix_location);
                Client->date.nombre = (Client->date.jour) + (Client->date.mois*100) + (Client->date.annee*10000);
                Parking[i] = Client;
            }
        }
    }
    fclose(fichier);

}
