#ifndef PLAYER_H
#define PLAYER_H

// My Includes
#include "list.h"

// Includes
    // None for the moment.

// My Defines
	// None for the moment.

typedef struct Player
{
    char *          _name;
    Domino **       _dominos;
    unsigned int    _nb_of_wins;
    unsigned int    _nb_of_defeats;
    
} Player;

// Functions
void init               (Player * player, char * name, const unsigned int nbOfDominos);
void print_player_hand  (const Player * const player);
void play               (Player * player);

#endif // PLAYER_H