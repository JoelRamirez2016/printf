#ifndef printflib

#define printflib

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *, ...);

typedef struct placeholders
{
	char c;
	int (*f)(va_list, char *, int *);
} placeholders;



/* miscellaneous functions */

int _strlen(char *);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

#endif
