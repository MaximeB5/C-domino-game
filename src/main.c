// My Includes
#include "../inc/player.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
#define NB_OF_DOMINO_AT_START 10

int main()
{
	printf("Hello from C-Domino.\n");

	Player player1;
	Player player2;

	char * player2_name = "Player 2";

	init(&player1, "Player 1",   NB_OF_DOMINO_AT_START);
	init(&player2, player2_name, NB_OF_DOMINO_AT_START);

	// Test
	printf("Print Player Hand of Player 1.\n");
	print_player_hand(&player1);

	return(0);
}
