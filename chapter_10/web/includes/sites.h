typedef struct _site
{
    char* name;
    struct _site* from[600];
    struct _site* next[600];
} SITE;


typedef struct _trie
{
    SITE* address;
    struct _trie* next[40];

} TRIE;

int ascii(char c);
void register_site(char* name, TRIE* root, SITE* site);
TRIE* create_trie(void);
SITE* get_site(char* site_name, TRIE* root);


void add_site(SITE* from, SITE* new, TRIE* root);
SITE* create_site(char* name);
