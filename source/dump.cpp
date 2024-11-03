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
                                  "node[color= \"#003A8C\",style=\"filled\", fillcolor=\"#7EEEF8\", fontsize=14];\n"
                                   "edge[color=\"black\", style=\"bold\", fontsize=14];\n");

    for (int i = 0; i < my_list->capacity; i++)
    {
        if (my_list->list[i].elem != -1)
            fprintf (my_list->dump_file,"el_%d [shape=record, label="
                                        "\"prev = %d | elem = %d | next = %d\""
                                        "];\n", i, my_list->list[i].index_prev, my_list->list[i].elem, my_list->list[i].index_next);

    }
    for (int i = 0; i < my_list->capacity; i++)
    {
        if (my_list->list[i].elem != -1)
        {
            if (i > 0)
               fprintf (my_list->dump_file,"->");
            fprintf (my_list->dump_file,"el_%d", i);
        }
    }

    fprintf (my_list->dump_file, ";\n");
    fprintf (my_list->dump_file, "edge[color=\"blue\",fontsize=12];\n");
    int ind = 0;
    for (int i = 0; i <= my_list->count + 1; i++)
    {

        if (i > 0 && my_list->list[ind].elem != -1)
            fprintf (my_list->dump_file,"->");
        fprintf (my_list->dump_file,"el_%d", ind);
        ind = my_list->list[ind].index_next;
    }
    fprintf (my_list->dump_file, ";}");

    return 0;
}
