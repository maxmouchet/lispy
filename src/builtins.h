#ifndef LISPY_BUILTINS
#define LISPY_BUILTINS

#include "lispy.h"

lval *builtin_add(lenv *e, lval *a);

lval *builtin_sub(lenv *e, lval *a);

lval *builtin_mul(lenv *e, lval *a);

lval *builtin_div(lenv *e, lval *a);

lval *builtin_head(lenv *e, lval *a);

lval *builtin_tail(lenv *e, lval *a);

lval *builtin_list(lenv *e, lval *a);

lval *builtin_eval(lenv *e, lval *a);

lval *builtin_join(lenv *e, lval *a);

#endif
