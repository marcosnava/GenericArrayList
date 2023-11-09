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
    EE_MEMORY_ALLOCATION_ERROR
};

typedef int ERROR;

// variables
extern void **galLvList;
extern size_t galLvSize;
extern size_t galLvIncrement;
extern size_t galLvElements;

// prototypes
/*
 * galInitialize the list with initial size
 * and define the increment when it expands
 */
ERROR galInitialize(size_t size, size_t inc);

/*
 * Utility function to initialize all elements
 * with NULL
 */
void galLvInitializeElements(void **list, size_t size);

/*
 * Utility function to destroy the ArrayList
 */
void galDestroy();

/*
 * Utility function to expand the ArrayList
 * by the increment
 */
ERROR galLvExpand();

/*
 * Appends the specified element to the end
 * of this list.
 */
ERROR galAdd(void *e);

/*
 * Inserts the specified element at the
 * specified position in this list.
 */
ERROR galInsert(int index, void *e);

/*
 * Removes all elements from this list.
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
ERROR galEnsureCapacity(int minCapacity);

/*
 * Returns the element at the specified
 * position in this list.
 */
void *galGet(int index, ERROR *error);

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
void galRemoveI(int index);

/*
 * Removes the first occurrence of the
 * specified element from this list, if
 * it is present.
 */
void galRemoveE(void *e);

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
 * Find element in list.
 */
void *galFind(BOOLEAN (*find)(void *, void*), void *what);

/*
 * Trims the capacity of this ArrayList
 * instance to be the list's current size.
 */
void galTrimToSize();

#endif //GENERICARRAYLIST_GENARRAYLIST_H
