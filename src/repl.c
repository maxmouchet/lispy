#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

#include "colors.h"
#include "lispy.h"
#include "parser.h"

// TODO: JIT ?
// TODO: Compiler
// TODO: Own parser ?
// Jemalloc ?
// Use unions ?
// Do additional exercises

int main(int argc, char **argv) {
  parser_init();

  lenv *e = lenv_new();
  lenv_add_builtins(e);

  puts("Lispy Version 0.0.0.1");
  puts("Press Ctrl+C to Exit\n");

  while (1) {
    char *input = readline("\001\033" BOLDGREEN
                           "\002"
                           "lispy>"
                           "\001\033" RESET
                           "\002"
                           " ");

    add_history(input);

    mpc_result_t r;
    if (parser_parse(input, &r)) {
      lval *x = lval_eval(e, lval_read(r.output));
      lval_println(x);
      lval_del(x);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }

  parser_cleanup();

  return 0;
}