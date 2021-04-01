typedef struct _site
{
    char* name;
    struct _site* relateds[80];
} SITE;


typedef struct _trie
{
    unsigned int exists:1;
    struct _trie* letters[60];

} TRIE;
