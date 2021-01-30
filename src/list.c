// My Includes
#include "../inc/list.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
	// None for the moment.

/**
 * @brief insert an element at the beginning of the specified domino list
 * 
 * @param dominoToInsert 
 * @param dominolist 
 */
void insert_at_top(DominoList * dominoListToInsert, DominoList * const dominoList)
{
    DominoList * previous_element = dominoList->_previous_element;

    // Go at the root level 
    while(previous_element != NULL)
    {
        previous_element = previous_element->_previous_element;
    }

    // Insert the new domino list before the current first one
    previous_element->_previous_element     = dominoListToInsert;

    // Update the ptr of the new domino list to make it the new first one
    dominoListToInsert->_previous_element   = NULL;
    dominoListToInsert->_next_element       = previous_element;
}


/**
 * @brief insert an element at the end of the domino list
 * 
 * @param dominoToInsert 
 * @param dominolist 
 */
void insert_at_bottom(DominoList * const dominoListToInsert, DominoList * const dominoList)
{
    DominoList * next_element = dominoList->_next_element;

    // Go at the end of the list
    while(next_element != NULL)
    {
        next_element = next_element->_next_element;
    }

    // Insert the new domino list after the current last one
    next_element->_next_element             = dominoListToInsert;

    // Update the ptr of the new domino list to make it the new last one
    dominoListToInsert->_previous_element   = next_element;
    dominoListToInsert->_next_element       = NULL;
}


/**
 * @brief erase all domino lists, and free all the memory allocated for each domino (+ set to NULL the pointers)
 * 
 * @param dominolist 
 */
void erase_all(DominoList * dominoList)
{
    // First, we go at the root level
    DominoList * current_element = dominoList->_previous_element;

    // Go at the root level 
    while(current_element != NULL)
    {
        current_element = current_element->_previous_element;
    }

    // Then we go from the root to the end and we free everything
    while(current_element != NULL) {
        free(current_element->_domino);
        current_element->_domino = NULL;

        current_element = current_element->_next_element;
    }
}


/**
 * @brief print all elements in the list from the dominoList argument as root element
 * 
 * @param dominolist 
 */
void print_element(const DominoList * const dominoList)
{
    printf("The domino list contains :\n[ %u / %u ] -> ", dominoList->_domino->_face_a, dominoList->_domino->_face_b);

    DominoList * current_element = dominoList->_next_element;

    while(current_element != NULL)
    {
        printf("The domino list contains :\n[ %u / %u ] -> ", current_element->_domino->_face_a, current_element->_domino->_face_b);
        current_element = current_element->_next_element;
    }

    printf("END");
}