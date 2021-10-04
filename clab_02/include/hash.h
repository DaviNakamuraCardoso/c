#ifndef __HASHH
#define __HASHH

#define HASHSIZE 10000


typedef struct _hnode {
    char* word;
    unsigned int index;
    struct _hnode* next; 

} hashnode_t;

typedef struct _hash {
    hashnode_t **table;
    unsigned int nodes;
} hash_t;

hash_t* new_hash(void);
unsigned int add_hash(hash_t* h, char* word);
int search_hash(hash_t* h, char* word);
int hash(char *word);

#endif 
