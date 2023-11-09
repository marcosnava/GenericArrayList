//
// Created by nava on 24/10/23.
//

#include <stdlib.h>

#include "GenArrayList.h"

// variables
void **galLvList = NULL;
size_t galLvSize = 0;
size_t galLvIncrement = 0;
size_t galLvElements = 0;

/*
 * galInitialize the list with initial size
 * and define the increment when it expands
 */
ERROR galInitialize(size_t size, size_t inc)
{
    if(size < 1)
    {
        return EE_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else
    {
        galLvSize = size;
        galLvIncrement = inc;
        galLvElements = 0;
        galLvList = malloc(galLvSize * sizeof(void *));
        if(galLvList == NULL)
        {
            return EE_MEMORY_ALLOCATION_ERROR;
        }
        galLvInitializeElements(galLvList, galLvSize);
        return EE_NO_ERROR;
    }
}

/*
 * Utility function to initialize all elements
 * with NULL
 */
void galLvInitializeElements(void **list, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        list[i] = NULL;
    }
}

/*
 * Utility function to destroy the ArrayList
 */
void galDestroy()
{
    for(size_t i = 0; i < galLvSize; i++)
    {
        if(galLvList[i] != NULL)
        {
            galLvList[i] = NULL;
        }
    }

    free(galLvList);
    galLvList = NULL;
    galLvSize = 0;
    galLvElements = 0;
    galLvIncrement = 0;
}

/*
 * Appends the specified element to the end
 * of this list.
 */
ERROR galAdd(void *e)
{
    ERROR error = EE_NO_ERROR;
    if(galLvElements == galLvSize)
    {
        error = galLvExpand();
    }
    galLvList[galLvElements] = e;
    galLvElements++;

    return error;
}

/*
 * Utility function to expand the ArrayList
 * by the increment
 */
ERROR galLvExpand()
{
    void **temp = NULL;

    temp = malloc((galLvSize + galLvIncrement) * sizeof(void *));
    if(temp == NULL)
    {
        return EE_MEMORY_ALLOCATION_ERROR;
    }
    galLvInitializeElements(temp, (galLvSize + galLvIncrement));

    for(size_t i = 0; i < galLvSize; i++)
    {
        temp[i] = galLvList[i];
    }

    free(galLvList);
    galLvList = temp;
    galLvSize += galLvIncrement;

    return EE_NO_ERROR;
}

/*
 * Inserts the specified element at the
 * specified position in this list.
 */
ERROR galInsert(int index, void *e)
{
    ERROR error = EE_NO_ERROR;
    if(galLvElements == galLvSize)
    {
        error = galLvExpand();
    }
    if(index < 0 || index > galLvElements-1)
    {
        return EE_INDEX_OUT_OF_BOUNDS_EXCEPTION;
    }
    for(size_t i = galLvElements; i > index; i--)
    {
        galLvList[i] = galLvList[i - 1];
    }
    galLvList[index] = e;
    galLvElements++;

    return error;
}

/*
 * Removes all of the elements from this list.
 */
void galClear()
{
    for(size_t i = 0; i < galLvSize; i++)
    {
        if(galLvList[i] != NULL)
        {
            galLvList[i] = NULL;
        }
    }

    galLvElements = 0;
}

/*
 * Returns true if this list contains the
 * specified element.
 */
BOOLEAN galContains(void *e)
{
    BOOLEAN contains = FALSE;

    for(size_t i = 0; i < galLvElements; i++)
    {
        if(galLvList[i] == e)
        {
            return TRUE;
        }
    }

    return contains;
}

/*
 * Increases the capacity of this ArrayList
 * instance, if necessary, to ensure that it
 * can hold at least the number of elements
 * specified by the minimum capacity argument.
 */
ERROR galEnsureCapacity(int minCapacity)
{
    ERROR error = EE_NO_ERROR;
    if(galLvSize < minCapacity)
    {
        size_t aux = galLvIncrement;

        galLvIncrement = minCapacity - galLvSize;
        error = galLvExpand();
        galLvIncrement = aux;
    }

    return error;
}

/*
 * Returns the element at the specified
 * position in this list.
 */
void * galGet(int index, ERROR *error)
{
    *error = EE_NO_ERROR;

    if(index > galLvElements-1 || index < 0)
    {
        *error = EE_INDEX_OUT_OF_BOUNDS_EXCEPTION;
        return NULL;
    }
    return galLvList[index];
}

/*
 * Returns the index of the first occurrence
 * of the specified element in this list, or
 * -1 if this list does not contain the element.
 */
int galIndexOf(void *e)
{
    for(int i = 0; i < galLvElements; i++)
    {
        if(galLvList[i] == e)
        {
            return i;
        }
    }

    return -1;
}

/*
 * Returns true if this list contains no elements.
 */
BOOLEAN galIsEmpty()
{
    if(galLvElements == 0)
    {
        return TRUE;
    }
    return FALSE;
}

/*
 * Returns the index of the last occurrence of
 * the specified element in this list, or -1 if
 * this list does not contain the element.
 */
int galLastIndexOf(void *e)
{
    int i = galLvElements - 1;
    for(; i >= 0; i--)
    {
        if(galLvList[i] == e) {
            break;
        }
    }

    return i;
}

/*
 * Removes the element at the specified
 * position in this list.
 */
void galRemoveI(int index)
{
    if(index > galLvElements-1 || index < 0)
    {
        return;
    }
    for(int i = index; i < galLvElements - 1; i++)
    {
        galLvList[i] = galLvList[i + 1];
    }
    galLvElements--;
    galLvList[galLvElements] = NULL;
}

/*
 * Removes the first occurrence of the
 * specified element from this list, if
 * it is present.
 */
void galRemoveE(void *e)
{
    int index = galIndexOf(e);
    if(index == -1)
    {
        return;
    }
    galRemoveI(index);
}

/*
 * Replaces the element at the specified
 * position in this list with the specified
 * element.
 */
ERROR galSet(int index, void *e)
{
    if(index < 0 || index >= galLvElements)
    {
        return EE_INDEX_OUT_OF_BOUNDS_EXCEPTION;
    }
    galLvList[index] = e;

    return EE_NO_ERROR;
}

/*
 * Returns the number of elements in this list.
 */
size_t galSize()
{
    return galLvElements;
}

/*
 * Sorts this list according to the order
 * induced by the specified function.
 */
void galSort(BOOLEAN (*sort)(void *, void*))
{
    if(galLvElements > 1)
    {
        void *aux = NULL;
        for(int i = 0; i < (galLvElements - 1); i++)
        {
            for(int j = i + 1; j < galLvElements; j++)
            {
                if(sort(galLvList[i], galLvList[j]))
                {
                    aux = galLvList[i];
                    galLvList[i] = galLvList[j];
                    galLvList[j] = aux;
                }
            }
        }
    }
}

/*
 * Trims the capacity of this ArrayList
 * instance to be the list's current size.
 */
void galTrimToSize()
{
    void **temp = NULL;

    temp = malloc((galLvElements) * sizeof(void *));
    if(temp == NULL)
    {
        return;
    }
    galLvInitializeElements(temp, (galLvElements));

    for(size_t i = 0; i < galLvElements; i++)
    {
        temp[i] = galLvList[i];
    }

    free(galLvList);
    galLvList = temp;
    galLvSize = galLvElements;
}
