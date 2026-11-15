#include "tic-tac-toe.h"


                                          
/*  Une case vide montre son numéro, une case jouée montre w ou A.    */

void afficher_plateau(char plateau[9])
{
    int ret;

    ret = system("clear");   /* efface le terminal */
    (void)ret;              /* évite un warning "résultat inutilisé" */

    printf("\n");
    printf("   %c | %c | %c\n", plateau[0], plateau[1], plateau[2]);
    printf("  -----------\n");
    printf("   %c | %c | %c\n", plateau[3], plateau[4], plateau[5]);
    printf("  -----------\n");
    printf("   %c | %c | %c\n", plateau[6], plateau[7], plateau[8]);
    printf("\n");
}
                                    
/*  On redemande tant que la saisie est invalide : le joueur ne peut 
 donc pas tricher (case inexistante ou déjà prise).                */

void tour_joueur(char plateau[9])
{
    char ligne[100];
    int position;

    while (1)
    {
        printf("Dans quelle case voulez-vous jouer ? (0-8) : ");
        if (fgets(ligne, sizeof(ligne), stdin) == NULL)
            exit(1);                      

        /* Valide seulement si : un seul caractère entre '0' et '8' */
        if (ligne[0] < '0' || ligne[0] > '8' || ligne[1] != '\n')
        {
            printf("Entrée invalide : tapez un chiffre entre 0 et 8.\n");
            continue;
        }

        position = ligne[0] - '0';          /* '5' devient le nombre 5 */

        /* Une case déjà jouée contient X ou O */
        if (plateau[position] == JOUEUR || plateau[position] == ORDINATEUR)
        {
            printf("Cette case est déjà prise !\n");
            continue;
        }

        plateau[position] = JOUEUR;
        return;
    }
}

                                         
/*  Il joue simplement dans la première case libre.                   */

void tour_ordinateur(char plateau[9])
{
    int i;

    i = 0;
    while (plateau[i] == JOUEUR || plateau[i] == ORDINATEUR)
        i++;
    plateau[i] = ORDINATEUR;
}


/*  On vérifie les 3 lignes, les 3 colonnes puis les 2 diagonales.    */

int a_gagne(char plateau[9], char symbole)
{
    int i;

    /* Lignes : (0,1,2) (3,4,5) (6,7,8) */
    for (i = 0; i < 9; i += 3)
    {
        if (plateau[i] == symbole && plateau[i + 1] == symbole
            && plateau[i + 2] == symbole)
            return 1;
    }
    /* Colonnes : (0,3,6) (1,4,7) (2,5,8) */
    for (i = 0; i < 3; i++)
    {
        if (plateau[i] == symbole && plateau[i + 3] == symbole
            && plateau[i + 6] == symbole)
            return 1;
    }
    /* Diagonales : (0,4,8) et (2,4,6) */
    if (plateau[0] == symbole && plateau[4] == symbole && plateau[8] == symbole)
        return 1;
    if (plateau[2] == symbole && plateau[4] == symbole && plateau[6] == symbole)
        return 1;
    return 0;
}
