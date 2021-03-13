#ifndef printflib

#define printflib

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *, ...);
int place_s(va_list args, char *buff, int *b_cnt);
int place_c(va_list args, char *buff, int *b_cnt);
typedef struct placeholders
{
	char c;
	int (*place_function)(va_list, char *, int *);
} placeholders;



/* miscellaneous functions */

int _strlen(char *);
char *_strncpy(char *dest, char *src, int n);
int fillnewbuff(char *buff, char *src, int n, int buff_size, int *b_cnt);

#endif
