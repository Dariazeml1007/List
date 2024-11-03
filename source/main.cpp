#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <sys\stat.h>

#include "list.h"
#include "dump.h"

int main()
{
    list_struct my_list = {};

    if (list_ctor (&my_list, 10, "dump.dot") != LIST_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    insert_elem(&my_list, 0, 10);
    insert_elem(&my_list, 1, 40);
    insert_elem(&my_list, 1, 30);

    delete_elem(&my_list, 1);

    insert_elem(&my_list, 2, 50);
    insert_elem(&my_list, 1, 60);

    for (int i = 0; i < my_list.capacity; i++)
    {
        printf ("%d ", my_list.list[i].elem);
    }
    dump (&my_list);

    list_dtor (&my_list);
}
