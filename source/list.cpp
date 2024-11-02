#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <sys\stat.h>

#include "list.h"

int find_free (list_struct *my_list);

int list_ctor(list_struct *my_list, int capacity, const char * name_of_dump_file)
{
    assert (my_list);

    my_list->capacity = capacity;

    my_list->list = (list_elem *) calloc (my_list->capacity, sizeof(list_elem));

    if (!my_list->list)
    {
        printf ("Memory allocation\n");
        return LIST_ALLOCATION_MEMORY_ERROR;
    }
    my_list->dump_file = fopen (name_of_dump_file, "w");

    if (!my_list->dump_file)
    {
        printf ("Dump file wasn't open\n");
        return LIST_FILE_NOT_OPENED;
    }
    my_list->list[0].elem = 0;
    my_list->list[0].index_prev = 0;
    my_list->list[0].index_next = 0;

    my_list->free = 1;

    for (int i = 1; i < capacity; i++)
        my_list->list[i].elem = -1;

    return LIST_SUCCESS;
}

int list_dtor(list_struct *my_list)
{
    assert(my_list);

    free(my_list->list);
    if (fclose (my_list->dump_file) != 0)
        return LIST_FILE_NOT_CLOSED;
    return LIST_SUCCESS;
}

int insert_elem (list_struct *my_list, int index, int elem)
{
    assert(my_list);

    my_list->list[my_list->free].elem = elem;
    my_list->list[my_list->free].index_next = my_list->list[index].index_next;
    my_list->list[my_list->list[index].index_next].index_prev = my_list->free;
    my_list->list[my_list->free].index_prev = index;

    my_list->list[index].index_next = my_list->free;

    find_free(my_list);

    my_list->count ++;

    return 0;

}

int find_free (list_struct *my_list)
{
    for (int i = 1; i < my_list->capacity; i++)
        if (my_list->list[i].elem == -1)
        {
            my_list->free = i;
            return LIST_SUCCESS;
        }
    return LIST_NO_FREE_ELEM;
}

int delete_elem (list_struct *my_list, int index)
{
    assert(my_list);

    my_list->list[my_list->list[index].index_prev].index_next= my_list->list[index].index_next;
    my_list->list[my_list->list[index].index_next].index_prev = my_list->list[index].index_prev;
    my_list->free = index;
    my_list->list[index].elem = -1;

    my_list->count --;
    return 0;
}
