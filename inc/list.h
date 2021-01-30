#ifndef LIST_H
#define LIST_H

// My Includes
#include "domino.h"

// Includes
    // None for the moment.

// My Defines
	// None for the moment.

typedef struct DominoList DominoList;

typedef struct DominoList
{
    Domino *        _domino;
    DominoList *    _previous_element;
    DominoList *    _next_element;
} DominoList;

// Functions
void insert_at_top      (DominoList * dominoListToInsert, DominoList * const dominoList);
void insert_at_bottom   (DominoList * const dominoListToInsert, DominoList * const dominoList);
void erase_all          (DominoList * dominoList);
void print_element      (const DominoList * const dominoList);

#endif // LIST_H