#include "parser.h"

mpc_parser_t *Number;
mpc_parser_t *Symbol;
mpc_parser_t *Sexpr;
mpc_parser_t *Qexpr;
mpc_parser_t *Expr;
mpc_parser_t *Lispy;

void parser_init(void) {
  // Grammar
  Number = mpc_new("number");
  Symbol = mpc_new("symbol");
  Sexpr = mpc_new("sexpr");
  Qexpr = mpc_new("qexpr");
  Expr = mpc_new("expr");
  Lispy = mpc_new("lispy");

  mpca_lang(MPCA_LANG_DEFAULT,
            " \
        number : /-?[0-9]+/ ;                             \
        symbol : /[a-zA-Z0-9_+\\-*\\/\\\\=<>!&]+/ ;       \
        qexpr  : '{' <expr>* '}' ; \
        sexpr  : '(' <expr>* ')' ; \
        expr   : <number> | <symbol> | <sexpr> | <qexpr> ; \
        lispy  : /^/ <expr>* /$/ ;            \
    ",
            Number, Symbol, Sexpr, Qexpr, Expr, Lispy);
}

void parser_cleanup(void) {
  mpc_cleanup(6, Number, Symbol, Sexpr, Qexpr, Expr, Lispy);
}

int parser_parse(const char *string, mpc_result_t *r) {
  return mpc_parse("<stdin>", string, Lispy, r);
}