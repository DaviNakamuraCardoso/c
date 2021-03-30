typedef struct _trie
{
    struct _trie* letters[26];
    unsigned int exists:1;
} TRIE;

TRIE* dnccreatet(void);
