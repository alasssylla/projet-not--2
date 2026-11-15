#include "tic-tac-toe.h"

/* ================================================================== */
/*  programme de base                                               */
/*  9 cases = 9 tours maximum. Tour pair : joueur. Tour impair : PC.  */
/*  Si personne n'a gagné après 9 tours, c'est un match nul.          */
/* ================================================================== */
int main(void)
{
    char plateau[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int tour;

    for (tour = 0; tour < 9; tour++)
    {
        afficher_plateau(plateau);

        if (tour % 2 == 0)
        {
            tour_joueur(plateau);
            if (a_gagne(plateau, JOUEUR))
            {
                afficher_plateau(plateau);
                printf("Bravo, vous avez gagné !\n");
                return 0;
            }
        }
        else
        {
            printf("L'ordinateur joue...\n");
            sleep(1);
            tour_ordinateur(plateau);
            if (a_gagne(plateau, ORDINATEUR))
            {
                afficher_plateau(plateau);
                printf("L'ordinateur a gagné !\n");
                return 0;
            }
        }
    }

    afficher_plateau(plateau);
    printf("Match nul !\n");
    return 0;
}