#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <sys\stat.h>

#include "list.h"

int main()
{
    list_struct my_list = {};
    if (list_ctor (&my_list, 10) == ALLOCATION_MEMORY_ERROR)
        assert (0 && "Memory allocation error");

    insert_elem(&my_list, 0, 10);
    insert_elem(&my_list, 1, 20);
    insert_elem(&my_list, 1, 15);
    insert_elem(&my_list, 2, 17);

    for(int i = 0; i < 10; i++)
    {
        printf ("%d ", my_list.list[i].elem);
    }
    printf ("\n");
    for (int i = 0; i < 9; i++)
    {
        printf ("%d ", my_list.list[i].index_next);
    }

    list_dtor (&my_list);
}
