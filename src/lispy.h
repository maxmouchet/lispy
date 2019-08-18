#ifndef LISPY_LISPY
#define LISPY_LISPY

#include "mpc.h"

struct lval;
typedef struct lval lval;

struct lenv;
typedef struct lenv lenv;

typedef lval *(*lbuiltin)(lenv *, lval *);

#pragma region lval struct

enum lval_types {
  LVAL_ERR,
  LVAL_NUM,
  LVAL_SYM,
  LVAL_FUN,
  LVAL_SEXPR,
  LVAL_QEXPR
};

struct lval {
  int type;

  long num;
  char *err;
  char *sym;
  lbuiltin fun;

  int count;
  struct lval **cell;
};

#pragma endregion

#pragma region lenv struct

struct lenv {
  int count;
  char **syms;
  lval **vals;
};

#pragma endregion

#pragma region lval functions

// Constructors

lval *lval_num(long x);

lval *lval_err(char *fmt, ...);

lval *lval_sym(char *s);

lval *lval_sexpr(void);

lval *lval_qexpr(void);

lval *lval_fun(lbuiltin func);

lval *lval_read_num(mpc_ast_t *t);

lval *lval_read(mpc_ast_t *t);

lval *lval_add(lval *v, lval *x);

void lval_del(lval *v);

// Evaluation

lval *lval_eval_sexpr(lenv *e, lval *v);

lval *lval_eval(lenv *e, lval *v);

// Utilities

lval *lval_pop(lval *v, int i);

lval *lval_take(lval *v, int i);

lval *lval_copy(lval *v);

char *ltype_name(int t);

// Print

void lval_expr_print(lval *v, char open, char close);

void lval_print(lval *v);

void lval_println(lval *v);

#pragma endregion

#pragma region lenv functions

// Constructors

lenv *lenv_new(void);

void lenv_del(lenv *e);

// Utilities

lval *lenv_get(lenv *e, lval *k);

void lenv_put(lenv *e, lval *k, lval *v);

void lenv_add_builtin(lenv *e, char *name, lbuiltin func);

void lenv_add_builtins(lenv *e);

#pragma endregion

#endif