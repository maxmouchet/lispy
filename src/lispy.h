#pragma once

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

/**
 * @brief Constructs an `lval` holding an integer.
 **/
lval *lval_num(long x);

/**
 * @brief Constructs an `lval` holding an error.
 **/
lval *lval_err(char *fmt, ...);

/**
 * @brief Constructs an `lval` holding a symbol.
 **/
lval *lval_sym(char *s);

/**
 * @brief Constructs an `lval` holding an S-expression.
 **/
lval *lval_sexpr(void);

/**
 * @brief Constructs an `lval` holding a Q-expression.
 **/
lval *lval_qexpr(void);

/**
 * @brief Constructs an `lval` holding a function.
 **/
lval *lval_fun(lbuiltin func);

/**
 * @brief Transform an AST to an `lval`.
 **/
lval *lval_read(mpc_ast_t *t);

/**
 * @brief Transform an AST to an `lval` holding an integer.
 **/
lval *lval_read_num(mpc_ast_t *t);

/**
 * @brief Add two expressions together.
 **/
lval *lval_add(lval *v, lval *x);

/**
 * @brief `lval` destructor.
 **/
void lval_del(lval *v);

// Evaluation

lval *lval_eval(lenv *e, lval *v);

lval *lval_eval_sexpr(lenv *e, lval *v);

// Utilities

lval *lval_pop(lval *v, int i);

lval *lval_take(lval *v, int i);

lval *lval_copy(lval *v);

char *ltype_name(int t);

// Print

void lval_print(lval *v);

void lval_println(lval *v);

void lval_expr_print(lval *v, char open, char close);

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