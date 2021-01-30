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
    player->_nb_of_dominos  = 0;
    player->_nb_of_wins     = 0;
    player->_nb_of_defeats  = 0;

    // Player hand
    player->_dominos = (Domino**) malloc( nbOfDominos * sizeof(Domino*) );

    unsigned int i = 0;
    for(i = 0; i < nbOfDominos; ++i)
    {
        player->_dominos[i] = get_domino();
        ++player->_nb_of_dominos;
    }
}


/**
 * @brief print on stdin the player hand (dominos)
 * 
 * @param player 
 */
void print_player_hand(const Player * const player)
{
    // Empty hand
    if( player->_dominos[0] == NULL ) {
        printf("The player hand of '%s' is empty.\n", player->_name);
        return;
    }

    // Else, it has demino
    printf("The player hand of '%s' contains :\n", player->_name);

    unsigned int i = 0;
    for(i = 0; i < player->_nb_of_dominos; ++i)
    {
        printf("Domino [ %u / %u ]\n", player->_dominos[i]->_face_a, player->_dominos[i]->_face_b);
    }

    printf("\n\t Player '%s' has %u Dominos.\n", player->_name, i);
}


/**
 * @brief play method for the game loop
 * TODO
 * 
 * @param player 
 */
void play(Player * player)
{
    // TODO
}


/**
 * @brief free all the memory required for the domino of the player and set the pointers to NULL.
 * Info : 2 "main" mallocs performed before :
 * 1 for each domino
 * 1 for the domino list
 * We have to free all of them and to secure the pointers.
 * 
 * @param player 
 */
void free_the_resources(Player * player, unsigned int playerHandSize)
{
    // Free each domino
    unsigned int i = 0;
    /*
    while( player->_dominos[i] != NULL )
    {
        free(player->_dominos[i]);
        player->_dominos[i] = NULL;
        ++i;
    }
    */
    for (i = 0; i < playerHandSize; ++i) {
        free(player->_dominos[i]);
        player->_dominos[i] = NULL;
    }

    // Free the domino *
    free(player->_dominos);
    player->_dominos = NULL;
}


/**
 * @brief increase the stats _nb_of_wins and _nb_of_defeats of the player
 * 
 * @param player 
 * @param win 
 * @param defeat 
 */
void update_score(Player * player, const unsigned int win, const unsigned int defeat)
{
    player->_nb_of_wins     += win;
    player->_nb_of_defeats  += defeat;
}