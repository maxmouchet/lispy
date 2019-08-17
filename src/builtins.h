#ifndef LISPY_BUILTINS
#define LISPY_BUILTINS

#include "lispy.h"

lval *builtin(lval *a, char *func);

lval *builtin_op(lval *a, char *op);

lval *builtin_head(lval *a);

lval *builtin_tail(lval *a);

lval *builtin_list(lval *a);

lval *builtin_eval(lval *a);

lval *builtin_join(lval *a);

lval *lval_join(lval *x, lval *y);

#endif
