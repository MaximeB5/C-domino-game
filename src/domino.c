// My Includes
#include "../inc/domino.h"

// Includes
#include <stdlib.h>

// My Defines
#define MAX_RANGE 9

Domino * get_domino(void)
{
    Domino * domino = (Domino *) malloc( sizeof(Domino) );

    // MAX_RANGE + 1 -> rand() will return an int between 0 and MAX_RANGE
    domino->_face_a = (unsigned int) (rand() % (MAX_RANGE + 1));
    domino->_face_b = (unsigned int) (rand() % (MAX_RANGE + 1));

    return domino;
}