#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <sys\stat.h>

#include "list.h"

int list_ctor(list_struct *my_list, int capacity)
{
    assert (my_list);

    my_list->capacity = capacity;

    my_list->list = (list_elem *) calloc (my_list->capacity, sizeof(list_elem));

    if (!my_list->list)
        return ALLOCATION_MEMORY_ERROR;

    my_list->list[0].elem= 0;
    my_list->list[0].index_prev= 0;
    my_list->list[0].index_next= 0;

    my_list->free = 1;

    return SUCCESS_CTOR;
}

int list_dtor(list_struct *my_list)
{
    assert(my_list);

    free(my_list->list);

    return SUCCESS_DTOR;
}

int insert_elem (list_struct *my_list, int index, int elem)
{
    assert(my_list);

    my_list->list[my_list->free].elem = elem;
    my_list->list[my_list->free].index_next = my_list->list[index].index_next;
    my_list->list[my_list->free].index_prev = index;

    if (index > 0)
        my_list->list[index].index_next = my_list->free;


    my_list->free++;

    return 0;

}
