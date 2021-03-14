#ifndef HOLBERTON_PRINTF
#define HOLBERTON_PRINTF

#include <stdio.h>
#include <stdarg.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char op;
	int (*f)(char*, int, va_list);
} op_t;

int _printf(const char * const format, ...);
int makeBuffer(char*, const char * const, va_list, int);

#endif
