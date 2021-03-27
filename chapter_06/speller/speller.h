typedef struct _trie
{
    unsigned int exists:1;
    struct _trie* next[27];
} TRIE;


TRIE* create(void);
void add_word(char* word, TRIE* root);
void release(TRIE* root);
unsigned int exists(char* word, TRIE* root);
