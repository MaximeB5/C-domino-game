// My Includes
#include "../inc/player.h"

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>		// errno
#include <limits.h>  	// INT_MAX
#include <stdlib.h>  	// strtol

// My Defines
#define BASE_CONVERSION_INT 10

int main(int argc, char *argv[])
{
	printf("Hello from C-Domino.\n");

	// Check number of program arguments (2 because 1st one is the program name)
	if( argc != 2 )
	{
		printf("\tError : invalid number of program arguments. One of type int/unsigned int awaited defining the number of dominos for each player at start.\n");
		return -1;
	}

	// Check the argument is valid
	errno					= 0;
	char * 	end_ptr 		= NULL;
	long 	prgm_input_1	= strtol(argv[1], &end_ptr, BASE_CONVERSION_INT);

	if( errno != 0 || *end_ptr != '\0' || prgm_input_1 > INT_MAX )
	{
		printf("\tError : correct number of program argument but invalid type. It must be an int/unsigned int in order to define the number of dominos for each player at start.\n");
		return -1;
	}

	// Data we need to start the game
	const unsigned int NB_OF_DOMINO_AT_START = prgm_input_1;

	// Players init
	Player player1;
	Player player2;

	char * player2_name = "Player 2";	// just checking if it's ok to pass it with a char * for player 2 and with hard coded data for player 1

	init(&player1, "Player 1",   NB_OF_DOMINO_AT_START);
	init(&player2, player2_name, NB_OF_DOMINO_AT_START);

	// Some stuff TODO
		// ...

	// Test
	printf("Print Player Hand of Player 1.\n");
	print_player_hand(&player1);

	printf("Print Player Hand of Player 2.\n");
	print_player_hand(&player2);

	// Free
	free_the_resources(&player1, NB_OF_DOMINO_AT_START);
	free_the_resources(&player2, NB_OF_DOMINO_AT_START);

	return(0);
}
