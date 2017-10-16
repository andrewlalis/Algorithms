/*
handyarraylist.h
Created By:
    Andrew Lalis (andrewlalisofficial@gmail.com)
    16 October 2017
This file is free to use, as long as the above comment remains in the file.
Please contact the author regarding bugs and/or feature requests.
*/

#ifdef ARRAYLIST_TYPE

#include "templates.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Array List:
    The array list is a type of list in which a continuous block of data
    is used as the array, and items are added and removed, and the list
    should remain intact, and one contiguous segment of memory.
*/

/*
ArrayList Constants:
*/
#ifndef ARRAYLIST_SIZE_DEFAULT
#define ARRAYLIST_SIZE_DEFAULT 64
#endif

/*
ARRAYLIST: the array list type for a specific arraylist.
*/
#define ARRAYLIST TEMPLATE(ARRAYLIST_TYPE,arraylist)

/*
Array List structure:
    Each array list contains an array of data, as well as a front, back,
    and size parameters.
*/
typedef struct {
    ARRAYLIST_TYPE* data;
    int size;//The size of the data array, not number of elements.
    int length;//The number of elements in the array.
} ARRAYLIST;

#endif
