#ifndef LISPY_LVAL
#define LISPY_LVAL

#include "mpc.h"

// lval - Lisp Value
typedef struct lval
{
    int type;
    long num;
    char *err;
    char *sym;
    int count;
    struct lval **cell;
} lval;

enum lval_types
{
    LVAL_ERR,
    LVAL_NUM,
    LVAL_SYM,
    LVAL_SEXPR,
    LVAL_QEXPR
};

// Constructors

lval *lval_num(long x);

lval *lval_err(char *m);

lval *lval_sym(char *s);

lval *lval_sexpr(void);

lval *lval_qexpr(void);

lval *lval_read_num(mpc_ast_t *t);

lval *lval_read(mpc_ast_t *t);

lval *lval_add(lval *v, lval *x);

void lval_del(lval *v);

// Evaluation

lval *lval_eval_sexpr(lval *v);

lval *lval_eval(lval *v);

// Utilities

lval *lval_pop(lval *v, int i);

lval *lval_take(lval *v, int i);

// Print

void lval_expr_print(lval *v, char open, char close);

void lval_print(lval *v);

void lval_println(lval *v);

#endif