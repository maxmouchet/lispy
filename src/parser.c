#include "parser.h"

mpc_parser_t *Number;
mpc_parser_t *Symbol;
mpc_parser_t *Sexpr;
mpc_parser_t *Expr;
mpc_parser_t *Lispy;

void parser_init(void)
{
    // Grammar
    Number = mpc_new("number");
    Symbol = mpc_new("symbol");
    Sexpr = mpc_new("sexpr");
    Expr = mpc_new("expr");
    Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT,
              " \
        number : /-?[0-9]+/ ;                             \
        symbol : '+' | '-' | '*' | '/' ;                 \
        sexpr  : '(' <expr>* ')' ; \
        expr   : <number> | <symbol> | <sexpr> ; \
        lispy  : /^/ <expr>* /$/ ;            \
    ",
              Number, Symbol, Sexpr, Expr, Lispy);
}

void parser_cleanup(void)
{
    mpc_cleanup(5, Number, Symbol, Sexpr, Expr, Lispy);
}

int parser_parse(const char *string, mpc_result_t *r)
{
    return mpc_parse("<stdin>", string, Lispy, r);
}