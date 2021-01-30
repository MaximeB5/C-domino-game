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
    DominoList *    _next_element;
} DominoList;

// Functions
void insert_element_at_top      (const Domino * const dominoToInsert, DominoList * const dominolist);
void insert_element_at_bottom   (const Domino * const dominoToInsert, DominoList * const dominolist);
void erase_element              (Domino * const dominoToErase, DominoList * const dominolist);
void erase_all                  (Domino * const dominoToErase, DominoList * const dominolist);
void find_element               (int * elements_found, const DominoList * const dominolist);
void print_element              (const DominoList * const dominolist);

#endif // LIST_H