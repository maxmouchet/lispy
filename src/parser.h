#pragma once

#include "mpc.h"

void parser_init(void);

void parser_cleanup(void);

int parser_parse(const char *string, mpc_result_t *r);
