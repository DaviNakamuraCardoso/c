#ifndef __STACKH
#define __STACKH 

#include "tokenizer.h"

typedef struct {
    unsigned int size, sp;
    ld_t* nums;

} stack_t;

stack_t* stack(unsigned int size);
ld_t pop(stack_t* s);
ld_t look(stack_t* s);
ld_t push(stack_t* s, ld_t v);

#endif
