#ifndef TIC_TAC_TOE_H
# define TIC_TAC_TOE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define JOUEUR     'X'
# define ORDINATEUR 'O'

void afficher_plateau(char plateau[9]);
void tour_joueur(char plateau[9]);
void tour_ordinateur(char plateau[9]);
int  a_gagne(char plateau[9], char symbole);

#endif