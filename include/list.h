#ifndef LIST
#define LIST

typedef enum
{
    ALLOCATION_MEMORY_ERROR = -1,
    SUCCESS_CTOR = 0,
    SUCCESS_DTOR = 0

}Status_and_errors;

struct list_elem
{
    int index_prev = 0;
    int elem = 0;
    int index_next;
};
struct list_struct
{

    list_elem *list;
    int free = 0;
    int size_list = 0;
    int capacity = 0;
};

int insert_elem (list_struct *my_list, int index, int elem);
int list_ctor(list_struct *my_list, int capacity);
int list_dtor(list_struct *my_list);

#endif
