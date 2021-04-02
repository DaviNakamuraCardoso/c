typedef struct _site
{
    char* name;
    struct _site* from[40];
} SITE;


typedef struct _trie
{
    SITE* address;
    struct _trie* next[40];

} TRIE;

int ascii(char c);
void register_site(char* name, TRIE* root, SITE* site);
TRIE* create_trie(void);
unsigned short exists(char* site_name, TRIE* root);


SITE* create_site(char* name);
void add_site(SITE* from, SITE* new, TRIE* root);
