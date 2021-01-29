// My Includes
#include "../inc/player.h"

// Includes
#include <stdlib.h>
#include <stdio.h>

// My Defines
	// None for the moment.

/**
 * @brief initialize un player.
 * It assigns to the player its name, reset both the number of wins and defeats to 0,
 * and create a defined number of dominos whose the values are randomly chosen.
 * 
 * @param player 
 * @param name 
 * @param nbOfDominos 
 */
void init(Player * player, char * name, const unsigned int nbOfDominos)
{
    // Name
    player->_name = name;

    // Stats
    player->_nb_of_wins = 0;
    player->_nb_of_defeats = 0;

    // Player hand
    player->_dominos = (Domino**) malloc( nbOfDominos * sizeof(Domino) );

    unsigned int i = 0;
    for(i = 0; i < nbOfDominos; ++i) {
        player->_dominos[i] = get_domino();
    }
}


/**
 * @brief print on stdin the player hand (dominos)
 * 
 * @param player 
 */
void print_player_hand(const Player * const player)
{
    if( player->_dominos[0] == NULL ) {
        printf("The player hand of '%c' is empty.\n", player->_name);
        return;
    }

    printf("The player hand of '%c' contains :\n", player->_name);
    unsigned int i = 0;

    while (player->_dominos[i] != NULL)
    {
        printf("Domino [ %u / %u ]\n", player->_dominos[i]->_face_a, player->_dominos[i]->_face_b);
        ++i;
    }

    printf("\n\t Player '%c' has %u Dominos.\n", player->_name, (i+1));
}