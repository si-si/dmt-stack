#ifndef _DMT_STACK_H
#define _DMT_STACK_H

#define T Stack_T
typedef struct T *T;

extern T Stack_new(void);

extern int Stack_empty(T stk);
extern int Stack_push(T stk, void *x);
extern void *Stack_pop(T stk);
extern void Stack_free(T *stk);

#undef T
#endif
