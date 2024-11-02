#ifndef LIST
#define LIST

typedef enum
{
    LIST_SUCCESS = 0,
    LIST_ALLOCATION_MEMORY_ERROR = 1,
    LIST_FILE_NOT_OPENED = 2,
    LIST_FILE_NOT_CLOSED = 3,
    LIST_NO_FREE_ELEM = 4

}List_errors;

struct list_elem
{
    int index_prev = 0;
    int elem = 0;
    int index_next;
};
struct list_struct
{
    int count = 0;
    FILE *dump_file = NULL;
    list_elem *list;
    int free = 0;
    int size_list = 0;
    int capacity = 0;
};

int insert_elem (list_struct *my_list, int index, int elem);
int list_ctor(list_struct *my_list, int capacity, const char * name_of_dump_file);
int list_dtor(list_struct *my_list);
int delete_elem (list_struct *my_list, int index);

#endif
