typedef struct _trie
{
    unsigned int passes;
    struct _trie* next[200];
} TRIE;

// Init the trie struct
TRIE* create_trie(void);

// Add phrases
void add_phrase(TRIE* root, char* start);
