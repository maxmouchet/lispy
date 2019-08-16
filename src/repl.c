#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

#include "lval.h"
#include "parser.h"

// TODO: JIT ?
// TODO: Compiler
// TODO: Own parser ?
// Jemalloc ?
// Use unions ?
// Do additional exercises

// lval eval_op(lval x, char *op, lval y)
// {
//     if (x.type == LVAL_ERR)
//     {
//         return x;
//     }
//     if (y.type == LVAL_ERR)
//     {
//         return y;
//     }

//     if (strcmp(op, "+") == 0)
//     {
//         return lval_num(x.num + y.num);
//     }

//     if (strcmp(op, "-") == 0)
//     {
//         return lval_num(x.num - y.num);
//     }
//     if (strcmp(op, "*") == 0)
//     {
//         return lval_num(x.num * y.num);
//     }
//     if (strcmp(op, "/") == 0)
//     {
//         if (y.num == 0)
//         {
//             return lval_err(LERR_DIV_ZERO);
//         }
//         else
//         {
//             return lval_num(x.num / y.num);
//         }
//     }

//     return lval_err(LERR_BAD_OP);
// }

// lval eval(mpc_ast_t *t)
// {
//     // Either a number or an expr
//     if (strstr(t->tag, "number"))
//     {
//         errno = 0;
//         long x = strtol(t->contents, NULL, 10);
//         if (errno != ERANGE)
//         {
//             return lval_num(x);
//         }
//         else
//         {
//             return lval_err(LERR_BAD_NUM);
//         }
//     }

//     // If an expr. the operator is the second child
//     char *op = t->children[1]->contents;

//     // Third child is another expression
//     lval x = eval(t->children[2]);

//     // Combine with (possibly) other expressions
//     int i = 3;
//     while (strstr(t->children[i]->tag, "expr"))
//     {
//         x = eval_op(x, op, eval(t->children[i]));
//         i++;
//     }

//     return x;
// }

int main(int argc, char **argv)
{
    parser_init();

    puts("Lispy Version 0.0.0.1");
    puts("Press Ctrl+C to Exit\n");

    while (1)
    {
        char *input = readline("lispy> ");

        add_history(input);

        // printf("%s\n", input);
        // Parse user input
        mpc_result_t r;
        if (parser_parse(input, &r))
        {
            lval *x = lval_read(r.output);
            lval_println(x);
            lval_del(x);
            mpc_ast_delete(r.output);
        }
        else
        {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }

    parser_cleanup();

    return 0;
}