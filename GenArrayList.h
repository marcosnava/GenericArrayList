//
// Created by nava on 21/10/23.
//

#ifndef GENERICARRAYLIST_GENARRAYLIST_H
#define GENERICARRAYLIST_GENARRAYLIST_H

#include <stdio.h>

#include "Boolean.h"
// constants
enum {
    EE_NO_ERROR = 0,
    EE_INDEX_OUT_OF_BOUNDS_EXCEPTION,
    EE_ILLEGAL_ARGUMENT_EXCEPTION,

};

typedef int ERROR;

// variables
extern void **galIvList;
extern size_t galIvSize;
extern size_t galIvIncrement;

// prototypes
/*
 * Initialize the list with initial size
 * and define the increment when it expands
 */
ERROR Initialize(size_t size, size_t inc);

/*
 * Appends the specified element to the end
 * of this list.
 */
BOOLEAN galAdd(void *e);

/*
 * Inserts the specified element at the
 * specified position in this list.
 */
ERROR galInsert(int index, void *e);

/*
 * Removes all of the elements from this list.
 */
void galClear();

/*
 * Returns true if this list contains the
 * specified element.
 */
BOOLEAN galContains(void *e);

/*
 * Increases the capacity of this ArrayList
 * instance, if necessary, to ensure that it
 * can hold at least the number of elements
 * specified by the minimum capacity argument.
 */
void galEnsureCapacity(int minCapacity);

/*
 * Returns the element at the specified
 * position in this list.
 */
ERROR galGet(int index, void *e);

/*
 * Returns the index of the first occurrence
 * of the specified element in this list, or
 * -1 if this list does not contain the element.
 */
int galIndexOf(void *e);

/*
 * Returns true if this list contains no elements.
 */
BOOLEAN galIsEmpty();

/*
 * Returns the index of the last occurrence of
 * the specified element in this list, or -1 if
 * this list does not contain the element.
 */
int galLastIndexOf(void *e);

/*
 * Removes the element at the specified
 * position in this list.
 */
BOOLEAN galRemoveI(int index);

/*
 * Removes the first occurrence of the
 * specified element from this list, if
 * it is present.
 */
BOOLEAN galRemoveE(void *);

/*
 * Replaces the element at the specified
 * position in this list with the specified
 * element.
 */
ERROR galSet(int index, void *e);

/*
 * Returns the number of elements in this list.
 */
size_t galSize();

/*
 * Sorts this list according to the order
 * induced by the specified function.
 */
void galSort(BOOLEAN (*sort)(void *, void*));

/*
 * Trims the capacity of this ArrayList
 * instance to be the list's current size.
 */
void galTrimToSize();

#endif //GENERICARRAYLIST_GENARRAYLIST_H
