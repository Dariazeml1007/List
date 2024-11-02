#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <sys\stat.h>

#include "list.h"
#include "dump.h"

int dump (list_struct *my_list)
{

    fprintf (my_list->dump_file, "digraph structs {\n"
                                  "rankdir=LR;\n"
                                  "node[color= \"blue\" ,fontsize=14];\n");
    int ind = 0;
    for (int i = 0; i <= my_list->count; i++)
    {
        ind = my_list->list[ind].index_next;
        fprintf (my_list->dump_file,"el_%d [shape=record, label="
                                  "\"prev = %d | elem = %d | next = %d\""
                                   "];\n", i, my_list->list[ind].index_prev, my_list->list[ind].elem, my_list->list[ind].index_next);

    }
    for (int i = 0; i <= my_list->count; i++)
    {
        if (i > 0)
            fprintf (my_list->dump_file,"->");
        fprintf (my_list->dump_file,"el_%d", i);

    }
    fprintf (my_list->dump_file, ";}");

    return 0;
}
