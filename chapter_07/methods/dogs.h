enum sizes {SMALL, MEDIUM, BIG};

typedef struct _dog
{
    char* name;
    double weight;
    void (*bark) (struct _dog*);
    void (*free) (struct _dog*);

} DOG;

DOG* init(char* name, float weight);
void _free(DOG* d); 

// Bark functions
void _bark(DOG* d);
char* bark_type(DOG* d);
enum sizes _size(DOG* d);
char* sound(enum sizes s);
char* small_bark(void);
char* medium_bark(void);
char* big_bark(void);
