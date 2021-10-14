#ifndef __TOKENIZERH
#define __TOKENIZERH


typedef long double ld_t;

enum type {
    COMMAND,
    NUMBER,
    SYMBOL

}; 

typedef struct token {
    enum type t;
    union {
        ld_t value;
        ld_t (*operation) (ld_t);

    };

} token_t;

unsigned int tokenize(FILE* f, token_t** tokens);
#endif
