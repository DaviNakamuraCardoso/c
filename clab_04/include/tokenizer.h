#ifndef __TOKENIZERH
#define __TOKENIZERH


typedef long double ld_t;

enum type {
    COMMAND,
    NUMBER,
    SYMBOL

}; 

enum operation {
    ADD, 
    SUB, 
    DIV, 
    MULT
};

typedef struct token {
    enum type t;
    union {
        ld_t value;
        enum operation op;

    };

} token_t;

unsigned int tokenize(FILE* f, token_t** tokens);
#endif
