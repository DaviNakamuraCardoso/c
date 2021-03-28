# Building Bridges
## Data structures and Dynamic memory

### Exercises
#### Sharpen your pencil
- Before:  
Amity -> Craggy -> Isla Nublar -> Shutter
                Skull

- After:
Amity -> Craggy -> Skull -> Isla Nublar -> Shutter

### The big questions:
1. How many pieces of data were left in the heap?
1
2. What was the piece of data left in the heap?
A question (char*)
3. Which line (or lines) of code caused the leak?
```c
current->question = strdup(question);
```
*The pointer is set to a new location without releasing the old one*
4. How do you plug the leak?
```c
free(current->question);
current->question = strdup(question); 

```
