#ifndef __HASHH
#define __HASHH

#define HASHSIZE 10000


typedef struct _hash {
   char* word;
   struct _hash* next; 
} Hash;

Hash** create_table(void);
void add_hash(Hash** table, char* word);
unsigned int search_hash(Hash** table, char* word);
int hash(char *word);

#endif 
