typedef struct _ll
{
    char* name;
    int value;
    struct _ll* next;
} LINKED_LIST;

void addll(LINKED_LIST* new, LINKED_LIST** root, int (*cmp) (const void* a, const void* b)); 
