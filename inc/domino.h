#ifndef DOMINO_H
#define DOMINO_H

// My Includes
    // None for the moment.

// Includes
    // None for the moment.

// My Defines
	// None for the moment.

typedef struct Domino
{
    unsigned int    _face_a;
    unsigned int    _face_b;
} Domino;

// Functions
Domino * get_domino(void);

#endif // DOMINO_H